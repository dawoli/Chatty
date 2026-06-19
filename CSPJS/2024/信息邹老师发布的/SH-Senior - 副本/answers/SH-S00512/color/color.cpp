//20 pts
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

inline int read() {
	char c=getchar(); int v=0,f=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (;isdigit(c);c=getchar()) v=v*10+c-48;
	return v*f;
}

#define r(a) a=read()

int T;
int n,ans,now;
int a[200005];
int col1[200005],col0[200005];
bool col[200005];

signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	r(T);
	while (T--) {
		ans=now=0;
		r(n);
		for (int i=1;i<=n;i++) r(a[i]);
		for (int _=0;_<(1<<n);_++) {
			now=0;
			for (int i=1;i<=n;i++) {
				col[i]=_&(1<<(i-1));
			}
			for (int i=1;i<=n;i++) {
				if (col[i]) col1[i]=a[i],col0[i]=col0[i-1];
				else col1[i]=col1[i-1],col0[i]=a[i];
			}
			for (int i=1;i<=n;i++) {
				if (col[i]) now+=(a[i]==col1[i-1]?a[i]:0);
				if (!col[i]) now+=(a[i]==col0[i-1]?a[i]:0);
			}
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}

