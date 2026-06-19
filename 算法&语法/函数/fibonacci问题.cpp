#include<iostream>
using namespace std;
long recursion(int n)
{
 if(n==1||n==2)
 {
  return 1;
 }
 else
 {
  return recursion(n-1)+recursion(n-2);
 }
}
int main()
{
 int n,i;
 cout<<"求fibonacci前多少项"<<endl;
 cin>>n;
 for(i=1;i<=n;i++)
  cout<<recursion(i)<<' ';
 return 0;
}
