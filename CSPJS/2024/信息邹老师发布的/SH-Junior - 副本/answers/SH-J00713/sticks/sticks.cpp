#include<bits/stdc++.h>
using namespace std;
int num[11]={6,2,5,5,4,5,6,3,7,6};
int n,tmp;
bool b=0;
void di(int cnt,int val,long long sum)
{
	if(b) return;
	if(cnt==0)
	{
		if(val==n)
		{
			b=1;
			cout<<sum<<'\n';
		}
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(!i&&cnt==tmp) continue;
		di(cnt-1,val+num[i],sum*10+i);
		if(b) break;
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,cnt;
	long long z=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2)
		{
			cout<<"-1\n";
			continue;
		}
		cnt=ceil(n*1.0/7);
		if(n%7==0)
		{
			while(cnt--) cout<<8;
			cout<<'\n';
			continue;
		}
		else if((n-1)%7==0&&n>30)
		{
			cout<<10;
			cnt-=2;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;
		}
		else if((n-2)%7==0&&n>30)
		{
			cout<<1;
			cnt-=1;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;
		}
		else if((n-3)%7==0&&n>30)
		{
			cout<<200;
			cnt-=3;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;
		}
		else if((n-4)%7==0&&n>30)
		{
			cout<<20;
			cnt-=2;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;
		}
		else if((n-5)%7==0&&n>30)
		{
			cout<<2;
			cnt-=1;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;
		}
		else if((n-6)%7==0&&n>30)
		{
			cout<<6;
			cnt-=1;
			while(cnt>0)
			{
				cout<<8;
				cnt--;
			}
			cout<<'\n';
			continue;			
		}
		b=0;
		tmp=cnt;
		di(cnt,0,z);
	} 
	return 0;
}
