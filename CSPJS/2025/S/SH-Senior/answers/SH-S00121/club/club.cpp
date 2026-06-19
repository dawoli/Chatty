#include<bits/stdc++.h>
using namespace std;

int T;
int N,f[100005],ans,fx[5];
struct Node{
	int a,b,c;
}A[100005];

void dfs(int k){
	if(k==N+1){
		int cnt=0;		
		for(int i=1;i<=N;i++){
			cnt+=f[i];
		}
		ans=max(ans,cnt);
	}else{
		f[k]=A[k].a;fx[1]++;
		if(fx[1]<=N/2) dfs(k+1);
		fx[1]--;
		
		f[k]=A[k].b;fx[2]++;
		if(fx[2]<=N/2) dfs(k+1);
		fx[2]--;
		
		f[k]=A[k].c;fx[3]++;
		if(fx[3]<=N/2) dfs(k+1);
		fx[3]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		memset(A,0,sizeof(A));
		memset(fx,0,sizeof(fx));
		ans=0;
		cin>>N;
		for(int i=1;i<=N;i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
