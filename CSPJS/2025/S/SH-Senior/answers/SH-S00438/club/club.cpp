#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
};
node g;
node f[4][100020];
int ka=0,kb=0,kc=0;
int fa=0,fb=0,fc=0;
bool pa=true,pb=true,pc=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>g.a>>g.b>>g.c;
			if(g.a>g.b&&g.a>g.c&&pa){
				if(ka+1<=n/2){
					f[1][ka]=g;
					++ka;
					fa+=g.a;
				}
				else{
					pa=false;
				}
			}
			else if(g.b>g.a&&g.b>g.c&&pb){
				if(kb+1<=n/2){
					f[2][kb]=g;
					++kb;
					fb+=g.b;
				}
				else{
					pb=false;
				}
			}
			else if(g.c>g.a&&g.c>g.b&&pc){
				if(kc+1<=n/2){
					f[3][kc]=g;
					++kb;
					fc+=g.c;
				}
				else{
					pc=false;
				}
			}
			else if(g.a==g.b&&g.a>g.c){
				if(ka<=kb){
					if(ka+1<=n/2&&pa){
						f[1][ka]=g;
						++ka;
						fa+=g.a;
					}
					else{
						pa=false;
					}
				}
				else{
					if(kb+1<=n/2&&pb){
						f[2][kb]=g;
						++kb;
						fb+=g.b;
					}
					else{
						pb=false;
					}
				}
			}
			else if(g.a==g.c&&g.a>g.b){
				if(ka<=kc){
					if(ka+1<=n/2&&pa){
						f[1][ka]=g;
						++ka;
						fa+=g.a;
					}
					else{
						pa=false;
					}
				}
				else{
					f[3][kc]=g;
					++kc;
					fc+=g.c;
				}
			}
			else if(g.b==g.c&&g.b>g.a){
				if(kb<=kc){
					f[2][kb]=g;
					++kb;
					fb+=g.b;
				}
				else{
					f[3][kc]=g;
					++kc;
					fc+=g.c;
				}
			}
			else{
				if(ka<=kb&&ka<kc){
					if(ka+1<=n/2&&pa){
						f[1][ka]=g;
						++ka;
						fa+=g.a;
					}
					else{
						pa=false;
					}
				}
				else if(kb<=kc&&kb<ka){
					f[2][kb]=g;
					++kb; 
					fb+=g.b;
				}
				else if(kc<=ka&&kc<kb){
					f[3][kc]=g;
					++kc;
					fc+=g.c;
				}
			}
		}
		--ka;
		--kb;
		--kc;
		if(ka<=n/2&&kb<=n/2&&kc<=n/2){
			cout<<fa+fb+fc;
		}
		ka=0;kb=0;kc=0;
		fa=0;fb=0;fc=0;
		pa=1;pb=1;pc=1;
	}
	return 0;
}
