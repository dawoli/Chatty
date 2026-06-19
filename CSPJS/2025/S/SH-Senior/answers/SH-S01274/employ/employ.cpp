#include<bits/stdc++.h>
using namespace std;

long long n,m,s[510],c[510],ans;
char a;
bool vis[510];

void dfs(long long pos,long long cnt,long long nok,long long id){
	if(nok>=c[id]){
		nok++;
	}else{
		if(s[pos]==0){
			nok++;
		}else{
			cnt++;
		}
	}
	if(cnt>=m){
		ans=(ans+1)%998244353;
		return;
	}
	if(pos==n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			dfs(pos+1,cnt,nok,i);
			vis[i]=false;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=true;
		dfs(1,0,0,i);
		vis[i]=false; 
	}
	cout<<ans<<endl;
}
