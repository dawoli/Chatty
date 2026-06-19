#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
string s;
int c[510];
int x[510];
long long  oh(int q)
{
	int ans=1;
	for(int i=1;i<=q;i++)ans=(ans*i)%998244353;
	return ans;
}
void dfs(int no,int nm)
{
	int q=nm;
	for(int i=1;i<=n;i++)
	{
		q=nm;
		if(x[i]){
			continue;
		}
		if(q>=c[i]||s[no-1]=='0')
		{
			q++;
		}
		if(no-q>=m){
			ans+=oh(n-no);
			ans%=998244353;
			return;
		}
		if(q>n-m)continue;
		x[i]=1;
		dfs(no+1,q);
		x[i]=0;
	}	
}
void dfsd(int no){
	if(no==n+1)return;
	for(int i=1;i<=n;i++)
	{
		if(x[i])continue;
		if(!(no>=c[i]||s[no-1]=='0'))
		{
			ans+=oh(n-no);
			ans%=998244353;
			return;
		}
		dfsd(no+1);
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int q=1;
	for(int i=1;i<=n;i++)if(s[i-1]=='0')q=0;
	if(q)
	{
		cout<<oh(n)<<endl;
		return 0;
	}
	if(m==1){
		dfsd(1);
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
	
} 
