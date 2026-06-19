#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define fr1(i,a,b,k) for(int i=a;i<=b;i+=k)
#define fr2(i,a,b,k) for(int i=a;i>=b;i-=k)
using namespace std;
int n,m,k,u,v,w,a[15][100005],c[15],cnt,cf,ans,f[100005],cs;
struct node{
	int u,v,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<node>e,g;
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	if(find(x)==find(y)){
		return;
	}
	f[find(x)]=find(y);
}
int solvek(){
	int res=0;
	memset(f,0,sizeof(f));
	fr1(i,1,n,1){
		f[i]=i;
	}
	sort(g.begin(),g.end(),cmp);
	fr1(i,0,g.size()-1,1){
		if(find(g[i].u)==find(g[i].v)){
			continue;
		}
		merge(g[i].u,g[i].v);
		res+=g[i].w;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	fr1(i,1,m,1){
		cin>>u>>v>>w;
		e.push_back((node){u,v,w});
	}
	fr1(i,1,k,1){
		cin>>c[i];
		if(c[i]!=0){
			cf=1;
		}
		fr1(j,1,n,1){
			cin>>a[i][j];
			if(a[i][j]!=0){
				cf=1; 
			}
		}
	}
	if(k==0){
		g.clear();
		fr1(j,0,e.size()-1,1){
			g.push_back((node)e[j]);
		}
		cout<<solvek();
		return 0;
	}
	if(cf==0 and k!=0){
		cout<<0;
		return 0;
	}
	ans=1e18;
	fr1(p,0,(1<<k)-1,1){
		cs=0;
		g.clear();
		fr1(j,0,e.size()-1,1){
			g.push_back((node)e[j]);
		}
		fr1(i,1,k,1){
			if((1<<(i-1))&p){
				cs+=c[i];
				fr1(j,1,n,1){
					if(i!=j){
						g.push_back({i,j,a[i][j]});
					}
				}
			}
		}
//		fr1(j,0,g.size()-1,1){
//			cout<<g[j].u<<" "<<g[j].v<<" "<<g[j].w<<endl;
//		}
		ans=min(ans,solvek()+cs);
//		cout<<cs<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
