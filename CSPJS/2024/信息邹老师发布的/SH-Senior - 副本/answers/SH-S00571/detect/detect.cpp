#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,Ln=1e6+5;
int T,n,m,L,V;
int d[N],v[N],a[N],p[N],f[Ln];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int z=1;z<=T;z++){
		memset(f,0,sizeof(f));
		int ansc=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		int pe=-1;
		for(int i=1;i<=m;i++){
			cin>>p[i];
			f[p[i]]=2;
			pe=max(pe,p[i]);
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			int ss=0,fl1=0;
			float dis=(V*V-v[i]*v[i])/2.0/a[i];
			if(a[i]>=0){
				if(2*a[i]*(pe-d[i])>V*V-v[i]*v[i]&&pe>=d[i]){
					ansc++;
					f[pe]=1;
				}
			}else{
				if(dis<0){
					continue;
				}
				for(int j=d[i]+dis;j>=d[i];j--){
					if(f[j]==2&&!fl1){
						ss=j;
						fl1=1;
					}else if(f[j]==1){
						ansc++;
						fl1=0;
						break;
					}
				}
				if(fl1){
					ansc++;
					f[ss]=1;
				}				
			}
		}
		int ans2=0;
		for(int i=1;i<=pe;i++){
			if(f[i]==1){
				ans2++;
			}
		}
		cout<<ansc<<" "<<m-ans2<<"\n";
	}
	return 0;
} 
