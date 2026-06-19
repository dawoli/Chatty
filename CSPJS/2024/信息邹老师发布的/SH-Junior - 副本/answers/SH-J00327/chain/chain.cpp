#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9,R=109;
int n,k,m;
int lth[N];
vector<int> s[N];
vector<pair<int,int> > e[N];
bool dis[R][N];
int dpx[R][N];
bool dxx[R][N];
int inq[R][N];
queue<pair<pair<int,int>,int> > q;//{r,u,last}
void bfs(){
	q.push({{0,1},0});
	dis[0][1]=true;
	while(q.size()){
//		cnt++;
//		cout<<cnt;
		int r=q.front().first.first,u=q.front().first.second,lst=q.front().second;
		q.pop();
		if(r>100)
			continue;
		for(int i=0;i<e[u].size();i++){
			int nx=e[u][i].first,jx=e[u][i].second;
			if(nx==lst)
				continue;
			bool f=false;
			for(int j=1;j<k&&jx+j<lth[nx];j++){
				int v=s[nx][jx+j];
				if(!dis[r+1][v]){
					dis[r+1][v]=f=true;
					dpx[r+1][v]=nx;
					q.push({{r+1,v},nx});
				}
				else{
					if(dpx[r+1][v]!=nx&&(!dxx[r+1][v]))
						q.push({{r+1,v},nx}),dxx[r+1][v]=f=true;
				}
			}
		}
//		cout<<cnt<<endl;
	}
}
void mem(){
	memset(lth,0,sizeof(lth));
	for(int i=1;i<=N-9;i++){
		while(s[i].size())
			s[i].pop_back();
		while(e[i].size())
			e[i].pop_back();
	}
	memset(dis,0,sizeof(dis));
	memset(dpx,0,sizeof(dpx));
	memset(inq,0,sizeof(inq));
	q.empty();
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mem();
		cin>>n>>k>>m;
		for(int i=1;i<=n;i++){
			int x;
			cin>>lth[i];
			for(int j=0;j<lth[i];j++){
				cin>>x;
				s[i].push_back(x);
				e[x].push_back({i,j});
			}
		}
		bfs();
		for(int i=1;i<=m;i++){
			int r,c;
			cin>>r>>c;
			if(dis[r][c])
				cout<<"1\n";
			else
				cout<<"0\n";
		}
	}
	return 0;
}
