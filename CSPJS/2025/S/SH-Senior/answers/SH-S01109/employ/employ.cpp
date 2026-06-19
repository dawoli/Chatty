#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans;
string s;
int a[1145];
bool check[1145];
long long f[1145];
const long long MOD = 998244353;

int dfs(int ind,int re)
{
	//cout<<ind<<" "<<re<<'\n';
	bool flag = 0;
	if(ind>n)
	{
		if(re <= n - m) {
			ans++;//cout<<"!\n"<<re<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		
		if(!check[i])
		{
			//cout<<i<<endl;
			flag = (re>=a[i] || s[ind-1]=='0');
			check[i] = 1;
			dfs(ind+1,re+int(flag));
			check[i] = 0;
			
			
		}
	}
	
	
	
	return 0;
}






int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];


	dfs(1,0);
	cout<<ans % MOD;
	
	


	
	return 0;
}
