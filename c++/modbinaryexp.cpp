#include<bits/stdc++.h>

using namespace std;
int rev(int a, int n, int p)
{
int res=1;
while(n)
{
    if(n%2)
    res=(res*a)%p, n--;
    else
    a=(a*a)%p , n/2;
}
 return res;
}