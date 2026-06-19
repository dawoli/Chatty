#include<bits/stdc++.h>
#define Code using
#define By namespace
#define CChara std
Code By CChara;
#define int long long
int n,m;
string str;
int ans;
int arr[114514];
int step[114514];
bool vis[114514];
#define MOD 998244353
void judge()
{
	int Cnt=0;//计数器
	int tmp=0;
	for(int i=0;i<n;i++)
	{
		if(Cnt>=arr[step[i]])
		{
			Cnt++;
		}
		else
		{
			if(str[i]=='1')
			{
				tmp++;
			}
			else
			{
				Cnt++;
			}
		}
	}
	if(tmp>=m)
	{
		ans++;
	}
}
void dfs(int num)//全排列并进行枚举判断 
{
	if(num==n)
	{
		judge();
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
				step[num]=i;
				vis[i]=true;
				dfs(num+1);
				vis[i]=false;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//Please Check Before Handing In!!
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(n<=18)
	{
		dfs(0);
	}
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=MOD;
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}

