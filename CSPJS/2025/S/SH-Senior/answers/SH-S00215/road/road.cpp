#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
typedef long long ll;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
#define M 1250425
#define N 10425
ll n,m,k,cnt,ncnt,cst[15],fa[N],res = 1e18,c,nres,res0,bad;
ll fi(ll x){
	return (x == fa[x]) ? x : fa[x] = fi(fa[x]); 
} 
struct node{
	ll u,v,w,l;
}rd[M],rd2[M];
bool cmp(node a,node b){
	return a.w < b.w;
}
#undef M
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read(); 
	ncnt = n;
	rep(j,1,n + k)fa[j] = j;
	rep(i,1,m){
		ll U = read(),V = read(),W = read();
		rd2[i] = {U,V,W,0}; 
	}
	sort(rd2 + 1,rd2 + m + 1,cmp);
	ll ltk = n;
	rep(i,1,m){
		ll U = fi(rd2[i].u),V = fi(rd2[i].v),W = rd2[i].w;
		if(U != V){
			--ltk;
			rd[++cnt] = rd2[i];
			fa[U] = V;
		}
		if(ltk == 1)break;
	}
	//可以把m从1e6降到1e4,原来初始不取的后面一定不取吗
	//如果初始不取，则有村改成城时，如果原来取了的边不取了那么一定是相当于这个边两个点连通了，还是轮不到原来不取的边 
	//复杂度O(2^k*(2nk+m))->O(2^k*k*n) 应该能80 
	rep(i,1,k){
		//n +k;
		cst[i] = read();
		rep(j,1,n)rd[++cnt] = {j,n + i,read(),1 << (i - 1)};
	}
	sort(rd + 1,rd + cnt + 1,cmp);
	rep(S,0,(1 << k) - 1){//2^k * nk 80pts
//		if(S | bad)continue;
		rep(j,1,n + k)fa[j] = j;
		ll lt = n,l2;
		nres = 0;
		rep(j,1,k){
			if((1 << (j - 1)) & S){
				nres += cst[j];
				++lt;
			}
		}
		l2 = lt;
		rep(i,1,cnt){
			if((S | rd[i].l) != S)continue;
			ll U = fi(rd[i].u),V = fi(rd[i].v),W = rd[i].w;
			if(U != V){
				--lt;
				nres += W;
				fa[U] = V;
			}
			if(lt == 1)break;
		}
		if(nres < res){
			c = S;
			res = nres; 
		}
		if(S == 0)res0 = nres;
//		if(l2 <= n + 1){
//			cout << nres << endl;
//			cout << "minus:" << res0 - nres << endl;
//			cout << S << endl;
//		}
	}
	cout << res <<endl;
//	cout << c << endl;
	return 0;
}

