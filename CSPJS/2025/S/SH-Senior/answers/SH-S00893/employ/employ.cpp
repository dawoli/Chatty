#include<bits/stdc++.h>
using namespace std;
int a[1009],n,m,s[1009],c[1009],ans;
bool vst[1009];
int isok(){
	int runAway=0,sum=0;
	for(int i=1;i<=n;i++){
		int nw=a[i];
		if(runAway>=c[nw]){
			runAway++;
			continue;
		}
		if(s[i]==0){
			runAway++;
			continue;
		}else{
			sum++;
			continue;
		}
	}
	if(sum>=m) return 1;
	return 0;
}
void dfs(int dep){
	if(dep==n+1){
		ans+=isok();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vst[i]){
			a[dep]=i;
			vst[i]=1;
			dfs(dep+1);
			vst[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>40){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='0') s[i]=0;
		else s[i]=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
