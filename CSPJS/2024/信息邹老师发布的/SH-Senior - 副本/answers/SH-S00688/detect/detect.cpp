#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,d[3010],v[3010],a[3010],p[3010],t[3010];
int bs(long double x){
	int l = 1,r = m;
	if (x>p[m]) return m+1;
	while (l<r){
		int mid=l+r>>1;
		if (p[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while (T--){
		int cnt=0;
		cin>>n>>m>>L>>V;
		for (int i = 1; i <= n; i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for (int i = 1; i <= m; i++){
			cin>>p[i];
		}
		for (int i = 1; i <= n; i++){
			if (a[i]>0||v[i]>V){
				long double l=d[i],r=L;
				if (a[i]>0){
					l=max(l,d[i]+(long double)(V*V-v[i]*v[i])/(2*a[i]));
					//if (l>p[m]&&T==1) cout<<d[i]<<" "<<v[i]<<" "<<a[i]<<" "<<i<<" "<<l<<"\n";
					if (v[i]>V) cnt+=(l<=p[m]);
					else cnt+=(l<p[m]);
				}
				else if (a[i]==0){
					cnt+=(d[i]<=p[m]);
				}
				else {
					r=d[i]+(long double)(V*V-v[i]*v[i])/(2*a[i]);
					int x=bs(r);
					//cout<<r<<" "<<x<<"\n";
					cnt+=(p[x-1]>=l);
				}
			}
		}
		cout<<cnt<<" "<<n-cnt<<"\n";
	}
	return 0;
}
/*

*/
