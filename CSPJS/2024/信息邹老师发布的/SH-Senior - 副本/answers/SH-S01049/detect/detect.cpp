#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5,MAXM=1e5+5;
int T,n,m,L,V,d[MAXN],v[MAXN],a[MAXN],p[MAXM];
struct node{
	int l,r;
	bool operator<(const node&x)const{
		return r<x.r||(r==x.r&&l<x.l);
	}
}t[MAXN];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					int l=lower_bound(p+1,p+m+1,d[i])-p;
					if(m-l>=0){
						t[++cnt].l=l;
						t[cnt].r=m;
					}
				}
			}
			else{
				double x=(V*V-v[i]*v[i])/(2.0*a[i])+d[i];
				if(a[i]>0){
					int l=upper_bound(p+1,p+m+1,max(x,d[i]*1.0))-p;
					if(m-l>=0){
						t[++cnt].l=l;
						t[cnt].r=m;
					}
				}
				if(a[i]<0){
					int r=lower_bound(p+1,p+m+1,x)-p-1;
					int l=lower_bound(p+1,p+m+1,d[i])-p;
					if(r-l>=0){
						t[++cnt].l=l;
						t[cnt].r=r;
					}
				}
			}
		}
		cout<<cnt<<" ";
		sort(t+1,t+cnt+1);
		int now=t[1].r,ans=0,i=1;
		while(i<=cnt){
			if(t[i].r==now){
				ans++;
				while(i<=cnt&&t[i].l<=now&&t[i].r>=now){
					i++;
				}
			}
			now=t[i].r;
		}
		cout<<m-ans<<endl;
	} 
}

