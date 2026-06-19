#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int shuju=1;shuju<=T;shuju++){
		int n,m,V,L,sum=0;
		cin>>n>>m>>L>>V;
		struct Sample{
			int d;
			int v;
			int a;
		};
		Sample Car[n];
		bool p[L];
		memset(p,false,sizeof(p));
		for(int i=0;i<n;i++)cin>>Car[i].d>>Car[i].v>>Car[i].a;
		for(int i=0;i<m;i++){
			int x;
			cin>>x;
			p[x]=true;
		}
		
//--------------------------------------------------------------------------

		for(int i=0;i<n;i++){
			if(Car[i].a==0){
				if(Car[i].v>V){
					bool panduan=false;
					for(int j=Car[i].d;j<=L;j++){
						if(p[j]==true){
							panduan=true;
							break;
						}
					}
					if(panduan==true){
						sum++;
					}
				continue;
				}
			}
			else if(Car[i].a<0){
				double t=Car[i].v/(-Car[i].a);
				double Distance=Car[i].v*t+0.5*Car[i].a*t*t;
				for(int j=Car[i].d;j<=min((double)L,Car[i].d+Distance);j++){
					if(p[j]==true){
						if(j==Car[i].d){
							if(Car[i].v>V){
								sum++;
							}
						}
						else{
							double vj=sqrt(Car[i].v*Car[i].v+2*Car[i].a*(j-Car[i].d));
							if(vj>V){
								sum++;
							}
						}
						break;
					}
				}
			}
			else{
				for(int j=Car[i].d;j<=L;j++){
					if(p[j]==true){
						if(j==Car[i].d){
							if(Car[i].v>V){
								sum++;
							}
							break;
						}
						else{
							double vj=sqrt(Car[i].v*Car[i].v+2*Car[i].a*(j-Car[i].d));
							if(vj>V){
								sum++;
								break;
							}
						}
					}
				}
			}
		}
		cout<<sum<<" "<<m-sum+1<<endl;
	}
	return 0;
}
