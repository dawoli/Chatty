#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node {
	int l,r;
}A[100005];
inline bool cmp(Node x,Node y) {
	return x.r<y.r;
}
void read(ll &x) {
	x=0;
	bool flag=false;;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') {
		flag=true;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(flag) x=-x;
}
int T,N,M,maxp,cntA,dp[100005],ans;
ll L,V,d[100005],v[100005],a[100005],p[100005];
int pos1[1000005],pos2[1000005];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(;T;T--) {
		scanf("%d%d%d%d",&N,&M,&L,&V);
		ans=0,cntA=0,maxp=0;
		for(int i=1;i<=N;i++) {
			read(d[i]);
			read(v[i]);
			read(a[i]); 
		}
		for(int i=1;i<=M;i++) {
			read(p[i]);
			for(int j=p[i-1]+1;j<=p[i];j++) pos1[j]=i;
			for(int j=p[i-1];j<p[i];j++) pos2[j]=i-1;
		}
		pos1[0]=1;
		for(int i=p[M];i<=L;i++) pos2[i]=M;
		for(int i=1;i<=N;i++) {
			if(a[i]>=0&&2*a[i]*(p[M]-d[i])>V*V-v[i]*v[i]) {
				if(v[i]<=V) maxp=max(maxp,pos1[d[i]+(V*V-v[i]*v[i]+2*a[i])/(2*a[i])]);
				else maxp=max(maxp,pos1[d[i]]);
				ans++;
			}
			else if(a[i]<0&&2*a[i]*(p[pos1[d[i]]]-d[i])>V*V-v[i]*v[i]) {
				A[++cntA].l=pos1[d[i]];
				A[cntA].r=pos2[d[i]+(V*V-v[i]*v[i]+1)/(2*a[i])];
				ans++;
			}
		}
		if(maxp) {
			A[++cntA].l=maxp;
			A[cntA].r=M;
		}
		sort(A+1,A+cntA+1,cmp);
		dp[0]=0;
		queue<int> que;
		for(int j=1;j<=cntA;j++) {
			while(!que.empty()&&A[que.front()].r<A[j].l) {
				que.pop();
			}
			que.push(j);
			dp[j]=dp[que.front()-1]+1;
		}
		printf("%d %d\n",ans,M-dp[cntA]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
