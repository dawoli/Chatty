#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,mod=998244353;
int p[13],used[13];
string s;
int c[510];

//17:18 2 X 4=8 tps
//17:33 maybe 12 tps

bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[p[i]]){
			cnt++;
			continue;
		}
		if(s[i-1]=='0')cnt++;
	}
	if(n-cnt>=m)return 1;
	return 0;
}

void dfs(int x){
	if(x==n+1){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==1)continue;
		p[x]=i;
		used[i]=1;
		dfs(x+1);
		used[i]=0;
	}
}

void planA(){
	int p=n;
	ans=1;
	for(int i=1;i<=n;i++){
		if(c[i]==0)p--;
	}
	if(p<m){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	int flag1=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]!='1')flag1=1;
	}
	if(flag1==0){
		planA();
		return 0;
	}
}
