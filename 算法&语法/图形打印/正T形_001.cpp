#include<iostream>
#include<cmath>
using namespace std;
int main()
{ 
    int n,l;
    cin>>n;
	  for(int i=1;i<=2*n-1;i++)
    {
      cout<<"*";
      l=i;
    }
    cout<<endl;
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=l/2;k++)
        cout<<" ";
      cout<<"*";
      cout<<endl;
    }
    return 0;
}
