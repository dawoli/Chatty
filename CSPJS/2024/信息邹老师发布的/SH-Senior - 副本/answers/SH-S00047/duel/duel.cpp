#include<bits/stdc++.h>
// #define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define repn(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int N=1e5+10;

int n,a[N],res;
multiset<int> s; // ¿É¹¥»÷µÄ¹ÖÊŞ 

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	
	rep(i,1,n) s.insert(a[i]);
	
	res=n;
	rep(i,1,n){
		auto it=s.upper_bound(a[i]);
		if(it!=s.end()){
			res--;
			s.erase(it);
		}
		else break;
	}
	
	cout<<res<<endl;

	return 0;
}

