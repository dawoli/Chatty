#include<bits/stdc++.h>
using namespace std;
const int d=2000;
int k,n,m,lst[4010],s[400010],T,Q,a[4010],vis[4010][110];
struct node{
	int y,z;
};
vector<node>v[200010];
struct node1{
	int v,id;
};
vector<node1>nv[200010];
void bfs(){
	queue<pair<int,int> >q;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<nv[i].size();j++){
			cnt++;
			if(nv[i][j].v==1)
				q.push({cnt,1}),vis[cnt][1]=1;
		}
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		q.pop();
		int x=tmp.first,t=tmp.second,www=v[x].size();
//		cout<<x<<" "<<t<<"\n";
		for(int i=0;i<www;i++){
			if(t+v[x][i].z>100||vis[v[x][i].y][t+v[x][i].z])
				continue;
			vis[v[x][i].y][t+v[x][i].z]=1;
			q.push({v[x][i].y,t+v[x][i].z});
		}
	}
}
void work(){
	int cnt=0;
	memset(vis,0,sizeof vis);
	memset(s,0,sizeof s);
	cin>>n>>k>>Q;
	if(n>2000){
		cout<<0<<"\n";
		return ;
	}
	for(int i=1;i<=200000;i++)
		nv[i].clear(),v[i].clear();
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++)
			cin>>a[j];
		for(int j=1;j<=l;j++){
			cnt++;
			nv[i].push_back({a[j],cnt}); 
			for(int p=j+1;p<=min(l,j+k-1);p++){
				v[cnt].push_back({cnt+p-j+d,0});
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int p=0;p<nv[i].size();p++)
				for(int q=0;q<nv[j].size();q++)
					if(nv[i][p].v==nv[j][q].v)
						v[nv[i][p].id+d].push_back({nv[j][q].id,1}),v[nv[j][q].id+d].push_back({nv[i][p].id,1});
	bfs();
	while(Q--){
		int r,c,qwq=0,flag=0;
		cin>>r>>c;
		for(int i=1;i<=n;i++)
			for(int j=0;j<nv[i].size();j++){
				if(nv[i][j].v==c){
					qwq++,flag|=vis[nv[i][j].id+d][r];
				}
			}
		cout<<flag<<"\n";
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--)
		work();
}
