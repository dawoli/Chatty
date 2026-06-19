#include <bits/stdc++.h> 
using namespace std;
struct carr{
	double st,ed;
}c[100005];
double p[100005];
int main(){
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,m,l,V,f1=1,f3=1,ans1=0;cin>>n>>m>>l>>V;//f1 a==0 
		for(int i=1;i<=n;i++){
			double d,v,a;//v chu
			cin>>d>>v>>a;
			if(a==0){
				if(v>V){
					c[i].st=d;
					c[i].ed=l;
					f3=0;
				}else{
					c[i].st=-1;
					c[i].ed=-1;
				}
			}else if(a>0){
				if(v>V){
					c[i].st=d;
					c[i].ed=l;					
				}else{
					double tmpd = ceil((V*V-v*v)/(2*a))-0.1;//³¬ËÙÎ»ÒÆÁ¿ 
					if((d+tmpd)>l){
						c[i].st=-1;
						c[i].ed=-1;						
					}else{
						c[i].st=d+tmpd+0.1;
						c[i].ed=l;
					}
			 }
			}else if(a<0){
				if(v<=V){
					c[i].st=-1;
					c[i].ed=-1;					
				}else{
					double tmpd = ceil((V*V-v*v)/(2*a))-0.1;
					c[i].st=d;
					c[i].ed=d+tmpd-0.1;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			//cout<<c[i].st<<' '<<c[i].ed<<endl;
			int tmpa = lower_bound(p,p+m,c[i].st) - p;
			if(p[tmpa]<=c[i].ed) ans1++;
		}
		cout<<ans1<<' ';
		if(f1){
			if(ans1>0) cout<<m-1;
			else cout<<m;
			cout<<endl;
		}
	} 
}
