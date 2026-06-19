#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,p[100010],nowval,nowit;
int cnt1,cnt2;
bool fl;
map<int,int>mp;
struct Node {
	int d,v,a,sl,el;
} c[100010];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>L>>V;
		mp.clear();
		cnt1=0;
		cnt2=0;
		for(int i=0; i<n; i++) {
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=0; i<m; i++) {
			cin>>p[i];
			mp[p[i]]=0;
		}
		for(int i=0; i<n; i++) {
			fl=false;
			if(c[i].v>V) {
				fl=true;
				c[i].sl=c[i].d;
				if(c[i].a<0) {
					c[i].el=ceil((float)abs(c[i].v*c[i].v-V*V)/abs(2*c[i].a))+c[i].d;
				} else {
					c[i].el=L;
				}
			} else {
				if(c[i].a>0) {
					fl=true;
					c[i].sl=ceil((float)abs(c[i].v*c[i].v-V*V)/abs(2*c[i].a))+c[i].d;
					c[i].el=L;
				}
			}
			//	cs
//			cout<<c[i].sl<<" "<<c[i].el<<" ";
			//	ce
			if(fl) {
				if(*lower_bound(p,p+m,c[i].sl)<=c[i].el){
					cnt1++;
					mp[*lower_bound(p,p+m,c[i].sl)]++;
				}
			}
			//	cs
//			cout<<cnt1<<endl; 
			//	ce
		}
		cout<<cnt1<<" ";
		nowval=0;
		nowit=0;
		//	cs
//		cout<<endl<<"cnt2"<<endl;
		//	ce
		for(int i=0; i<m; i++) {
			if(mp[p[i]])cnt2++;
			//	cs
//			cout<<mp[p[i]]<<" "<<cnt2<<endl;
			//	ce
		}
		cout<<cnt2<<'\n';
	}
	return 0;
}

