#include<iostream>
using namespace std;
int main()
{
  int m,n;
  cin>>m>>n;
  int a[m][n];
  for(int l=1;l<=m;l++)
  {
    for(int h=1;h<=n;h++)
        cin>>a[l][h];
  }
  if(n%2==0)
  {
  for(int k=1;k<=n;k++)
  {
    for(int i=0,j=n;i<=n,j<=0;i++,j--)
        swap(a[k][i],a[k][j]);       
  }
  }
    for(int l=1;l<=m;l++)
  {
    for(int h=1;h<=n;h++)
        cout<<a[l][h]<<' ';
    cout<<endl;
  }
}
