#include <bits/stdc++.h>
using namespace std;
int li[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,a,a1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<=1)
		{
			cout<<-1<<endl;
			continue;
		}
		int num=0;
		a1=0;
		while(num!=n){
			num=0;
			a1++;
			a=a1;
			while(a!=0)
		    {
			    num=num+li[a%10];
			    a=a-a%10;
			    a=a/10;
		    }
	    }
	    cout<<a1<<endl;
	}
	return 0;
}
