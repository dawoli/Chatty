#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
#define int long long 
struct d{
	int from,to,val;
	bool operator<(const d &x)const{
		return val<x.val;
	}
};
vector <d> e[20005];
int edg[15][1005];
int anse[1005][1005];
d bian[1000005];int r=1;
int c[20005]; 
int fa[20005];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int merge(int x,int y){
	if(find(fa[x])!=find(fa[y])){
		fa[find(x)]=find(fa[y]);
	}
}
signed main(int argc, char** argv) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	memset(anse,0x3f,sizeof(anse));
	memset(edg,0x3f,sizeof(edg));
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		e[x].push_back({x,y,z});
		e[y].push_back({y,x,z});
		bian[r++]={x,y,z};
		anse[x][y]=z;
		anse[y][x]=z;
//		bian[r++]={y,x,z};
	}
	int flag=1;
	for(int i=n+1;i<=n+k;i++){
//		cin >> c[i];
		scanf("%lld",&c[i]);
		if(c[i]!=0){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			int x;
			scanf("%lld",&x);
			edg[i-n][j]=x;
//			if(x!=0)flag=0;
//			e[i].push_back({i,j,x});
//			e[j].push_back({j,i,x});
//			bian[r++]={i,j,x};
//			bian[r++]={j,i,x};
			
			
		}
		
	}
	sort(bian+1,bian+r);
//	cout << endl << endl;
//	for(int i=1;i<r;i++){
//		cout << bian[i].from << " " << bian[i].to << " " << bian[i].val << endl;
//	}
//	cout << "\n\n";
	if(k==0){
		int ans=0;
		int sumbian=0;
		for(int i=1;i<r;i++){
			int u=bian[i].from,v=bian[i].to,w=bian[i].val;
			if(find(u)!=find(v)){
//				cout << find(u) << " " << find(v) << endl;
				sumbian ++;
				ans+=w;
				merge(u,v);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	else if(flag==1){
//		for(int j=1;j<=n;j++){
//			for(int des=1;des<=n;des++){
//				cout << anse[j][des]<< " ";
////			
//			}
//			cout << endl;
//		}
//		cout << "fda";
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int des=1;des<=n;des++){
//					cout << i << endl;
					if(j==des)continue;
					anse[j][des]=min(anse[j][des],edg[i][j]+edg[i][des]);
//					bian[r++]={j,des,edg[i+n][j]+edg[i+n][des]};
				}
			}
		}
//		for(int j=1;j<=n;j++){
//			for(int des=1;des<=n;des++){
//				cout << anse[j][des]<< " ";
////			
//			}
//			cout << endl;
//		}
		r=1;
		for(int j=1;j<=n;j++){
			for(int des=1;des<=n;des++){
//				cout << anse[j][des]<< " ";
//				cout << i << endl;
				if(j==des)continue;
				bian[r++]={j,des,anse[j][des]};
//				bian[r++]={j,des,edg[i+n][j]+edg[i+n][des]};
			}
//			cout << endl;
		}
//		cout << "fda";
		sort(bian+1,bian+r);
		int ans=0;
		int sumbian=0;
		for(int i=1;i<r;i++){
			int u=bian[i].from,v=bian[i].to,w=bian[i].val;
			if(find(u)!=find(v)){
//				cout << find(u) << " " << find(v) << endl;
				sumbian ++;
				ans+=w;
				merge(u,v);
			}
		}
		printf("%lld",ans);
		return 0;
		
	}
//	cout << "fdafa";
	//long long !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}
/*
8 9 0
1 4 6
2 3 7
4 2 5
4 3 4
6 8 9
3 5 3
7 8 4
7 5 6
1 8 5

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
