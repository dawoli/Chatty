#include<iostream>
using namespace std; 
int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n-i;j++)
  cout<<" ";
for(int k=1;k<=2*i-1;k++)
  cout<<"*";
cout<<endl;
}
for(int p=n-1;p>=1;p--)
{
for(int l=1;l<=n-p;l++)
  cout<<" ";
for(int g=1;g<=2*p-1;g++)
  cout<<"*";
cout<<endl;
}
return 0;
}
