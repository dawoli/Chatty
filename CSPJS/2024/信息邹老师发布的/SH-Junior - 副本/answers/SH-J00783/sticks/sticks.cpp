#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,n;

int ans[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
string round[8]={"88","108","188","200","208","288","688"};

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=1) cout<<-1<<endl;
		else if(n<=13) cout<<ans[n]<<endl;
		else
		{
			cout<<round[n%7];
			n=n/7-2;
			while(n--) cout<<8;
			cout<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
