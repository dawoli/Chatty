#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::clog;
using std::endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=200009,M=1000009;
int a[N],n;
ll f[N][2];
/*
红色0蓝色1
前i个，第i个选某个颜色，算上对下一个的影响，最大值
*/
//单调栈
int q[4*N],nq;//队列内部元素
int lst[2*N];//队列中上一个元素
int hd[2*N],ed[2*N];
int rh,bh;
/*
0 红色队列
1~n 红色i头队列
n 蓝色队列
n+1~2n+1 蓝色i-N头队列
*/
int lsh[N];
ll ys[N];
void solve() {
	cin>>n;
	a[0]=a[n+1]=0,nq=0,rh=0,bh=n+1;
	for(int i=1; i<=n; i++) f[i][0]=f[i][1]=ys[i]=lsh[i]=0;
	for(int i=0; i<=2*n+5; i++) hd[i]=ed[i]=lst[i]=0;
	for(int i=0; i<=4*n+5; i++) q[i]=0;
	for(int i=1; i<=n; i++) cin>>a[i],lsh[i]=a[i];
	std::sort(lsh+1,lsh+1+n);
	int m=std::unique(lsh+1,lsh+1+n)-lsh-1;
	for(int i=1; i<=n; i++)  a[i]=std::lower_bound(lsh+1,lsh+1+m,a[i])-lsh;
	for(int i=1; i<=n; i++)
		if(a[i]==a[i-1]) ys[i]=ys[i-1]+lsh[a[i]];
		else ys[i]=ys[i-1];
//	for(int i=1; i<=n; i++) clog<<ys[i]<<' ';
//	clog<<endl;
	//从l到r一段颜色: ys[r]-ys[l]

	q[++nq]=0,f[0][0]=f[0][1]=0,hd[rh]=ed[rh]=hd[bh]=ed[bh]=nq;
	q[++nq]=n+1,f[n+1][0]=f[n+1][1]=-1e18;
	for(int i=1; i<=n; i++) hd[rh+i]=ed[rh+i]=hd[bh+i]=ed[bh+i]=nq;

	for(int i=1; i<=n; i++) {
		//红不考虑a[i+1]，考虑a[i+1]
		f[i][0]=std::max(f[q[hd[bh]]][1]+ys[i]-ys[q[hd[bh]]+1]
		                 ,f[q[hd[bh+a[i+1]]]][1]+ys[i]-ys[q[hd[bh+a[i+1]]]+1]+lsh[a[i+1]]);
		//蓝不考虑a[i+1]，考虑a[i+1]
		f[i][1]=std::max(f[q[hd[rh]]][0]+ys[i]-ys[q[hd[rh]]+1]
		                 ,f[q[hd[rh+a[i+1]]]][0]+ys[i]-ys[q[hd[rh+a[i+1]]]+1]+lsh[a[i+1]]);
//		clog<<hd[bh]<<' '<<q[hd[bh]]<<' '<<f[q[hd[bh]]][1]<<' '
//		    <<hd[bh+a[i+1]]<<' '<<q[hd[bh+a[i+1]]]<<' '<<f[q[hd[bh+a[i+1]]]][1]
//		    <<' '<<lsh[a[i+1]]<<' '<<i<<' '<<lsh[a[i]]<<endl;

		//处理普通红队
		while(hd[rh]<=ed[rh]&&f[q[ed[rh]]][0]+ys[i]-ys[q[ed[rh]]+1]<f[i][0]) ed[rh]=lst[ed[rh]];
		q[++nq]=i;
		if(hd[rh]>ed[rh]) hd[rh]=nq;
		lst[nq]=ed[rh],ed[rh]=nq;
		//处理普通蓝队
		while(hd[bh]<=ed[bh]&&f[q[ed[bh]]][1]+ys[i]-ys[q[ed[bh]]+1]<f[i][1]) ed[bh]=lst[ed[bh]];
		q[++nq]=i;
		if(hd[bh]>ed[bh]) hd[bh]=nq;
		lst[nq]=ed[bh],ed[bh]=nq;



		//处理a[i]红队
		while(hd[rh+a[i]]<=ed[rh+a[i]]&&f[q[ed[rh+a[i]]]][0]+ys[i]-ys[q[ed[rh+a[i]]]+1]<f[i][0])
			ed[rh+a[i]]=lst[ed[rh+a[i]]];
		q[++nq]=i;
		if(hd[rh+a[i]]>ed[rh+a[i]]) hd[rh+a[i]]=nq;
		lst[nq]=ed[rh+a[i]],ed[rh+a[i]]=nq;
		//处理a[i]蓝队
		while(hd[bh+a[i]]<=ed[bh+a[i]]&&f[q[ed[bh+a[i]]]][1]+ys[i]-ys[q[ed[bh+a[i]]]+1]<f[i][1])
			ed[bh+a[i]]=lst[ed[bh+a[i]]];
		q[++nq]=i;
		if(hd[bh+a[i]]>ed[bh+a[i]]) hd[bh+a[i]]=nq;
		lst[nq]=ed[bh+a[i]],ed[bh+a[i]]=nq;

//		clog<<f[i][0]<<' '<<f[i][1]<<endl;
	}
	cout<<std::max(f[n][0],f[n][1])<<'\n';
}
int main() {
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("F:\\CSP-S\\color\\color2.in","r",stdin);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	cout.flush();
	return 0;
}

