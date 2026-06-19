#include <iostream>
using namespace std;

int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int f[15]={0,0,0,0,0,0,0,0,0,0,0,0,0};
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		int p[15]={0,0,1,7,4,2,0,8,2,1,7,4,2,0,8};//ÊÖËã 
		int r;
		if(n<=7)
		{
			if(n==6)
			{
				cout<<6<<endl;
				continue;
			}
			cout<<p[n]<<endl;
			continue;
		}
		r=n%7+7;
		int s;
		s=n/7-1;
		f[8]+=s;
		
		if(r>7)
		{
			f[p[r]]++;
			f[0]++;
		}
		else
		{
			f[p[r]]++;
		}
		
		if(f[0]==n)
		{
			f[0]--;
			f[6]++;
		}
		//
		while(f[0]!=n&&f[7]>0&&f[0]>0&&f[1]==0&&f[2]==0&&f[3]==0&&f[4]==0&&f[5]==0&&f[6]==0)
		{
			f[3]++;
			f[4]++;
			f[7]--;
			f[0]--;
		}
		
		while(f[0]!=n&&f[4]>0&&f[0]>0&&f[1]==0&&f[2]==0&&f[3]==0)
		{
			f[3]++;
			f[2]++;
			f[4]--;
			f[0]--;
		}
		
		//
		bool con=false;
		for(int i=1;i<=9;i++)
		{
			
			for(int j=1;j<=f[i];j++)
			{
				cout<<i;
				f[i]--;
				con=true;
				break;
			}
			if(con)break;
		}
		for(int i=1;i<=f[0];i++)
		{
			cout<<0;
		}
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=f[i];j++)
			{
				cout<<i;
				
			}
		}
		cout<<endl;
		
	}
	return 0;
}
