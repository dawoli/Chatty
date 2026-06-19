#include<iostream>
using namespace std;
int main ()
{
   int n;
   cin>>n;
   int a[n];
   for(int j=0;j<n;j++)cin>>a[j]; 
   int max=-1; 
   for(int i=0;i<n;i++)if(a[i]>max)max=a[i]; 
   cout<<max;
   return 0;
} 
