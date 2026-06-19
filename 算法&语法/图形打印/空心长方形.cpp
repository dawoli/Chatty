#include<iostream>
using namespace std; 
int main()
{
int n,m;
cin>>n>>m;
for(int i=1;i<=m;i++)
{
for(int j=1;j<=n;j++)
{
if(i==1||j==1||j==n||i==m)cout<<"*";
else cout<<" ";
}
cout<<endl;
}
return 0;
}
