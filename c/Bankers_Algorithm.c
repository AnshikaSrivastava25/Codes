#include <stdio.h>
int main()
{
// P0, P1, P2, P3, P4 are the Process names here
int p, q, i, j, k;
p = 5; // Number of processes
q = 3; // Number of resources
int alloc[5][4] = { { 0, 0, 1, 2 }, // P0 // Allocation Matrix
{ 1, 0, 0,0}, // P1
{ 1, 3, 5, 4 }, // P2
{ 0, 6, 3, 2 }, // P3
{ 0, 0, 1, 4 } }; // P4
int max[5][4] = { { 0, 0, 1, 2 }, // P0 // MAX Matrix
{ 1, 7, 5, 0 }, // P1
{ 2, 3, 5, 6 }, // P2
{ 0, 6, 5, 2 }, // P3
{ 0, 6, 5, 6 } }; // P4
int avail[4] = { 1, 5, 2, 0 }; // Available Resources
int f[p], ans[p], ind = 0;
for (k = 0; k < p; k++) {
f[k] = 0;
}
int need[p][q];
for (i = 0; i < p; i++) {
for (j = 0; j < q; j++)
need[i][j] = max[i][j] - alloc[i][j];
}
int y = 0;
for (k = 0; k < 5; k++) {
for (i = 0; i < p; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < q; j++) {
if (need[i][j] > avail[j]){
flag = 1;
break;
}
}
if (flag == 0) {
ans[ind++] = i;
for (y = 0; y < q; y++)
avail[y] += alloc[i][y];
f[i] = 1;
}
}
}
}
printf("SAFE Sequence: \n");
for (i = 0; i < p - 1; i++)
printf(" P%d ->", ans[i]);
printf(" P%d", ans[p - 1]);
return (0);
}
