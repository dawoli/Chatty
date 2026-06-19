#include<bits/stdc++.h>
using namespace std;
const int N=509;
const int M=509;
const int MOD=998244353;
int n,m,ans;
string s;
int c[N],a[N];
bool A=true,C=true;//a[i]是第i天来面试的人编号 
bool check()
{
	int rejected=0,accepted=0;
	for(int i=1;i<=n;i++)
	{
		if(rejected<c[a[i]]&&s[i-1]=='1')  accepted++;
		else rejected++;
		if(rejected>n-m) return false;
	}
	return accepted>=m;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') A=false;
		if(s[i]=='1') C=false;
	}
	for(int i=1;i<=n;i++) cin>>c[i],a[i]=i;
	if(n<=30)
	{
		do
		{
			if(check()) ans++;
			ans%=MOD;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
		return 0;
	}
	if(A)
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*n%MOD;
		cout<<ans;
		return 0;
	}
	if(C)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
