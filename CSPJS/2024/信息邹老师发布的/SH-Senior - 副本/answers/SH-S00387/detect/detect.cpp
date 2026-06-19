#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,T,ans=0;
int p[100005];
struct car{
	int d,v,a;
	int overspeed;//从距离多少时达到V=3 
}a[100005]; 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			int dd,vv,aa;
			cin>>dd>>vv>>aa;
			a[i].d=dd;a[i].v=vv;a[i].a=aa;
			if(aa==0){
				if(vv>V) a[i].overspeed=dd;
				else a[i].overspeed=-1;
			}
			//if(a[i].overspeed>L) a[i].overspeed=0;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++){
			int os=a[i].overspeed;
			//cout<<os<<endl;
			if(os==-1){
				//ans++;
				continue;
			}
			if(a[i].a==0){
				if(p[m]>a[i].a && p[m]>=a[i].d) ans++;
			}
//			if(a[i].a>0){
//				for(int j=1;j<=m;j++){
//					if(os<=p[j] && a[i].d<=p[j]){
//						ans++;
//						//cout<<"DEBUG : "<<i<<' '<<os<<' '<<p[j]<<endl;
//						break;
//					}
//				}
//			}
//			if(a[i].a<0){
//				for(int j=1;j<=m;j++){
//					if(os<=p[j] && a[i].d>p[j]){
//						ans++;
//						//cout<<"DEBUG : "<<i<<' '<<os<<' '<<p[j]<<endl;
//						break;
//					}
//				}
//			}
		}
		cout<<ans<<' ';
		if(ans==0) cout<<m<<endl;
		else cout<<m-1<<endl;//我太难了 
	}
	return 0;
}
//1 5 5 15 3 0 3 0 12 4 0 1 1 4 5 5 -2 6 4 -4 2 5 8 9 15
