#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sc,fail,ans,c[501],used[501];char s[501];
void dfs(int a){
	if(a==n+1){
		if(sc>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			if(s[a-1]=='1'&&fail<c[i]){
				used[i]=1;sc++;dfs(a+1);sc--;used[i]=0;
			}
			else{
			used[i]=1;fail++;dfs(a+1);fail--;used[i]=0;
		}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
