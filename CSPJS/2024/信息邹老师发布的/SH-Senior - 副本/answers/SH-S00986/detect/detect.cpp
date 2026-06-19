#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int m,T,n;
double L,V,p[N],ans,num,Max[N];
vector<double> q[N];
struct car{
	double d;
	double v;
	double a;
}c[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		ans=0,num=0;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(c[1].a==0 && n>20){
				if(c[i].v>V){
					ans++;
				}
				num=m-1;
			}
			if(c[1].a>0 && n>20){
				double x=sqrt(c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d));
				if(x>V){
					ans++;
				}
				num=m-1;
			}
		}
		for(int i=1;i<=n;i++){
			c[i].a=0;
			c[i].d=0;
			c[i].v=0;
		}
		cout<<ans<<" "<<num<<endl;
	}
	return 0;
}
