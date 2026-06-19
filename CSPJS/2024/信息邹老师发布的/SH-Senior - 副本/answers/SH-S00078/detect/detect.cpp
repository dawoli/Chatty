#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,m,L,V,d[N],v[N],a[N],p[N];
struct znc{
	int f,e;
} c[N];
bool OK(int f,int e){
	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)/2;
		if(p[mid]>e) r=mid-1;
		else if(p[mid]<f) l=mid+1;
		else return 1;
	}
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int dy=0,xy=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]>0){
				if(V>=v[i]){
					c[i].f=d[i]+(V*V-v[i]*v[i]+2*a[i]-1)/(2*a[i]);
					c[i].e=L;
				}
				else{
					c[i].f=d[i]; 
					c[i].e=L;
				}
				dy++;
			}
			else if(a[i]==0){
				if(v[i]<=V){
					c[i].f=-1;
					c[i].e=-1;
					continue;
				}
				else{
					c[i].f=d[i];
					c[i].e=L;
				}
				dy++;
			}
			else{
				if(V>=v[i]){
					c[i].f=-1;
					c[i].e=-1;
					continue;
				}
				else{
					c[i].e=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
					c[i].f=d[i];
				}
				xy++;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			//rp[p[i]]=1;
		}
		int ans=0,ansx=0,ansd=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(!OK(c[i].f,c[i].e)) continue;
			if(a[i]<0) ansx++;
			else ansd++;
			//r[c[i].f]++;
			//r[c[i].e]--;
		}
		/*for(int i=0;i<=L;i++){
			
		}*/
		ans=ansx+ansd;
		if(dy==n){
			if(ans>0) cout<<ans<<" "<<m-1<<endl;
			else cout<<m<<endl;
		}
		else cout<<ans<<" "<<ans<<endl; 
	}
	return 0;
}
