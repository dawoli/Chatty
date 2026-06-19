#include<bits/stdc++.h>
using namespace std;

struct aaa
{
	int mem;
	int val;
	int jule;
	bool operator<(aaa& b)
	{
		return val<b.val;
	}
	bool operator>(aaa& b)
	{
		return val>b.val;
	}
	bool operator>=(aaa& b)
	{
		return val>=b.val;
	}
} a[4][100001];

int n,top[4],num[4],u;
bool used[100001];

bool cmp(aaa& a,aaa& b)
{
	return a>b;
}

int main()
{
	ifstream in("club.in");
	ofstream out("club.out");
	int t;
	in>>t;
	while((t=t-1)>=0)
	{
		in>>n;
		top[1]=top[2]=top[3]=1;
		num[1]=num[2]=num[3]=0;
		u=0;
		for(int i=1;i<=n;i++)
		{
			used[i]=false;
			for(int j=1;j<=3;j++)
			{
				in>>a[j][i].val;
				a[j][i].mem=i;
				a[j][i].jule=j;
			}
		}
		sort(a[1]+1,a[1]+n+1,cmp);
		sort(a[2]+1,a[2]+n+1,cmp);
		sort(a[3]+1,a[3]+n+1,cmp);
		while((num[1]+num[2]+num[3])<n)
		{
			aaa max_={0,0,0};
			for(int i=1;i<=3;i++)
			{
				while(used[a[i][top[i]].mem]&&top[i]<=n)
				{
					top[i]++;
				}
				if(num[i]<n/2&&top[i]<=n)
				{
					aaa o=a[i][top[i]];
					if(o>=max_) max_=o;
				}
			}
			used[max_.mem]=true;
			num[max_.jule]++;
			u+=max_.val;
		}
		out<<u<<endl;
	}
	return 0;
}
