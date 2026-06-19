#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=150007;
ll T,n,m,a[N],b[N],q[N][4],ans,c[N],nowC,ok[N],qwq[N],flA=1,flB=1,P,SUM,diff[N],ANS[N];
int A[20][N],B[20][N];
char s[20][N];
vector<ll> vec,tmp;
void build(ll l,ll r){
	if (l==r){
		A[0][l]=(1<<P)+1;B[0][l]=l;return;
	}
	ll mid=l+r>>1,R=qwq[r-l+1];
	build(l,mid);build(mid+1,r);
	if (s[R][l/(1<<R)]=='0'){
		int tmp=B[R-1][l];
		for (int i=l;i<=mid;++i){
			if (a[i]>=R) A[R][i]=A[R-1][i];
			else{A[R][i]=min(A[R-1][i],i);tmp=max(tmp,A[R-1][i]);}
		}
		for (int i=mid+1;i<=r;++i) A[R][i]=min(A[R-1][i],tmp);
		B[R][l]=max(B[R-1][l],min(tmp,B[R-1][mid+1]));
	}
	else{
		int tmp=B[R-1][mid+1];
		for (int i=mid+1;i<=r;++i){
			if (a[i]>=R) A[R][i]=A[R-1][i];
			else{A[R][i]=min(A[R-1][i],i);tmp=max(tmp,A[R-1][i]);}
		}
		for (int i=l;i<=mid;++i) A[R][i]=min(A[R-1][i],tmp);
		B[R][l]=max(B[R-1][mid+1],min(tmp,B[R-1][l]));
	}
}
void solve(ll cid){
	for (int i=1;i<=n;++i) a[i]^=q[cid][i%4];
	build(1,1<<P);
//	for (int i=0;i<=P;++i) for (int j=1;j<=(1<<P);++j) cout<<A[i][j]<<(" \n"[j==(1<<P)]);
	memset(diff,0,sizeof(diff));
	for (int S=1<<P;S;S>>=1){
		int R=qwq[S];
		ANS[S]=0;
		for (int i=1;i<=S;++i){
			--A[R][i];
			if (A[R][i]>=S) ANS[S]+=i;
			else if (A[R][i]>(S>>1)) diff[A[R][i]]+=i;
		}
		for (int i=S-1;i>(S>>1);--i) ANS[i]=ANS[i+1]+diff[i];
	}
//	for (int i=1;i<=(1<<P);++i) cout<<diff[i]<<' ';cout<<endl;
//	for (int i=1;i<=(1<<P);++i) cout<<ANS[i]<<' ';cout<<endl;
	ans=0;
	for (int i=1;i<=m;++i) ans^=i*ANS[c[i]];
	cout<<ans<<endl;
	for (int i=1;i<=n;++i) a[i]^=q[cid][i%4];
}
void dfsBF(ll l,ll r){
	if (l==r){
		ok[l]=1;
		return;
	}
	if (l>nowC){
		for (int i=l;i<=r;++i) ok[i]=1;return;
	}
	ll R=qwq[r-l+1],mid=l+r>>1;
	dfsBF(l,mid);dfsBF(mid+1,r);
	if (s[R][l/(1<<R)]=='0'){
		bool fl=0;
		for (int i=l;i<=mid;++i) if (ok[i]){
			ok[i]=(i>nowC||a[i]>=R);
			if (i>nowC||a[i]<R) fl=1;
		}
		if (!fl) for (int i=mid+1;i<=r;++i) ok[i]=0;
	}
	else{
		bool fl=0;
		for (int i=mid+1;i<=r;++i) if (ok[i]){
			ok[i]=(i>nowC||a[i]>=R);
			if (i>nowC||a[i]<R) fl=1;
		}
		if (!fl) for (int i=l;i<=mid;++i) ok[i]=0;
	}
}
ll dfsA(ll l,ll r){
	if (l==r) return l;
	ll mid=l+r>>1;
	ll pl=dfsA(l,mid),pr=dfsA(mid+1,r),R=qwq[r-l+1];
	if (s[R][l/(1<<R)]=='0') return (a[pl]>=R?pl:pr);
	else return (a[pr]>=R?pr:pl);
}
pair<ll,ll> dfsB(ll l,ll r){
	if (r<=nowC) return make_pair(0,dfsA(l,r));
	if (l>nowC) return make_pair(1,(r-l+1)*(l+r)/2);
	ll mid=l+r>>1,R=qwq[r-l+1];
	pair<ll,ll> pl=dfsB(l,mid),pr=dfsB(mid+1,r);
	if (pl.first==1) return make_pair(1,pl.second+pr.second);
	return (a[pl.second]>=R?pl:pr);
}
void solveBF(){
	for (int i=1;i<=n;++i) a[i]^=q[1][i%4];
	for (int i=1;i<=m;++i){
		if ((c[i]&c[i]-1)==0){
			ans^=dfsA(1,c[i])*i;
			continue;
		}
		nowC=c[i];
		ll p=1,sum=0;
		while(p<nowC) p<<=1;
		dfsBF(1,p);
		for (int j=1;j<=p;++j) if (ok[j]) sum+=j;
		ans^=sum*i;
	}
	cout<<ans<<endl;
}
void solveB(){
//	cout<<"B\n";
	for (int i=1;i<=n;++i) a[i]^=q[1][i%4];
	for (int i=1;i<=m;++i){
		nowC=c[i];
		ll p=1;
		while(p<nowC) p<<=1;
		ans^=dfsB(1,p).second*i;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for (int i=2;i<N;i<<=1) qwq[i]=qwq[i>>1]+1;
	cin>>n>>m;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=m;++i) {cin>>c[i];flA&=((c[i]&c[i]-1)==0);}
	for (P=1;;++P){
		cin>>s[P];
		if ((1<<P)>=n) break;
	}
	for (int i=1;i<=P;++i) for (int j=0;j<(1<<P-i);++j) flB&=(s[i][j]=='0');
	cin>>T;
	for (int i=1;i<=T;++i) cin>>q[i][0]>>q[i][1]>>q[i][2]>>q[i][3];
	if (T==1&&flB){solveB();return 0;}
	if (T==1&&(n<=5000||flA)){solveBF();return 0;}
	for (int i=1;i<=T;++i) solve(i);
	return 0;
}
