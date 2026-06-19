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
#define N 100005
ll _,n,res;
pair<ll,ll> p[3];
vector<ll> vec[3];
#undef N
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_ = read();
	while(_--){
		res = 0;
		rep(i,0,2)vec[i].clear();
		n = read();
		rep(i,1,n){
			rep(j,0,2){
				p[j].first = read();
				p[j].second = j;
			}
			sort(p,p + 3);
			res += p[2].first;
			vec[p[2].second].push_back(p[2].first - p[1].first);
		}
		if(vec[2].size() > n / 2)swap(vec[2],vec[0]);
		if(vec[1].size() > n / 2)swap(vec[1],vec[0]);
		if(vec[0].size() <= n / 2){
			printf("%lld\n",res);
		}
		else{
			sort(vec[0].begin(),vec[0].end());
			rep(i,0,vec[0].size() - 1 - n / 2)res -= vec[0][i];
			printf("%lld\n",res);
		}
	}
	return 0;
} 
