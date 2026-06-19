#include<bits/stdc++.h>
using namespace std;
#define N 200007
int n,m,T,a0[N],c[N],x[4]; 
int a[N];
vector<bool> d[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a0[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int xx=n,n2=0;
	while(xx){
		n2=(xx&(-xx));
		xx-=(xx&(-xx));
	}
	if(n==(n&(-n))) n2<<=1;
	int h=0;
	int kk=n2;
	while(kk){
		++h;
		for(int i=1;i<=kk;++i){
			int u;
			scanf("%1d",&u);
			d[h].push_back(u);
		}
		kk>>=1;
	}
	cin>>T; 
	while(T--){
		for(int i=0;i<4;++i){
			cin>>x[i];
		}
		for(int i=1;i<=n;++i){
			a[i]=a0[i]^x[i%4];
		}
		vector<int> vc[2];
		int ans=0;
		for(int ii=1;ii<=n;++ii){
			int xx=c[ii],ct=0;
			while(xx){
				++ct;
				int i=0;
				vc[ct&1].clear();
				for(int k=0;k<d[ct].size();++k){
					int v=d[ct][k];
					if(v==0){
						if(a[i]>=ct) vc[ct&1].push_back(a[i]);
						else vc[ct&1].push_back(a[i+1]);
					}
					else{
						if(a[i+1]>=ct) vc[ct&1].push_back(a[i+1]);
						else vc[ct&1].push_back(a[i]);
					}
				}
				xx>>=1;
			}
			ans^=(ii*vc[ct&1][1]);
		}
		cout<<ans<<'\n';
	}
}
