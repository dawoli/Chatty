#include<bits/stdc++.h>
#define ull long long
#define db long long
using namespace std;

int T;
struct car{
	db a;
	db v;
	db d;
	bool extra;
}c[100010];

ull m,n;
db mo[100010];
db V,L;


bool A(){
	for(ull i=1;i<=n;++i){
		if(c[i].a==0)continue;
		else return false;
	}
	return true;
}
bool B(){
	for(ull i=1;i<=n;++i){
		if(c[i].a>0)continue;
		else return false;
	}
	return true;
}



int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>T;
	for(ull i=1;i<=T;++i){
		cin>>n>>m>>L>>V;ull ans=0;
		for(ull j=1;j<=n;++j){
			cin>>c[j].d>>c[j].v>>c[j].a;
			}
			for(ull j=1;j<=m;++j){
				cin>>mo[j];
			}
			if(A()){
				for(ull j=1;j<=n;++j){
					if(c[j].v>V&&c[j].d<=mo[m])++ans;
				}
				db x=0;bool flag=true;
				for(int i=1;i<=n;++i){
					if(c[i].v>V&&flag){
						x=c[i].d;
						flag=false;
					}
					if(c[i].v>V&&c[i].d<x){
						x=c[i].d;
					}
				}
				cout<<ans<<" ";
				if(ans==0){
					cout<<m<<endl;
				}
				else{
					cout<<m-1<<endl;
				}
				fill(mo,mo+100010,0);
			}
			else if(B()){
				for(ull j=1;j<=n;++j){
					if(c[j].v<=V&&(V*V-c[j].v*c[j].v)/(2*c[j].a)+c[j].d<=L){
						c[j].d=(V*V-c[j].v*c[j].v)/(2*c[j].a)+c[j].d;	
						c[j].extra=true;
					}
				}
				for(ull j=1;j<=n;++j){
					if((c[j].v>V&&c[j].d<=mo[m])||(c[j].extra&&c[j].d<=mo[m]))++ans;
				}
				int x=0;bool flag=true;
				for(ull i=1;i<=n;++i){
					if(c[i].v>V&&flag){
						x=c[i].d;
						flag=false;
					}
					if(c[i].v>V&&c[i].d<x){
						x=c[i].d;
					}
				}
				cout<<ans<<" ";
				if(ans==0){
					cout<<m<<endl;
				}
				else{
					cout<<m-1<<endl;
				}
				fill(mo,mo+100010,0);
			}
	
	}
	return 0;
}
