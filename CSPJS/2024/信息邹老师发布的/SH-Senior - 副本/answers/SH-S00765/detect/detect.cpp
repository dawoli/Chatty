#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,V;
int ans1,ans2;
int d[3003],v[3003],a[3003],p[3003];
bool cs[3003][3003];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(cs,0,sizeof(cs));
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) 
			cin>>p[i];
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				int s=p[i]-d[j];
				if(sqrt(v[i]+2*a[i]*s)>V) {
					ans1++;
					cs[i][j]=1;
					if(cs[i-1][j]==0) ans2++;
 				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
