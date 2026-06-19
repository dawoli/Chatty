#include<bits/stdc++.h>
using namespace std;

#define int long long

const int Maxn=5e2,Mod=998244353;
int n,m,c[Maxn+5],a[Maxn+5],ans;
string s;
bool v[Maxn+5];

void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]||s[i-1]=='0') cnt++;
		}
		if(n-cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]) v[i]=true,a[x]=i,dfs(x+1),v[i]=false;
	}
}

int jc(int x){
	int sum=1;
	for(int i=1;i<=x;i++) sum*=i,sum%=Mod;
	return sum;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=11){
		dfs(1);	
		cout<<ans%Mod<<endl;
	} 
	else{
		bool flag=false;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') flag=true;
			if(c[i]==0) cnt++;
		}
		if(flag||n-cnt<m) cout<<0<<endl;
		else{
			cout<<jc(n-cnt)%Mod<<endl;
		}
	}
	return 0;
}
