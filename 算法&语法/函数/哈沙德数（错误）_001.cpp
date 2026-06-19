#include<iostream>
using namespace std;
int work1(int a)
{
  int ans=0;
  ans+=a%10;
  ans+=a%100;
  ans+=a%1000;
  ans+=a%10000;
  return ans;
}
bool work2(int a)
{
  int b=work1(a);
  if(a%b==0)return 1;
  else return 0;
}
int main()
{
  int m,n;
  cin>>m>>n;
  for(int i=m;i<=n;i++)
  {
    bool flag;
    flag=work2(i);
    if(flag==1)cout<<i<<' ';
  }
  return 0;
}
