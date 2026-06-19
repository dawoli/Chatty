#include<bits/stdc++.h>
using namespace std;
typedef long long qwq;
const qwq maxn=505;

qwq n,m,ans;
qwq a[maxn],c[maxn];
qwq r[maxn],vis[maxn];
string s;

void check(){
	for(int i=1;i<=n;i++){
		if(c[r[i]]<a[i]) return;
	}
	ans++;
}
void dfs(qwq l){
	if(l==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&c[i]>=a[l]){
			r[l]=i; vis[i]=1;
			dfs(l+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
	    if(s[i-1]-'0'==1) a[i]=a[i-1]+1;
	    else a[i]=a[i-1];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
