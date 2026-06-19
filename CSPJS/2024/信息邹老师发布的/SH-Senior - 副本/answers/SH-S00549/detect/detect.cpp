#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T;
int l[N],r[N],p[N];
bool cs[N];
struct car{
	int lq,rq;
}c[N];
void mem(int n,car *a){
	for(int i=1;i<=n;i++){
		a[i].lq=0;
		a[i].rq=0;
	}
}
bool cmp(car a,car b){
	return a.rq<b.rq||a.rq==b.rq&&a.lq<b.lq;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(cs,0,sizeof(cs));
		int n,m,L,V,ans1=0;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++){
			int d,v,a;
			cin>>d>>v>>a;
			if(v>V&&a>=0){
				l[j]=d;
				r[j]=L;
			}
			else if(v==V&&a>0){
				l[j]=min(L,d+1);
				r[j]=L;
			}
			else if(v<=V&&a<=0){
				l[j]=-1;
				r[j]=-1;
			}
			else if(v>V&&a<0){
				l[j]=d;
				double s=(double)(v*v-V*V)/(-2*a);
				int ns=floor(s);
				if(s==ns) r[j]=min(L,d+ns-1);
				else r[j]=min(L,d+ns);
			}
			else if(v<V&&a>0){
				double s=(double)(V*V-v*v)/(2*a);
				int ns=ceil(s);
				if(d+ns>L){
					l[j]=-1;
					r[j]=-1;
				}
				else{
					if(s==ns) {
						l[j]=d+ns+1;
						r[j]=L;
					}
					else{
						l[j]=d+ns;
						r[j]=L;
					}
					
				} 
			}
			//cout<<l[j]<<" "<<r[j]<<endl;
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
		}
		sort(p,p+m);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(l[j]==-1) continue;
			if(lower_bound(p,p+m,l[j])-p==m||*lower_bound(p,p+m,l[j])>r[j]) continue;
			c[cnt].lq=lower_bound(p,p+m,l[j])-p;
			c[cnt++].rq=upper_bound(p,p+m,r[j])-p-1;
			cs[j]=1;
			ans1++;
		}
		sort(c,c+cnt,cmp);
		int num=-1;
		int ans2=0;
		//for(int j=0;j<cnt;j++) cout<<c[j].lq<<" "<<c[j].rq<<endl;
		int j=0;
		while(j<cnt){
			while(c[j].lq<=num&&j<cnt) j++;
			if(j==cnt) break;
			ans2++;
			num=c[j].rq;
			//cout<<num<<endl;
		}
		//mem(cnt,c);
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	return 0;
} 
