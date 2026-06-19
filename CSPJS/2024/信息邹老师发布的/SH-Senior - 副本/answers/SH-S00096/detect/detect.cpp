#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
int V;
double caculate(int d,int v,int a){
	return d+(v*((V-v)/a)*1.0+0.5*a*((V-v)/a)*((V-v)/a));
}
double caculate1(int s,int v,int a){
	return sqrt(v*v+2*a*s);
}
int t;
int n,d[100005],v[100005],a[100005],m,p[100005],L;
bool b[100005]={};
double num[100005]={};
vector<int> g[100005];
int ans=0x7f7f7f7f;
void dfs(int k,int l,int ans1,int k1){
	
	if(k>=ans1){
		
		if(k1<ans){
			ans=k1;
		}
		return;
	}
	if(l>m){
		return;
	}
	for(int i=l;i<=m;++i){
		
		int temp=0;
		vector<int> t1;
		for(int j=0;j<g[i].size();++i){
			if(!b[g[i][j]]){
				b[g[i][j]]=true;
				temp+=1;
				t1.push_back(g[i][j]);
			}
		}
		if(temp){
			dfs(k+temp,l+1,ans1,k1+1);
			for(int j=0;j<t1.size();++j){
				b[t1[j]]=false;
			}
		}
		
	}
	
}


int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;++T){
		
	
		scanf("%d%d%d%d",&n,&m,&L,&V);
		memset(d,0,sizeof(d));
		for(int i=1;i<=m;++i){
			g[i].clear();
		}
		bool st=false;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]!=0){
				num[i]=caculate(d[i],v[i],a[i]);
				st=true;	
			}
		}
		
		for(int i=1;i<=m;++i){
			scanf("%d",&p[i]);
		}
		
		int ans1=0;
		
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				if(V<v[i]){
					for(int j=1;j<=m;++j){
						if(p[j]>=d[i]){
							ans1+=1;
							b[i]=true;
							break;
						}
					}
					
				}
			}else{
				if((a[i]==0 && v[i]<V) || (a[i]<0 && v[i]<V))continue;
				bool state=false;
				for(int j=1;j<=m;++j){
					if(p[j]<d[i])continue;
					int n1=caculate1(p[j]-d[i],v[i],a[i]);
					if(n1>=V){
						state=true;
						g[j].push_back(i);
					}
				}
				if(state){
					b[i]=true;
					ans1+=1;
				}
			}
			
		}
		//dfs(0,1,ans1,0);
		if(st){
			int num_max=0;
			for(int i=1;i<=n;++i){
				if(b[i] && num[i]>num_max){
					num_max=num[i];
				}
			}
			int ans=0;
			for(int i=1;i<=m;++i){
				if(p[i]>num_max){
					ans=p[i];
					break;
				}
			}
			printf("%d %d\n",ans1-1,ans+(m-ans-1));
			continue;
		}
		int d_max=0;
		for(int i=1;i<=n;++i){
			if(b[i] && d[i]>d_max){
				d_max=d[i];
			}
		}
		int ans=0;
		for(int j=1;j<=m;++j){
			if(p[j]>=d_max){
				ans=j;
				break;
			}
		}
		printf("%d %d\n",ans1,ans+(m-ans-1));
	}
}
