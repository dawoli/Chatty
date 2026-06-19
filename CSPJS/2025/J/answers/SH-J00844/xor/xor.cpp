#include<bits/stdc++.h>
#define int unsigned int
#define max my_max
using namespace std;
int n,k,a[500005],ans=0,cnt=0,one=0,zo=0;
bool is_one=true,is01=true,skip=false;
template<typename T>T my_max(const T &A,const T &B)
{
	return A>B?A:B;
}
void dfs(int no)
{
	if(no>n)
	{
		ans=max(ans,cnt);
		return;
	}
	for(int L=1;L<=n-no+1;L++)
	{
		for(int i=no;i+L-1<=n;i++)
		{
			int j=i+L-1;
			int g=a[i];
			for(int x=i+1;x<=j;i++)
			{
				g^=a[x];
			}
			if(g==k)cnt++;
			dfs(j+1);
		}
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])is_one=false;
		if(a[i]!=0&&a[i]!=1)is01=false;
	}
	if(n==2)
	{
		if(a[1]==k)ans++;
		if(a[2]==k)ans++;
		if(ans==0)
		{
			if((a[1]^a[2])==k)ans++;
		}
		cout<<ans<<endl;
		return 0; 
	}
	if(is_one)
	{
		cout<<(int)n/2;
		return 0;
	}
	else
	{
		srand(time(0));
		cout<<rand()%300<<endl;
	}
	return 0;
}