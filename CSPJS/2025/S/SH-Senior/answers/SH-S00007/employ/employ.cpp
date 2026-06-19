#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,m;
bool hard[520];
int pat[520];
int hp[520],fir[520],eas=0,sb=0;
bool spe1=true;
//long long jiech(int a)
//{
//	long long ans=1;
//	for(int i=1;i<=a;i++)
//	{
//		ans*=i;
//		ans%=M;
//	}
//	return ans;
//}
//long long dfs(int qu,int hir)
//{
//	if(qu==0&&hir>=m)
//		return jiech(n-hir);
//	long long temp=dfs(qu-1,hir);
//	for(int i=1;i<=j)
//}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char aaa;
		cin>>aaa;
		if(aaa=='0')
		{
			hard[i]=true;
			spe1=false;
		}
		else
		{
			sb++;
			fir[++eas]=i-1;
		}
	}
	if(m==n)
	{
		if(spe1&&sb==0)
		{
			long long ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=M;
			}
			cout<<ans;
		}
		else
			cout<<0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>pat[i];
			for(int j=1;j<=eas;j++)
			{
				if(pat[i]<fir[j])
				{
					hp[j]++;
					j=eas+1;
				}
			}
		}
		if(m==1)
		{
			long long mi=1;
			long long ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=M;
			}
			int locc=1;
			for(int i=1;i<=n;i++)
			{
				int tm=hp[locc];
				while(i<=tm)
				{
					mi*=hp[locc]--;
					mi%=M;
					i++;
//					cout<<"q";
				}
				hp[locc+1]+=hp[locc];
				locc++;
				if(mi==0)
					break;
			}
			for(int i=1;i<=eas;i++)
			{
				mi*=i;
				mi%=M;
			}
//			for(int i=1;i<=eas;i++)
//			{
//				if(hp[i])
//				cout<<hp[i]<<" "<<i<<endl;
//			}
			ans-=mi;
			if(ans<0)
				ans+=M;
			cout<<ans-mi;
		}
		else if(eas==0)
		{
			sort(fir,fir+eas+1);
			if(1)
			{
				long long ans=1;
				for(int i=1;i<=n;i++)
				{
					ans*=i;
					ans%=M;
				}
				cout<<ans;
			}
			else
				cout<<0;
		}
	}
//	sort(fir,fir+eas+1);
}
