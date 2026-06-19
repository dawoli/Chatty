#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,res;
char now[N];
int vis[N];
char s[N],c[N];
void dfs(int x){
	if(x>n){
		int ans=0,cnt[N]={0};
		for(int i=1;i<=n;i++){
			cnt[i]=cnt[i-1];
			if(cnt[i]>=c[i]){
				cnt[i]++;
			}
			else{
				if(now[i]=='0'){
					cnt[i]++;
				}
				else{
					ans++;
				}
			}
			
		}
		if(ans>=m){
			res++;
			res%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		now[x]=s[i];
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	dfs(1);
	cout << res << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
