#include <bits/stdc++.h>
using namespace std;

const int chg[10]={6,2,5,5,4,5,6,3,7,6};
const int chsnum[6]={1,7,4,2,0,8},maxn=50010;
const int intmax=INT_MAX;
int t,n,minsiz;
int st[maxn],res[maxn],ans[maxn];

int p(int tmp) { // result->number
	if (tmp==6) return 0;
	if (tmp==2) return 1;
	if (tmp==5) return 2;
	if (tmp==4) return 4;
	if (tmp==3) return 7;
	if (tmp==7) return 8;
	return -1;
}
/*void debug(int siz) {
	printf("get res=");
	for (int i=0;i<siz;i++) printf("%d",res[i]); puts("");
}*/
void f(int num,int depth,int canchs) {
	//printf("f(%d)\n",num);
	if (depth>minsiz) return;
	if (num<=7) {
		const int siz=depth+1; st[depth]=p(num);
		if (siz>minsiz) return;
		for (int i=0;i<siz;i++) res[i]=st[i];
		sort(res,res+siz);
		if (res[0]==-1) return;
		if (res[depth]==0) res[depth]=6;
		for (int i=0;i<siz;i++) {
			if (res[i]!=0) {
				swap(res[0],res[i]); break;
			}
		}
		
		if (siz<minsiz) {for (int i=0;i<siz;i++){ans[i]=res[i];} minsiz=siz; return;}
		for (int i=0;i<siz;i++) {
			if (ans[i]<res[i]) return;
			else if (ans[i]>res[i]) {for (int i=0;i<siz;i++){ans[i]=res[i];} minsiz=siz; return;}
		}
		return;
	}
	for (int i=canchs;i>=0;i--) {
		st[depth]=chsnum[i];
		f(num-chg[chsnum[i]],depth+1,i);
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n); minsiz=intmax;
		if (n%7==0&&n>=7) {
			for (int i=1;i<=n/7;i++) printf("8");
			puts("");
		} else if (n%7==1&&n>=8) {
			printf("10");
			for (int i=1;i<=n/7-1;i++) printf("8");
			puts("");
		} else {
			f(n,0,5);
			if (minsiz!=intmax) {for (int i=0;i<minsiz;i++){printf("%d",ans[i]);}puts("");}
			else puts("-1");
		}
	}
	return 0;
}
