#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int arr[555],ss[555],tr[555];
bool vis[555];
string s;
unsigned long long cnt=0;
bool check()
{
	int wei=0,lu=0;
	for(int i=1;i<=n;i++)
	{
		if(wei>=arr[tr[i]])
		{
			wei++;
		}
		else if(ss[i]==0)
		{
			wei++;
		}
		else
		{
			lu++;
		}
	}
	if(lu>=m)
	{
		return true;
	}
	return false;
}
void dfs(int num,int rec)
{
	if(num==n)
	{
		if(check())
		{
			cnt++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			tr[rec]=i;
			vis[i]=false;
			dfs(num+1,rec+1);
			vis[i]=true;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		ss[i+1]=int(s[i])-48;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	memset(vis,true,sizeof vis);
	dfs(0,1);
	cout<<cnt%998244353;
	return 0;
}
