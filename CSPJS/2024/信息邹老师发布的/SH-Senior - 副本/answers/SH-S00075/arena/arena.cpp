#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
const int M=1e5+5;
int n,m,a[N],q[M],Log2[N],x[4],ans[M],r[M];
bool d[22][22],B=true;
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n<<1;i++) Log2[i]=Log2[i>>1]+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>q[i];
	sort(q+1,q+n+1);
	for(int i=1;i<=m;i++) r[i]=Log2[q[i]]+(1<<Log2[q[i]]!=n);
	int p=Log2[n]+(1<<Log2[n]!=n);
	for(int i=1;i<=p;i++)for(int j=1;j<=1<<(p-i);j++) {
		char ch; cin>>ch;
		d[i][j]=ch^48;
		if(d[i][j]) B=false;
	}
	int t; cin>>t;
	if(B) {
		while(t--) {
			for(int i=0;i<4;i++) cin>>x[i];
			for(int i=1,z=1;i<=n;i++) {
				int ai=(a[i]^=x[i%4]);
				while(z<=m) {
					int k=r[z];
					if(ai>k) ans[z++]=i;
					else break;
				}
			}
			int A=ans[1];
			for(int i=2;i<=m;i++) A^=i*ans[i];
			cout<<A<<endl;
		}
	}
	return 0;
}
