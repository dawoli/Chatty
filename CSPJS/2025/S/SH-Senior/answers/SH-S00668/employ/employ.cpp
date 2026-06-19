#include<bits/stdc++.h>
using namespace std;
const int Mod = 998224353;
int n,m;
bool s[509],vst[509];
int c[509];
long long ans = 0;
void dfs(int ju,int now){
	if(now == n){
		if((n - ju) >= m){
			ans++;
		}
		return;
	}
	for(int i = 0;i < n;i++){
		if(vst[i]){
			continue;
		}
		vst[i] = 1;
		if(ju >= c[i] or s[now] == 0){
			dfs(ju + 1,now + 1);
		}else{
			dfs(ju,now + 1);
		}
		vst[i] = 0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		char ch;
		cin>>ch;
		if(ch == '1'){
			s[i] = 1;
		}
	}
	for(int i = 0;i < n;i++){
		cin>>c[i];
	}
	sort(c,c + n);
	dfs(0,0);
	cout<<ans;
	return 0;
}

