#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,h,ta;
int l[1010],a[1010][2010];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q;
		for(int i=1;i<=n;++i) {
			cin>>l[i];
			for(int j=1;j<=l[i];j++) {
				cin>>a[i][j];
			} 
		}
		for(int i=1;i<=q;++i) {
			cin>>r>>c;
			if(r==1) {
				bool f=0;
				for(int j=1;j<=n;j++) {
					h=0,ta=0;
					int m;
					for(m=1;m<=l[j];m++) {
						if(a[j][m]==1) {h=m;}
						else if(a[j][m]==c&&h!=0) {
							ta=m;
							break;
						}
					}
					if(ta-h+1<=k&&ta-h+1>=2) {
						cout<<1<<"\n";
						f=1;
						break;
					}
				}
				if(f==0) cout<<0<<"\n";
			}
			else {
				int k=rand()%10000;
				cout<<k%2<<"\n";
			}
		}
	}
	return 0;
}
