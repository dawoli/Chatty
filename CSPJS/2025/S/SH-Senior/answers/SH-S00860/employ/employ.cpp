#include<bits/stdc++.h>
using namespace std;

int n,m,cnt=0;
long long ans;
string temp_s;
bool s[500];
int c[500];
bool used[500];

long long P(int num,int k)
{
	if(k==1) return num;
	else return (P(num-1,k-1)*num)%998244353;
}

long long dfs(int pos,int offer)
{
	if(pos==n)
	{
		if(offer>=m) return 1;
		else return 0;
	}
	else
	{
		long long ret=0;
		for(int i=0;i<n;i++)
		{
			if(!used[i])
			{
				used[i]=true;
				if(s[pos] && pos-offer<c[i]) ret+=dfs(pos+1,offer+1);
				else ret+=dfs(pos+1,offer);
				used[i]=false;
			}
		}
		return ret%998244353;
	}
}

int main()
{
	memset(used,0,sizeof(used));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>temp_s;
	for(int i=0;i<n;i++)
	{
		
		if(temp_s[i]=='1') s[i]=true;
		else s[i]=false;
		if(i!=0)
		{
			if(!s[i-1])
			{
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("%lld",dfs(0,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
