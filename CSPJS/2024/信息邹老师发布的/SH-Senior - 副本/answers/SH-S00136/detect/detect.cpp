#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,m,L,V,cs=0;
struct car{
	int d;
	int a;
	int v;
	double cs1=N;
	double cs2=N;
}c[N];
int csy[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>m>>L>>V;
		cs=0;
		for(int j=1;j<=m;j++){
			cin>>c[j].d>>c[j].v>>c[j].a;
			if(v<=V&&a<=0) continue;
			if(v>V&&a>=0){
				cs++;
				c[j].cs1=d;
				c[j].cs2=L;
			}
			if(v>V&&a<0){
				cs++;
				c[j].cs1=d;
				c[j].cs2=(V*V-v*v)/(2*a)+d;
			}
			if(v<=V&&a>0){
				cs++;
				c[j].cs1=(V*V-v*v)/(2*a)+d;
			}
		}
		for(int j=1;j<=n;j++) cin>>csy[j];
		for()
		cout<<cs;
	}
	return 0;
}
