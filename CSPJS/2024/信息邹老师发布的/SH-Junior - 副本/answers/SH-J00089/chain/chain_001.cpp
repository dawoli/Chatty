#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[1003][2003];
int r,c;
struct point{
	int no,wh,va;
};
queue<point> que;
int dfs(point u,int dp){
	if(dp>r)return 0;
	int i=u.no;
	for(int j=u.wh+1;j<=u.wh+k-1&&j<=s[i][0];j++){
		que.push((point){i,j,s[i][j]});
		if(dp==r&&s[i][j]==c){
			
			return 1;
		}
	}
	for(int j=1;j<=n;j++){
		if(j!=i){
		for(int k=1;k<=s[j][0];k++){
			int ft=que.front().va;
			bool b=((s[j][k])==(ft));
			if(b){
				int a=dfs((point){j,k,s[j][k]},dp+1);
				if(a==1){
					return 1;
				}
				que.pop();
			}
		}	
		}
		
		
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
			}s[i][0]=l;
		}for(int a=0;a<q;a++){
			cin>>r>>c;
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=s[i][0];j++){
					if(s[i][j]==1){
						if(i==2&&j==1)cout<<7;
						int cc=dfs((point){i,j,1},1);
						if(cc==1){
							res=1;
						}
					}
				}
			}cout<<res<<endl;
		}
	}
	return 0;
}
