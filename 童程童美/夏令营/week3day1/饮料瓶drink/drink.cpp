#include<iostream>
using namespace std;
int main()
{
	freopen("drink.in","r",stdin);
	freopen("drink.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool flag;
    for (int i=n;i>=1;i--)
    {
    	for(int j=0;j<i;j++)
    	{
    		flag=false;
    		if(a[j]>a[j+1]){swap(a[j],a[j+1]);flag=true;cnt++;}
	    }
		if(flag==false)break;
	}
	cout<<cnt;
	return 0;	
}
