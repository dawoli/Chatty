#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
int sum=0;
for(int i=1;i<=n;i++)
{
    sum^=a[i];
    if(sum==k){
        cnt++;
        sum=0;
    }
}
cout<<cnt;
return 0;
}
