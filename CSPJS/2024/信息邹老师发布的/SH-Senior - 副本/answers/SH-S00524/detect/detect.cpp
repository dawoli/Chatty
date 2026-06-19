#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int d[N],v[N],a[N];
struct node{
	int l,r;
}s[N];
int p[N];
set<int> st;
bool cmp(node x,node y){return x.l>y.l;}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		st.clear();
		int n,m,L,V,ans1=0,ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0){
				if(v[i]>V) s[i].l=d[i],s[i].r=L;
				else s[i].l=s[i].r=L+1;
			}
			if(a[i]>0){
				if(v[i]>V){
					s[i].l=d[i],s[i].r=L;
					continue;
				}
				if(v[i]==V){
					s[i].l=d[i]+1;
					s[i].r=L;
					continue;
				}
				double t=(V-v[i])*1.0/a[i];
				int x;
//				if((V-v[i])%a[i]==0 && (V-v[i])/a[i]*(V-v[i])/a[i]%2==0) x=d[i]+v[i]*(V-v[i])/a[i]-(V-v[i])/a[i]*(V-v[i])/a[i]/2+1;
//				else x=d[i]+ceil(v[i]*t-a[i]*t*t/2.0);
				if((V-v[i])*(v[i]+V)%(2*a[i])==0) x=d[i]+(V-v[i])*(v[i]+V)/(2*a[i])+1;
				else x=d[i]+ceil(v[i]*t+a[i]*t*t/2.0);
				if(x<=L) s[i].l=x,s[i].r=L;
				else s[i].l=s[i].r=L+1;
			}
			if(a[i]<0){
				if(v[i]<=V){
					s[i].l=s[i].r=L+1;
					continue;
				}
				
//				a[i]=-a[i];
//				double t=(v[i]-V)*1.0/a[i];
//				int x;
//				if((v[i]-V)*(v[i]+V)%(2*a[i])==0) x=d[i]+(v[i]-V)*(v[i]+V)/(2*a[i])-1;
//				else x=d[i]+floor(v[i]*t-a[i]*t*t/2.0);
				double t=(V-v[i])*1.0/a[i];
				int x;
				if((V-v[i])*(v[i]+V)%(2*a[i])==0) x=d[i]+(V-v[i])*(v[i]+V)/(2*a[i])-1;
				else x=d[i]+floor(v[i]*t+a[i]*t*t/2.0);
				s[i].l=d[i];
				s[i].r=min(L,x);
			}
//			cout<<s[i].l<<" "<<s[i].r<<"\n";
		}
		for(int i=1;i<=m;i++) cin>>p[i],st.insert(p[i]);
		for(int i=1;i<=n;i++){
			if(s[i].l>L) continue;
			auto it=st.lower_bound(s[i].l);
			if(it!=st.end() && *it<=s[i].r) ans1++;
			else s[i].l=s[i].r=L+1;
		}
		sort(s+1,s+1+n,cmp);
		int las=L+1;
		for(int i=1;i<=n;i++){
			if(s[i].l>L) continue;
			if(s[i].r<las){
				las=*st.lower_bound(s[i].l);
				ans2++;
			}
		}
		cout<<ans1<<" "<<m-ans2<<"\n";
	}
	return 0;
}
