#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct s{
	ll d,v,a,l,r;
	bool check=false;
}car[maxn];
struct {
	ll pos;
	ll overlap[maxn];
}p[maxn];
int main(){
	freopen("detect.in",r,stdin);
	freopen("detect.out",w,stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
			if(car[i].v>=v && car[i].a>=0){
				car[i].l=car[i].d;
				car[i].r=l;
			}else if(car[i].v<v && car[i].a>0){
				car[i].l=car[i].d+(v*v-car[i].v*car[i].v)/(2*car[i].a);
				car[i].r=l;
			}else if(car[i].v>=v && car[i].a<0){
				car[i].l=car[i].d;
				car[i].r=car[i].d+(v*v-car[i].v*car[i].v)/(2*car[i].a);
			}else if(car[i].v<v && car[i].a<=0){//包不超速的，遵纪守法 
				car[i].l=car[i].r=0; 
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i].pos;
		}
		sort(p,p+m+1);
		ll count=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++){
				if(car[i].l<=p[j].pos&& p[j].pos<=car[i].r){
					p[j].overlap[p[j].cnt]=car[i];
					p[j].cnt++;
					if(car[i].check=false){
					count++;
					car[i].check=true;
					}
				}
			}
		}
		cout<<count<<"\n"<<0;
	}
} 
