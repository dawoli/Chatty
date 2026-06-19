#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;
int t,n,ans;
int a[maxn],c[maxn];
bool b[maxn];

void count(int cur) {
	c[cur]=0;
	for (int i=cur-1;i>=1;i--) {
		if (b[i]==b[cur]) {
			if (a[i]==a[cur]) c[cur]=a[i];
			return;
		}
	}
}
void f(int cur) {
	//printf("f(%d) b[%d-1]=%d\n",cur,cur,b[cur-1]);
	if (cur>n) {
		int res=0;
		for (int i=1;i<=n;i++) res+=c[i];
		//printf("%d\n",res);
		if (res>ans) {
			ans=res;
		}
		return;
	}
	for (int i=0;i<=1;i++) {
		b[cur]=i;
	    count(cur); f(cur+1);
	}
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    scanf("%d",&t);
    while (t--) {
    	scanf("%d",&n); ans=0;
    	for (int i=1;i<=n;i++) {
    		scanf("%d",&a[i]); b[i]=0; c[i]=0;
		}
		f(1);
		printf("%d\n",ans);
	}
	return 0;
}
