#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long tu[10015][10015],u,v,w,c[15],a;
long long dis[10015];
bool vis[10015];
queue<int>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(tu,0x3f3f3f3f,sizeof(tu));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		tu[u][v]=tu[v][u]=w;
	}
//	cout<<n<<' '<<k<<"!!";
	for(int i=1;i<=k;i++){
		cin>>c[k];
//		cout<<"^";
		for(int j=1;j<=n;j++){
			cin>>a;
//			cout<<"%"<<a<<"@";
			tu[i+n][j]=tu[j][i+n]=a;
		}
//		cout<<"()";
	}
//	cout<<"(((";
//	for(int i=1;i<=n+k;i++){
//		for(int j=1;j<=n+k;j++){
//			if(tu[i][j]<0x3f3f3f3f)cout<<tu[i][j]<<' ';
//			else cout<<"max"<<' ';
//		}
//		cout<<endl;
//	}
	q.push(1);
	dis[1]=0;
	vis[1]=1;
	while(q.empty()==0){
		int d=q.front();
		q.pop();
//		cout<<q.front();
//		cout<<d<<endl;
		for(int i=1;i<=n+k;i++){
			if(vis[i]==0){
				dis[i]=min(dis[i],dis[d]+tu[i][d]);
				cout<<dis[i]<<'*'<<i<<endl;
			}
		}
		int minnn=0x3f3f3f3f,minn=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&dis[i]<minnn){
				minnn=dis[i];
				minn=i;
			}
		}
		for(int i=1;i<=k;i++){
			if(vis[i+n]==0&&dis[i+n]+c[i]<minnn){
				minnn=dis[i+n]+c[i];
				minn=i+n;
			}
		}
		vis[minn]=1;
		if(minn==0)break;
		q.push(minn);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
		if(vis[i]==1&&maxn<dis[i])maxn=dis[i];
	}
	cout<<maxn;
	return 0;
} 
