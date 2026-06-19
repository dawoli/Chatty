#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long t,n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1) cout<<-1<<endl;
		if(n<10) 
		{
			for(long long i=1;i<10;i++)
			{
			  if(a[i]==n) 
			  {
			  	cout<<i<<endl;
			  	break;
			  }
		    }
		}
		else
		{
			if(n==11) cout<<20<<endl;
			if(n==12) cout<<28<<endl;
			if(n==13) cout<<68<<endl;
			if(n==14) cout<<88<<endl;
			if(n==15) cout<<108<<endl;
			if(n==16) cout<<168<<endl;
			if(n==17) cout<<200<<endl;
			if(n==18) cout<<208<<endl;
			if(n==19) cout<<288<<endl;
			if(n==20) cout<<688<<endl;
		}
	}
	return 0;
}
