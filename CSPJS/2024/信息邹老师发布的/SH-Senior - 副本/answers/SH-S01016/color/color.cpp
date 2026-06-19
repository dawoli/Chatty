#include<bits/stdc++.h>
using namespace std;
int t,n;
struct sz {
	int num,col;
}a[1000010];
int squ(int x,int y) {
	int ret=1;
	for(int i=1;i<=y;i++) ret*=x;
	return ret;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++) {
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].num;
		for(int i=1;i<=squ(2,n);i++) {
			int p=i,c=0;
			for(int j=1;j<=n;j++) {
				a[j].col=p%2;
				p/=2;
			}
			for(int j=n;j>1;j--) {
				for(int l=j-1;l>=1;l--) {
					if(a[j].col!=a[l].col) continue;
					if(a[j].num!=a[l].num) continue;
					c+=a[j].num;break;
				}
			}
			if(c>ans) ans=c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
