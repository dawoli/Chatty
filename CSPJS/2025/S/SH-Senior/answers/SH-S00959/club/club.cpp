#include<iostream>
#include<algorithm>
#include<random>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>*/
#include<cstring>
using namespace std;
/*template<typename Tp, typename _Cmp = std::less<Tp>>
class heap_2 {
	__gnu_pbds::tree<Tp,__gnu_pbds::null_type,_Cmp> mTree;
public:
	void push(const Tp& x) {
		mTree.insert(x);
	}
	Tp top() {
		return *mTree.begin();
	}
	Tp back() {
		auto it = mTree.end();
		it--;
		return *it;
	}
	void pop_back() {
		auto it = mTree.end();
		it--;
		mTree.erase(it);
	}
	void pop() {
		mTree.erase(mTree.begin());
	}
	int size() {
		return mTree.size();
	}
	void erase(const Tp& x) {
		mTree.erase(x);
	}
	void clear() {
		mTree.clear();
	}
};
template<typename _Container, typename _RandomAccessIterator>
void __generate_seedseq(const _Container& _M_v,
                        _RandomAccessIterator __begin,
                        _RandomAccessIterator __end) {
	typedef typename iterator_traits<_RandomAccessIterator>::value_type _Type;

	if (__begin == __end)
		return;

	std::fill(__begin, __end, _Type(0x8b8b8b8bu));

	const size_t __n = __end - __begin;
	const size_t __s = _M_v.size();
	const size_t __t = (__n >= 623) ? 11
	                   : (__n >=  68) ? 7
	                   : (__n >=  39) ? 5
	                   : (__n >=   7) ? 3
	                   : (__n - 1) / 2;
	const size_t __p = (__n - __t) / 2;
	const size_t __q = __p + __t;
	const size_t __m = std::max(size_t(__s + 1), __n);

	for (size_t __k = 0; __k < __m; ++__k) {
		_Type __arg = (__begin[__k % __n]
		               ^ __begin[(__k + __p) % __n]
		               ^ __begin[(__k - 1) % __n]);
		_Type __r1 = __arg ^ (__arg >> 27);
		__r1 = __detail::__mod<_Type,
		__detail::_Shift<_Type, 32>::__value>(1664525u * __r1);
		_Type __r2 = __r1;
		if (__k == 0)
			__r2 += __s;
		else if (__k <= __s)
			__r2 += __k % __n + _M_v[__k - 1];
		else
			__r2 += __k % __n;
		__r2 = __detail::__mod<_Type,
		__detail::_Shift<_Type, 32>::__value>(__r2);
		__begin[(__k + __p) % __n] += __r1;
		__begin[(__k + __q) % __n] += __r2;
		__begin[__k % __n] = __r2;
	}

	for (size_t __k = __m; __k < __m + __n; ++__k) {
		_Type __arg = (__begin[__k % __n]
		               + __begin[(__k + __p) % __n]
		               + __begin[(__k - 1) % __n]);
		_Type __r3 = __arg ^ (__arg >> 27);
		__r3 = __detail::__mod<_Type,
		__detail::_Shift<_Type, 32>::__value>(1566083941u * __r3);
		_Type __r4 = __r3 - __k % __n;
		__r4 = __detail::__mod<_Type,
		__detail::_Shift<_Type, 32>::__value>(__r4);
		__begin[(__k + __p) % __n] ^= __r3;
		__begin[(__k + __q) % __n] ^= __r4;
		__begin[__k % __n] = __r4;
	}
}
struct Status {
	unsigned a,b,c;
	bool operator==(const Status& x) const {
		return std::tie(a,b,c) == std::tie(a,b,c);
	}
};
namespace std {
	template<>
	struct hash<Status> {
		size_t operator()(const Status& x) const {
			std::array<unsigned,3> data {x.a,x.b,x.c};
			std::array<unsigned,2> arr;
			__generate_seedseq(data, arr.begin(),arr.end());
			return *(size_t*)arr.data();
		}
	};
}
static constexpr int N = 1e5+7;
int a[N][3];
int valid[N];
int ans;
unordered_map<Status,int> m;
struct cmpL {
	bool operator()(const Status& x, const Status& y) const {
		return m[x]<m[y];
	}
};
struct cmpG {
	bool operator()(const Status& x, const Status& y) const {
		return m[x]>m[y];
	}
};
heap_2<Status,cmpG> gh;
void _push(Status x,int v,int n) {
	if(n<valid[x.a+x.b+x.c]){
		return;
	}else valid[x.a+x.b+x.c]=n;
	if(gh.size() > n*6+3) {
		m.erase(gh.back());
		gh.pop_back();
	}
	if(m.find(x)==m.end()) {
		m[x]=v;
		gh.push(x);
	} else if(m[x]<v) {
		gh.erase(x);
		m[x]=v;
		gh.push(x);
	}
}
//overloaded
void solve(int n) {
	memset(valid,0,N*4);
	ans=0;
	m.clear();
	gh.clear();
	gh.push(Status {0,0,0});
	m[Status {0,0,0}] = 0;
	while(gh.size()) {
		auto s = gh.top();
		gh.pop();
		printf("%d %d %d %d\n",s.a,s.b,s.c,m[s]);
		int i = s.a+s.b+s.c;
		if(i==n) {
			ans=max(ans,m[s]);
		} else {
			if(i>n) continue;
			if(s.a+1<=n/2) _push(Status {s.a+1,s.b,s.c},m[s]+a[i][0],n);
			if(s.b+1<=n/2) _push(Status {s.a,s.b+1,s.c},m[s]+a[i][1],n);
			if(s.c+1<=n/2) _push(Status {s.a,s.b,s.c+1},m[s]+a[i][2],n);
		}
	}
}*/
static constexpr int N = 1e5+7;
int dp[120][120][120];
int ans;
int a[N*3/2][3];
void solve(int n){
	memset(dp,0,sizeof(dp));
	ans = 0;
	int limit = n/2;
	for(int i=0;i<=limit;i++){
		for(int j=0;j<=limit;j++){
			for(int k=0;k<=limit;k++){
				dp[i][j][k]=0;
				if(i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k-1][0]);
				if(j) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k-1][1]);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k-1][2]);
				if(i+j+k==n){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	for(int _=0; _<k; _++) {
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		solve(n);
		printf("%d\n",ans);
	}
	return 0;
}
