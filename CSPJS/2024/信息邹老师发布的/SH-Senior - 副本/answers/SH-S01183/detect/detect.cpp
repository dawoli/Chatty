#include<bits/stdc++.h>
using namespace std;
struct car{int d,v,a;};
long long T,h,n,m,L,V,p[100009],cnt,ans,s,t;
bool aa,ab;
car c[100009]; 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(h=1;h<=T;h++){
		cin>>n>>m>>L>>V;
		aa=1,ab=1;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a<0) aa=0,ab=0;
			if(c[i].a==0) ab=0;
			else aa=0;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		cnt=0;
		if(aa){
			for(int i=1;i<=n;i++) if(c[i].v>V&&c[i].d<=p[m]) cnt++;
			if(cnt>0) cout<<cnt<<" "<<m-1<<endl;
			else cout<<cnt<<" "<<m<<endl;
			continue;
		}
		if(ab){
			for(int i=1;i<=n;i++){
				if(c[i].v>V){
					if(c[i].d<=p[m]){
						cnt++;
					}
				}
				if(c[i].v==V){
					if(c[i].d<p[m]){
						cnt++;
					}
				}
				if(c[i].v<V){
					s=(V*V-c[i].v*c[i].v)/(2*c[i].a);
					if(c[i].d+s<p[m]) cnt++;
				}
			}
			if(cnt>0) cout<<cnt<<" "<<m-1<<endl;
			else cout<<cnt<<" "<<m<<endl;
			continue;
		}
	} 
	return 0;
}
