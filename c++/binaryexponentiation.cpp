#include<bits/stdc++.h>

using namespace std;
int rev(int a, int n)
{
int res=1;
while(n)
{
    if(n%2)
    res*=a, n--;
    else
    a*=a , n%2;
}
 return res;
}