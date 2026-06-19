#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=508,MOD=998244353; 
ll n,m,pa[N],ans=0,inq[N],flag=1,flag2=1;
string ques;

void dfs(int day,int pas,int combo) //T1,2
{
	if(day==n)
	{
		if(pas>=m) ans++;
		ans%=MOD;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(inq[i]==0)
		{
			inq[i]=1;
			if(combo>=pa[i]||ques[day]=='0') dfs(day+1,pas,combo+1);
			else dfs(day+1,pas+1,combo);
			inq[i]=0;
		}
	}
}

void dfs1() //T12-14
{
	int cnt1=0;
	for(int i=0;i<ques.size();i++)
	{
		cnt1+=(ques[i]=='1');
		if(ques[i]=='0') break;
	}
	
	if(cnt1<m) ans=0;
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%MOD;
		}
	}
}

void dfs2() //T15 
{
	int cnt0=0;
	for(int i=0;i<ques.size();i++)
	{
		cnt0+=(ques[i]=='0');
	}
	if(cnt0>m) ans=0;
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%MOD;
		}
	}
	
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>ques;
	for(int i=0;i<n;i++) {cin>>pa[i];flag&=(pa[i]==n);flag2&=(pa[i]==1);}
	
	if(n<=10) dfs(0,0,0);
	else if (flag) dfs2();
	else if (flag2) dfs1();
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
