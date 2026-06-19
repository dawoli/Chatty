#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct CAR{
	int d,speed,a;
}c[100005];
int p[100005];
int to[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int ans1=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].speed>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			for(int j=(p[i-1]+1);j<=p[i];j++){
				to[j]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i].d<=p[m]){
				if(c[i].a>0){
					int tmp=p[m]-c[i].d;
					if((c[i].speed*c[i].speed+2*c[i].a*tmp)>v*v){
						ans1++;
					}
				}
				else if(c[i].a==0){
					if(c[i].speed>v){
						ans1++;
					}
				}
				else{
					if(c[i].speed>=v){
						int tmp=p[to[c[i].d]]-c[i].d;
						if((c[i].speed*c[i].speed+2*c[i].a*tmp)>v*v){
							ans1++;
						}
					}
				}
			}
		}
		if(ans1!=0)cout<<ans1<<" "<<m-1<<endl;
		else cout<<0<<" "<<m<<endl;
	}
	return 0;
}
