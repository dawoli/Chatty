#include<iostream>
using namespace std;
int work(int i)
{
int l;
l=i*i;
if(l%10==i)return 1;
else if(l%100==i)return 1;
else if(l%1000==i)return 1;
else if(l%10000==i)return 1;
else return 0;
}
int main()
{
int n,m,a;
cin>>n>>m;
for(int i=n;i<=m;i++)
{
bool f;
f=work(i);
if(f==1)a++;
}
cout<<a;
return 0;
}
