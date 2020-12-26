
## 2-D (A[m][n]) Array Row Major Mapping -- Addr(A[i] [j]) = Lo + ( i * n + j ) * w  
- Lo = Base Address
- n = # elements in a column
- w = size of data type

## n-D Array (A[d1][d2][d3][d4]) Row Major Mapping       ~(Left to Right)

### - Addr([i1] [i2] [i3] [i4]) = Lo + [i1* d2* d3* d4 +  i2* d3* d4 +  i3* d4 + i4] * w           
