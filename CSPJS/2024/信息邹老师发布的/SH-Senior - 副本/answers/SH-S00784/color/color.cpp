#include<bits/stdc++.h>
using namespace std;
const int N =1e2+5;
int a[N],ans,n,f[N][N][N];
bool flag[N][N][N]; 
int dfs(int i,int lasr,int lasb){
	if(flag[i][lasr][lasb]) return f[i][lasr][lasb];
	if(i==n+1)	return 0;
	f[i][lasr][lasb]=max(dfs(i+1,i,lasb)+(a[lasr]==a[i])*a[i],dfs(i+1,lasr,i)+(a[lasb]==a[i])*a[i]); 
	flag[i][lasr][lasb]=1;
	return f[i][lasr][lasb];
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){	
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		memset(flag,0,sizeof flag);
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<dfs(1,0,0)<<endl;
	}
}
