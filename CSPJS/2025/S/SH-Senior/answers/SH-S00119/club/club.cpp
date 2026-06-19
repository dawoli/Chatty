#include<bits/stdc++.h>
using namespace std;
struct k1
{
	long long j1;
	long long j2;
	long long j3;
	bool operator<(const k1&ki)
	const
	{
		return j1-max(j2,j3)>ki.j1-max(ki.j2,ki.j3);
	};
};
struct k2
{
	long long j1;
	long long j2;
	long long j3;
	bool operator<(const k2&ki)
	const
	{
		return j2-max(j1,j3)>ki.j2-max(ki.j1,ki.j3);
	};
};
struct k3
{
	long long j1;
	long long j2;
	long long j3;
	bool operator<(const k3&ki)
	const
	{
		return j3-max(j2,j1)>ki.j3-max(ki.j1,ki.j2);
	};
};
long long t,n,a1,a2,a3,u4,u5,u6,ans;
k1 u1;
k2 u2;
k3 u3;
vector<k1> l1;
vector<k2> l2;
vector<k3> l3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{	
		ans=0;
		cin>>n;
		l1.clear();
		l2.clear();
		l3.clear();
		for(long long j=1;j<=n;j++)
		{
			cin>>a1>>a2>>a3;
			u1.j1=a1;
			u2.j1=a1;
			u3.j1=a1;
			u1.j2=a2;
			u2.j2=a2;
			u3.j2=a2;
			u1.j3=a3;
			u2.j3=a3;
			u3.j3=a3;
			u4=a1*2-a2-a3;
			u5=a2*2-a1-a3;
			u6=a3*2-a1-a2;
			if(u4>=u5&&u4>=u6)
			{
				l1.push_back(u1);
			}
			else if(u5>=u4&&u5>=u6)
			{
				l2.push_back(u2);
			}
			else
			{
				l3.push_back(u3);
			}
		}
		if(l1.size()>n/2)
		{ 
			sort(l1.begin(),l1.begin()+l1.size());
			while(l1.size()>n/2)
			{
				long long j=l1.size()-1;
				if(l1[j].j2-max(l1[j].j1,l1[j].j3)>l1[j].j3-max(l1[j].j1,l1[j].j2))
				{
					u2.j1=l1[j].j1;
					u2.j2=l1[j].j2;
					u2.j3=l1[j].j3;
					l2.push_back(u2);
				}
				else
				{
					u3.j1=l1[j].j1;
					u3.j2=l1[j].j2;
					u3.j3=l1[j].j3;
					l3.push_back(u3);
				}
				l1.pop_back();
			}
		}
		if(l2.size()>n/2)
		{ 
			sort(l2.begin(),l2.begin()+l2.size());
			while(l2.size()>n/2)
			{
				long long j=l2.size()-1;
				if(l2[j].j1-max(l2[j].j2,l2[j].j3)>l2[j].j3-max(l2[j].j1,l2[j].j2))
				{
					u1.j1=l2[j].j1;
					u1.j2=l2[j].j2;
					u1.j3=l2[j].j3;
					l1.push_back(u1);
				}
				else
				{
					u3.j1=l2[j].j1;
					u3.j2=l2[j].j2;
					u3.j3=l2[j].j3;
					l3.push_back(u3);
				}
				l2.pop_back();
			}
		}
		if(l3.size()>n/2)
		{ 
			sort(l3.begin(),l3.begin()+l3.size());
			while(l3.size()>n/2)
			{
				long long j=l3.size()-1;
				if(l3[j].j2-max(l3[j].j1,l3[j].j3)>l3[j].j1-max(l3[j].j2,l3[j].j3))
				{
					u2.j1=l3[j].j1;
					u2.j2=l3[j].j2;
					u2.j3=l3[j].j3;
					l2.push_back(u2);
				}
				else
				{
					u1.j1=l3[j].j1;
					u1.j2=l3[j].j2;
					u1.j3=l3[j].j3;
					l1.push_back(u1);
				}
				l3.pop_back();
			}
		}
		for(long long j=0;j<l1.size();j++)
		{
			ans+=l1[j].j1;
		}
		for(long long j=0;j<l2.size();j++)
		{
			ans+=l2[j].j2;
		}
		for(long long j=0;j<l3.size();j++)
		{
			ans+=l3[j].j3;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
