#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,w,d[100010],a,v[100010],cnt,p,mink=1000010;
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		cnt=0;
		scanf("%d%d%d%d",&n,&m,&l,&w);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&d[i],&v[i],&a);
		}
		for(int i=1;i<=m;i++) {
			scanf("%d",&p);
			mink=min(mink,p);
		}
		for(int i=1;i<=n;i++) {
			if(a==0) {
				if(v[i]>w and d[i]<mink) {
					cnt++;
				}
			}
		}
		cout<<cnt<<" ";
		if(cnt==0) cout<<m<<endl;
		else cout<<m-1<<endl;
	}
	return 0;
}
