#include<iostream>
int MAXN=100001;
using namespace std;
int main() 
{
	int n,i,j,a[MAXN];
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	bool flag;
    for (i=n-1;i>=1;i--)
    {
    	for(j=0;j<i;j++)
    	{
    		flag=false;
    		if(a[j]>a[j+1]){swap(a[j],a[j+1]);flag=true;}
	    }
		if(flag==false)break;
	}
    for (i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
