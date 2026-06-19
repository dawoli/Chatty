#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V,ans1,ans2;//n车辆数量，m测速仪数量，L路长，V限速
double lastp;
int road[1000001],p[N];
struct car{
	int start,v,a;
}c[N]; 
int sum(){
	int r=0;
	for(int i=1;i<=n;i++){
		if(c[i].start>lastp)continue;
		if(c[i].v<=V&&c[i].a<=0)continue;
		if(c[i].v>V&&c[i].a>=0){
			r++;
			continue;			
		};
		if(c[i].v<V&&c[i].a>0){
			double s;
			s=(V*V-c[i].v*c[i].v)/(2.0*c[i].a);
			if(lastp>(s+c[i].start)){
				r++;
				continue;
			}
		}
		if(c[i].v>V&&c[i].a<0){
			for(int j=c[i].start;j<=lastp;j++){
				if(road[j]){
					int s=j-c[i].start;
					if(V*V<(c[i].v*c[i].v+2*c[i].a*s)){
						r++;
						break;
					}
				}
			}
		}
	}
	return r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(c,0,sizeof(c));
		memset(road,0,sizeof(road));
		memset(p,0,sizeof(p));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].start>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			road[p[i]]=1;
		}
		lastp=p[m];
		ans1=sum();
		ans2=0;
		for(int i=1;i<=m;i++){
			road[p[i]]=0;
			if(i==m){
				for(int j=m-1;j>=1;j--){
					if(road[p[j]]){
						lastp=p[j];
						break;
					}
				}
			}
			if(sum()==ans1){
				ans2++;
				continue;
			}
			else road[p[i]]=1;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	
	return 0;
}

