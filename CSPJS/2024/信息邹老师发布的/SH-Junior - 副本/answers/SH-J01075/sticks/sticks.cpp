#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	long long n;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n=1||3)
		{
			cout<<'-1'<<endl;
			continue;
		}
		else if(n==2)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n==4)
		{
			cout<<4<<endl;
		}
		else if(n==5) cout<<"2"<<endl;
		else if(n==6) cout<<"6"<<endl;
		else if(n==7) cout<<"8"<<endl;
		else if(n==8) cout<<"10"<<endl;
		else if(n==9) cout<<"24<<endl;
		else if(n==10) cout<<"22"<<endl;
		else if(n==12) cout<<"28"<<endl;
		else if(n==13) cout<<"80"<<endl;
		else if(n==14) cout<<"221"<<endl;
		else if(n==15) cout<<"204"<<endl;
		else if(n==16) cout<<"202"<<endl;
		else if(n==17) cout<<"200"<<endl;
		else if(n==18) cout<<"208"<<endl;
		for(int j=1;j<=n/7;j++)
		{
			cout<<"8";
		}
		cout<<endl;
	}
}


