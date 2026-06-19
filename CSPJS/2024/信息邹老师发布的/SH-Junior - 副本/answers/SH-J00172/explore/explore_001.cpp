#include<bits/stdc++.h>
using namespace std;
const int Max_N=1e3+10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
long long T,N,M,K,X,Y,d;
char C[Max_N][Max_N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N>>M>>K>>X>>Y>>d;
		bool Vis[N+1][M+1];
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){cin>>C[i][j];Vis[i][j]=0;}
		}
		long long Ans=1;Vis[X][Y]=1;
		for(int t=1;t<=K;t++){
			long long NX=X+dx[d],NY=Y+dy[d];
			if(1<=NX&&NX<=N&&1<=NY&&NY<=M&&C[NX][NY]=='.'){
				X=NX;Y=NY;
				if(Vis[X][Y]==0){Vis[X][Y]=1;Ans++;}
			}
			else d=(d+1)%4;
		}
		cout<<Ans<<endl;
	}
	return 0;
}
