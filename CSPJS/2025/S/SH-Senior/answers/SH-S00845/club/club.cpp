#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+8; 
ll T,n,temp,tt[10],ans,temp2;

struct Stu
{
	ll sa[3],cha; //cha:最大-次大 
	bool operator <(const Stu &rhs) const
	{
		return cha>rhs.cha;
	}
}stu[N]; 

ll cal(int a,int b,int c)
{
	ll maxn=(c>(a>b? a:b)? c:(a>b? a:b));
	ll minn=(c<(a<b? a:b)? c:(a<b? a:b));
	ll mmnn=a+b+c-maxn-minn;
	return maxn-mmnn;
}

ll calin(int a,int b,int c)
{
	return (c>(a>b? a:b)? 2:(a>b? 0:1));
}

ll midin(int a,int b,int c)
{
	return 3-(c>(a>b? a:b)? 2:(a>b? 0:1))-(c<(a<b? a:b)? 2:(a<b? 0:1));
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(tt,0,sizeof tt);ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i].sa[0]>>stu[i].sa[1]>>stu[i].sa[2];
			stu[i].cha=cal(stu[i].sa[0],stu[i].sa[1],stu[i].sa[2]);
			//cout<<stu[i].cha<<endl;
		}
		
		sort(stu+1,stu+n+1);
		
		for(int i=1;i<=n;i++)
		{
			temp=calin(stu[i].sa[0],stu[i].sa[1],stu[i].sa[2]);
			if(tt[temp]<n/2)
			{
				ans+=stu[i].sa[temp];
				tt[temp]++;
			}
			else
			{
				temp=midin(stu[i].sa[0],stu[i].sa[1],stu[i].sa[2]);
				ans+=stu[i].sa[temp];
				tt[temp]++;
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
