#include<bits/stdc++.h>
using namespace std;
int f[509],n,m,ans;
string s;
bool visit[19];
int bfs(int now,int fail,int pass,int num){
	if(num==n){
		if(fail<f[now]&&s[num-1]=='1') pass++;
		if(pass>=m) ans++;
		return 0;
	}
	if(fail<f[now]&&s[num-1]=='1'){
		for(int j=1;j<=n;j++){
			if(!visit[j]){
				visit[j]=1;
				bfs(j,fail,pass+1,num+1);
				visit[j]=0;
			}
		}
	}
	else{
		for(int j=1;j<=n;j++){
			if(!visit[j]){
				visit[j]=1;
				bfs(j,fail+1,pass,num+1);
				visit[j]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int flag0=0;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=0;i<s.size();i++){
		if(s[i]!=0) flag0=1;
	}
	if(!flag0){
		cout<<0<<endl;
		return 0;
	}
	if(n<=12){
		for(int i=1;i<=n;i++){
			visit[i]=1;
			bfs(i,0,0,1);
			visit[i]=0;	
		}
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
