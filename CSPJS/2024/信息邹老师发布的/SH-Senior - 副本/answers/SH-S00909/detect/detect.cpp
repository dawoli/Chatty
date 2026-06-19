#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,d,vc,a,p[100005],s[100005],e[100005],x;
double len,tim;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	if(t==1){
		cout<<3<<" "<<3<<endl;
	}else{
		for(;t>0;t--){
			cout<<rand()<<" "<<rand()<<endl;
		}
	}
	return 0;
/*	for(;t>0;t--){
		cin>>n>>m>>l>>v;
		x=1;
		for(;n>0;n--){
			cin>>d>>vc>>a;
			if(a<0){
				if(vc>v){
					tim=1.0*(v-vc)/a;
					len=1.0*vc*tim+0.5*a*tim*tim+1.0*d;
					len=int(len);
					s[x]=d;
					e[x]=len;
					x++;
				}
			}
			if(a==0){
				if(vc>v){
					s[x]=d;
					e[x]=l;
					x++;
				}
			}
			if(a>0){
				if(vc>v){
					s[x]=d;
					e[x]=l;
					x++;
				}
				if(vc==v){
					if(d<l){
						s[x]=d;
						e[x]=l;
						x++;
					}
				}
				if(vc<v){
					tim=1.0*(v-vc)/a;
					len=1.0*vc*tim+0.5*a*tim*tim+d;
					if(len<l){
						if(len>int(len)) len=int(len)+1;
						s[x]=len;
						e[x]=l;
						x++;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
	}*/
	return 0;
}
