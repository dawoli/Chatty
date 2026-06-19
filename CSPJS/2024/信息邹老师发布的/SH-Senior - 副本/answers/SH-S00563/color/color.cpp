#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200009;
int T,n,a[maxn],col[maxn],len;
ll ans,f[maxn];
void init() {
	ans=0,len=1;
	memset(f,0,sizeof(f));
	memset(col,0,sizeof(col));
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) {
		init();
		scanf("%d%d",&n,&a[1]);
		for(int i=2,x; i<=n; i++) {
			scanf("%d",&x);
			if(x==a[len]) ans+=x;
			else a[++len]=x;
		}
		for(int i=1; i<=len; i++) {
			f[i]=f[i-1];
			for(int j=i-1; j>=1; j--) {
				if(a[i]==a[j]) {
					if(f[j]+a[i]>f[i]) {
						f[i]=f[j]+a[i];
						col[i]=col[j]=1;
					}
					break;
				}
			}
		}
		int lst=-1;
		for(int i=1; i<=len; i++) {
			if(!col[i]) {
				if(lst==a[i]) ans+=a[i];
				lst=a[i];
			}
		}
		printf("%lld\n",ans+f[len]);
	}
	return 0;
}

