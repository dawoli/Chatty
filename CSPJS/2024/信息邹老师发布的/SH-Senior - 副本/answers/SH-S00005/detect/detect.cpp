#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,l,V,d[N],v[N],a[N],p[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int f[N],cnt,cnt1,maxn;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=i;i<=m;i++){
			cin>>p[i];
			f[p[i]]=1;
			maxn=max(maxn,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(v[i]<=V)continue;
			else{
				if(d[i]>maxn)continue;
				int x=lower_bound(p+1,p+n+1,d[i])-p;
				f[x]++;
				cnt1++;
			}
//			if(a[i]<0){
//				if(d[i]<V)continue;
//				else{
//					int x=d[i]-V;
//					double t=x/(a[i]*1.0);
//					double len=v[i]*t+0.5*a[i]*t*t+d[i];
//					for(int i=a[i];i<=(int)len+a[i];i++){
//						if(f[p[i]]){
//							f[p[i]]++;
//							cnt++; 
//							break;
//						}
//					}
//				} 
//			}
//			if(a[i]==0){
//				if(d[i]<=V)continue;
//				else{
//					for(int i=a[i];i<=l;i++){
//						if(f[p[i]]){
//							f[p[i]]++;
//							cnt++; 
//							break;
//						}
//					}
//				}
//			}
//			else{
//				if(d[i]>V){
//					for(int i=a[i];i<=l;i++){
//						if(f[p[i]]){
//							f[p[i]]++;
//							cnt++;
//							break;
//						}
//					}
//				}
//				else{
//					int x=V-d[i];
//					double t=x/(a[i]*1.0);
//					double len=v[i]*t+0.5*a[i]*t*t+d[i];
//					for(int i=a[i];i<=(int)len+a[i];i++){
//						if(f[p[i]]){
//							f[p[i]]++;
//							cnt++;
//							break;
//						}
//					}
//				}
//			}
		}
		for(int i=1;i<=m;i++){
			if(f[p[i]]==1)cnt1++;
		}
		cout<<cnt<<" "<<cnt1<<endl;
	}
	return 0; 
}
