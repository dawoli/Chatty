#include<iostream>
using namespace std;
int main()
{ 
    int n;
    cin>>n;
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=(2*n-1)/2;k++)
        cout<<" ";
      cout<<"*";
      cout<<endl;
    }
    for(int i=1;i<=2*n-1;i++)
    {
      cout<<"*";
    }
    return 0;
}
