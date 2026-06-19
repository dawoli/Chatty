#include<bits/stdc++.h>
using namespace std;
struct ca{
	int d;
	int v;
	int a;
}c[100005];
int p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	int n,m,L,V,ans1,ans2,k;
	cin>>T;
	while(T>0){
		T--;
		ans1=0;
		ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			if(c[i].d>p[m]) continue;
			for(int j=1;j<=m;j++){
				if(p[j]>=c[i].d){
					k=j;
					break;
				}
			}
			if(c[i].a>=0){
				if(pow(c[i].v,2)+2*c[i].a*(p[m]-c[i].d)>pow(V,2)){
					ans1++;
				}
			}
			else{
				if(pow(c[i].v,2)+2*c[i].a*(p[k]-c[i].d)>pow(V,2)){
					ans1++;
				}
			}
		}
		cout<<ans1<<' ';
		if(ans1==0) cout<<0;
		else cout<<1;
		cout<<endl;
	}
	return 0;
}
