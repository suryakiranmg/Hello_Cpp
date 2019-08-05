#include "state_machine.h"

#include "../Flash28335_API_V210/include/DSP28_DataTypes.h"
#include "../DSP2833x_headers/include/DSP2833x_Device.h"
#include "../hw_io/hw_io.h"
#include "../isr/isr.h"
#include "../serial_comm/serial_comm.h"

#include "../comm_mgr/comm_mgr.h"
#include "../axis_controller/axis_controller.h"

#include "../system_params/system_params.h"

#include "../loop_controller/configure_controller.h"
#include "../loop_controller/set_parameter.h"
#include "../loop_controller/reset_controller.h"
#include "../loop_controller/run_controller.h"

#include "../test_diag/test_diag.h"
#include "../tc_interface/tc_interface.h"
#include "../interaxis_interface/interaxis_interface.h"



/* ###################################################### */
STATE_TYPE CurrentAxisState,NextAxisState;
EVENT_TYPE ExternalEvent,InternalEvent,FinalEvent;
static Uint16 M1FltStt,M2FltStt;

BOOLEAN	ScanOn;

Uint16 tStr[16];

Uint16 AxisStateTable[NOOF_STATES][NOOF_EVENTS] = {0, 1, 0, 0, 0, 5, 0,
												   0, 1, 2, 3, 4, 5, 1,
												   0, 1, 2, 2, 2, 5, 2,
												   0, 1, 3, 3, 3, 5, 3,
												   0, 1, 4, 4, 4, 5, 4,
												   5, 5, 5, 5, 5, 5, 0
												  };

FunPtr DoAction[NOOF_STATES] =	{ Do_Off,
				  Do_StandBy,
				  Do_Scan,
				  Do_Track,
				  Do_TestDiag,
				  Do_Fault
				};

FunPtr EntryAction[NOOF_STATES] = { Enter_Off,
				  Enter_StandBy,
				  Enter_Scan,
				  Enter_Track,
				  Enter_TestDiag,
				  Enter_Fault
				};

FunPtr ExitAction[NOOF_STATES] =  { Exit_Off,
				  Exit_StandBy,
				  Exit_Scan,
				  Exit_Track,
				  Exit_TestDiag,
				  Exit_Fault
				};

/* ###################################################### */
#pragma CODE_SECTION(Process,"ramfuncs1");
void Process(FunPtr fptr)
{
 (*fptr)();

}


/* ###################################################### */
void Init_StateMachine(void)
{
 CurrentAxisState = FAULT;
 NextAxisState = FAULT;

 /* Switch On Fault LED */
 TurnOn_LED3();
 
 /* Disable Axes Motors */
 Disable_M1();
 Disable_M2();

 /* Apply Motor Brakes */
 ApplyMotorBrakes();

 /* Update Drive Status */
 AxisVars.Motor[0].Fault = 1;
 AxisVars.Motor[1].Fault = 1;
 M1FltStt = 0;
 M2FltStt = 0;

 ExternalEvent = E_NULL;
 InternalEvent = E_NULL;

 AxisVars.Motor[0].Dem_Current.Val = 0;
 AxisVars.Motor[1].Dem_Current.Val = 0;

}


/* ###################################################### */
#pragma CODE_SECTION(Do_Off,"ramfuncs1");
void Do_Off(void)
{
 /* Do Nothing */

}

#pragma CODE_SECTION(Do_StandBy,"ramfuncs1");
void Do_StandBy(void)
{
 /* Do Nothing */

}

#pragma CODE_SECTION(Do_Scan,"ramfuncs1");
void Do_Scan(void)
{
 if(Axis == AZ)
  {
   if(ScanOn == TRUE)
	{
	 GenerateScanDem();
	}
   else
	{
	 AZ2EL_Pkt.Demand.Val = EL2AZ_Pkt.Position.Val;
	}
  }
 else
  {
   AxisVars.Position_Demand.Val = AZ2EL_Pkt.Demand.Val;
  }

 /* Update Controller Input variables */
 ContIPVars.dem_ip = AxisVars.Position_Demand.Val;

 /* Run PLC & SLC controller */
 Run_Controller();

}

#pragma CODE_SECTION(Do_Track,"ramfuncs1");
void Do_Track(void)
{
 if(Axis == AZ)
  {
   if(ScanOn == TRUE)
	{
	 GenerateTrackDem();
	}
   else
	{
	 AxisVars.Position_Error.Val = 0;
	 AZ2EL_Pkt.Demand.Val = 0;
	}
  }
 else
  {
   AxisVars.Position_Error.Val = AZ2EL_Pkt.Demand.Val;
  }

 /* Update Controller Input variables */
 ContIPVars.dem_ip = AxisVars.Position_Error.Val;

 /* Run PLC, Stab & SLC controller */
 Run_Controller();

}

#pragma CODE_SECTION(Do_TestDiag,"ramfuncs1");
void Do_TestDiag(void)
{
 if(ServoCalTestOn == TRUE)
  {
   DoServoCalTest();
   Run_Controller();
  }

}

#pragma CODE_SECTION(Do_Fault,"ramfuncs1");
void Do_Fault(void)
{
 /* Do Nothing */

}


/* ###################################################### */
#pragma CODE_SECTION(Enter_Off,"ramfuncs1");
void Enter_Off(void)
{
 ClearAxisVars();

 /* Disable Axes Motors */
 Disable_M1();
 Disable_M2();

 /* Apply Motor Brakes */
 ApplyMotorBrakes();

}

#pragma CODE_SECTION(Enter_StandBy,"ramfuncs1");
void Enter_StandBy(void)
{
 ClearAxisVars();

 /* Enable Axes Motors */
 Enable_M1();
 Enable_M2();

 /* Release Motor Brakes */
 ReleaseMotorBrakes();

}

#pragma CODE_SECTION(Enter_Scan,"ramfuncs1");
void Enter_Scan(void)
{
 ClearAxisVars();

 /* Set current Position as Position Demand */
 AxisVars.Position_Demand.Val = AxisVars.Position.Val;

 /* Reset the Axes controller */
 Reset_Controller();

 ScanOn = FALSE;

}

#pragma CODE_SECTION(Enter_Track,"ramfuncs1");
void Enter_Track(void)
{
 ClearAxisVars();

 ServoModeCalSwitches.pos_error_selector = EXTERNAL;
 Config_Controller();

 /* Set Position Error demand as Zero */
 AxisVars.Position_Error.Val = 0;

 /* Reset the Axes controller */
 Reset_Controller();

 ScanOn = FALSE;

}

#pragma CODE_SECTION(Enter_TestDiag,"ramfuncs1");
void Enter_TestDiag(void)
{
 /* Reset the Axes controller */
 Reset_Controller();

 ServoCalTestOn = FALSE;

 ClearAxisVars();

}

#pragma CODE_SECTION(Enter_Fault,"ramfuncs1");
void Enter_Fault(void)
{
 /* Switch On Fault LED */
 TurnOn_LED3();

 /* Disable Axes Motors */
 Disable_M1();
 Disable_M2();

 /* Apply Motor Brakes */
 ApplyMotorBrakes();

 ClearAxisVars();

 // In case AZ goes to FAULT State then command EL to go to OFF State
 if(Axis == AZ)
  {
   AZ2EL_Pkt.ModeCmd = E_OFF;
  }

}


/* ###################################################### */
#pragma CODE_SECTION(Exit_Off,"ramfuncs1");
void Exit_Off(void)
{

}

#pragma CODE_SECTION(Exit_StandBy,"ramfuncs1");
void Exit_StandBy(void)
{

}

#pragma CODE_SECTION(Exit_Scan,"ramfuncs1");
void Exit_Scan(void)
{
 ScanOn = FALSE;

}

#pragma CODE_SECTION(Exit_Track,"ramfuncs1");
void Exit_Track(void)
{
 /* Reconfigure the controllers for Entry Point = Pos */
 Init_ServoModenCalSwitches();
 Config_Controller();

 Reset_Controller();

 ScanOn = FALSE;

}

#pragma CODE_SECTION(Exit_TestDiag,"ramfuncs1");
void Exit_TestDiag(void)
{
 /* Reconfigure the controllers for Entry Point = Pos */
 Init_ServoModenCalSwitches();
 Config_Controller();

 Reset_Controller();

 ServoCalTestOn = FALSE;
 Send_ServoCalPLCData = FALSE;
 Send_ServoCalSTLCData = FALSE;
 Send_ServoCalSLCData = FALSE;
 Send_ServoCalCLCData = FALSE;

}

#pragma CODE_SECTION(Exit_Fault,"ramfuncs1");
void Exit_Fault(void)
{
 /* Switch Off Fault LED */
 TurnOff_LED3();

}


/* ###################################################### */
#pragma CODE_SECTION(CheckInternalEvents,"ramfuncs1");
void CheckInternalEvents(void)
{
 InternalEvent = E_NULL;

 if((M1FltStt == 1) || (M2FltStt == 1))
  {
   InternalEvent = E_FAULT;
  }

}


#pragma CODE_SECTION(CheckExternalEvents,"ramfuncs1");
void CheckExternalEvents(void)
{
 if(Axis == AZ)
  {
   /* Check for any command from TC */
   ExternalEvent = TC_ModeCmd;
  }
 else
  {
   if(AZ2EL_Pkt.ModeCmd != E_NULL)
    {
     ExternalEvent = AZ2EL_Pkt.ModeCmd;
    }
   else
    {
     ExternalEvent = TC_ModeCmd;
    }
  }

 // Clear TC mode command (if any)
 TC_ModeCmd = E_NULL;

}


#pragma CODE_SECTION(PrioritiseEvents,"ramfuncs1");
void PrioritiseEvents(void)
{
 if(CurrentAxisState == FAULT)
  {
   FinalEvent = InternalEvent;
  }
 else
  {
   if(InternalEvent == E_NULL)
	{
	 FinalEvent = ExternalEvent;
	}
   else
	{
	 FinalEvent = InternalEvent;
	}
  }

}

/* ###################################################### */
#pragma CODE_SECTION(DoStateProcess,"ramfuncs1");
void DoStateProcess(void)
{
 Process(DoAction[CurrentAxisState]);

}

/* ###################################################### */
#pragma CODE_SECTION(Run_StateMachine,"ramfuncs1");
void Run_StateMachine(void)
{
 /* Check for internal events */
 CheckInternalEvents();

 /* Check for external events */
 CheckExternalEvents();

 PrioritiseEvents();

 NextAxisState = (STATE_TYPE) AxisStateTable[CurrentAxisState][FinalEvent];

 if(CurrentAxisState != NextAxisState)
  {
   /* ExitAction(CurrentAntState) */
   Process(ExitAction[CurrentAxisState]);
   /* EntryAction(NextAntState) */
   Process(EntryAction[NextAxisState]);

   CurrentAxisState = NextAxisState;
  }

}
