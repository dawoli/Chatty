#include<bits/stdc++.h>
#define N 100009
using namespace std;
int T,n,m,L,V,d[N],v[N],a[N],p[N],ans1,ans2;
int in[N],out[N];
struct Car{
	int in,out;
} c[N];
bool cmp(Car a,Car b){
	return a.in<b.in||a.in==b.in&&a.out<b.out;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		ans1=0,ans2=m;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++){
			if(d[i]>p[m])continue;
			if(a[i]==0){
				if(v[i]>V){
					int l=1,r=m-1,res=m;
					while(l<=r){
						int mid=(l+r)/2;
						if(p[mid]<d[i])l=mid+1;
						else r=mid-1,res=mid;
					}
					ans1++;in[res]++;out[m+1]++;
					c[ans1].in=res;c[ans1].out=m+1;
//					cout<<i<<' '<<res<<' '<<m+1<<endl;
				}
			}else if(a[i]>0){
				if((2.0*a[i]*(p[m]-d[i])+v[i]*v[i])<=V*V)continue;
				int l=1,r=m-1,res=m;
				while(l<=r){
					int mid=(l+r)/2;
					if(d[i]>p[mid]||(2.0*a[i]*(p[mid]-d[i])+v[i]*v[i])<=V*V)l=mid+1;
					else r=mid-1,res=mid;
				}
				ans1++;in[res]++;out[m+1]++;
				c[ans1].in=res;c[ans1].out=m+1;
//				cout<<i<<' '<<res<<' '<<m+1<<endl;
			}else{
				if(v[i]<=V)continue;
				int l=1,r=m-1,res=m;
				while(l<=r){
					int mid=(l+r)/2;
					if(p[mid]<d[i])l=mid+1;
					else r=mid-1,res=mid;
				}
				if(v[i]*v[i]-V*V<=(p[res]-d[i])*(-2)*a[i])continue;
				if(v[i]*v[i]-V*V>(p[m]-d[i])*(-2)*a[i]){
					ans1++;in[res]++;out[m+1]++;
					c[ans1].in=res;c[ans1].out=m+1;
//					cout<<i<<' '<<res<<' '<<m+1<<endl;
					continue;
				}
				ans1++;in[res]++;
				c[ans1].in=res;
//				cout<<i<<' '<<res<<' ';
				l=res;r=m-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(v[i]*v[i]-V*V<=(p[mid]-d[i])*(-2)*a[i])r=mid-1;
					else l=mid+1,res=mid;
				}
				out[res+1]++;c[ans1].out=res+1;
//				cout<<res+1<<endl;
			}
		}
		sort(c+1,c+ans1+1,cmp);
		int i=1,l=1,r=0;
		for(;i<=m+1;i++){
			for(int j=r+1;j<=ans1;j++){
				if(c[j].in==i)r=j;
				else break;
			}
			if(in[i])break;
		}
		for(i++;i<=m+1;i++){
			if(out[i]){
				for(int j=l;j<=r;j++){
					out[c[j].out]--;
				}l=r+1;
				ans2--;
				for(;i<=m+1;i++){
					for(int j=r+1;j<=ans1;j++){
						if(c[j].in==i)r=j;
						else break;
					}
					if(in[i])break;
				}
			}
			for(int j=r+1;j<=ans1;j++){
				if(c[j].in==i)r=j;
				else break;
			}
		}
//		for(int i=1;i<=m+1;i++)cout<<in[i]?1:0;
//		cout<<endl;
//		for(int i=1;i<=m+1;i++)cout<<out[i]?1:0;
//		cout<<endl;
		cout<<ans1<<' '<<ans2<<endl;
	}
}
