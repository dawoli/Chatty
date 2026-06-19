#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , k , kc[10009] , ok[10009] , ans , ansn , flag , num , strt , nlft , cnt , sum , id , fa[100050] , n1 , n2;
//vector<ll> to[10050] , w[10050];
struct node{
	ll u , v , w;
	bool operator<(const node&b)const{
		return w < b.w;
	}
} dp[1000009] , d1[1000009] , d2[1000009];
ll root(ll x){
	if(fa[x] == x) return x;
	else return fa[x] = root(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i = 1 , a , b , c; i <= m; i++){
		fa[i] = i;
		scanf("%lld %lld %lld",&a,&b,&c);
		dp[i]=(node){a,b,c};
	}
	sort(dp+1,dp+1+m);
	sum = n , id = 1;
	while(sum > 1){
		while(root(dp[id].u) == root(dp[id].v) && id <= m){
			id++; 
		}
		fa[root(dp[id].u)] = root(dp[id].v);
		sum--;
		num += dp[id].w;
		d1[++n1] = dp[id];
		id++;
	}
	ansn = n1;
	for(ll i = 1; i <= n1; i++) dp[i]=d1[i];
	ansn = n1;
	ans = num;
	num = 0 , strt = 0;
	for(ll i = 1 , c; i <= k; i++){
	 	scanf("%lld",&c);
	 	fa[i+n] = i+n , kc[i] = c ,strt += c , num = strt;
		for(ll j = 1 , a; j <= n; j++){
			fa[j] = j;
			scanf("%lld",&a);
			d1[++n1]=(node){i+n,j,a};
		}
		sort(d1+1,d1+1+n1);
//		for(ll j = 1; j <= n1; j++){
//			cout << d1[j].w << endl;
//		}
		sum = n, id = 1 , flag = 0;
		while(sum > 1){
			while(root(d1[id].u) == root(d1[id].v) && id <= n1){
				id++; 
			}
			if(id > n1) break;
			if(d1[id].u > n){
				if(root(d1[id].u) == root(d1[id].v)){
					id++;
					continue;
				} 
				if(fa[d1[id].u] != d1[id].u) sum--;
				fa[root(fa[d1[id].u])] = root(d1[id].v);
				num += d1[id].w;
				d2[++n2]=d1[id];
				ok[d1[id].u - n] = i;
			}
			else{
				fa[root(d1[id].v)] = fa[d1[id].u];
				sum--;
				num += d1[id].w;
				d2[++n2]=d1[id];
			}
			if(num > ans){
				break;
			}
			id++;
		}
		for(ll j = 1; j <= i; j++){
			if(ok[j] > -1 && ok[j] < i){
				num -= kc[j] , strt -= kc[j] , ok[j] = -1;
			}
			else if(ok[j] == i){
				fa[j+n] = j+n;
			}
		}
		//cout << num << endl;//lakkkkkaljewifwa
		if(num < ans){
			ans = num;
			ansn = n2;
			for(ll i = 1; i <= n2; i++) dp[i] = d2[i];
		}
		else{
			n2 = ansn;
			for(ll i = 1; i <= ansn; i++) d2[i] = dp[i];
		}
		n1 = 0;
		if(i == k) break;
		i++;
		scanf("%lld",&c);
		fa[i+n] = i+n , kc[i] = c ,strt += c , num = strt;
		for(ll j = 1; j <= n; j++){
			fa[j] = j;
			scanf("%lld",&c);
			d2[++n2]=(node){i+n,j,c};
		}
		sort(d2+1,d2+1+n2);
		sum = n , id = 1 , flag = 0;
		while(sum > 1){
			while(root(d2[id].u) == root(d2[id].v) && id <= n2){
				id++; 
			}
			if(id > n2) break;
			if(d2[id].u > n){
				if(root(d2[id].u) != d2[id].u) sum--;
				fa[root(d2[id].u)] = root(d2[id].v);
				num += d2[id].w;
				d1[++n1]=d2[id];
				ok[d2[id].u - n] = i;
			}
			else{
				fa[root(d2[id].v)] = fa[d2[id].u];
				sum--;
				num += d2[id].w;
				d1[++n1]=d2[id];
			}
			if(num > ans){
				break;
			}
			id++;
		}
		for(ll j = 1; j <= i; j++){
			if(ok[j] > -1 && ok[j] < i){
				num -= kc[j] , strt -= kc[j] , ok[j] = -1;
			}
			else if(ok[j] == i){
				fa[j+n] = j+n;
			}
		}
		//cout << num << endl;
		if(num < ans){
			ans = num;
			ansn = n1;
			for(ll i = 1; i <= n1; i++) dp[i]=d1[i];
		}
		else{
			n1 = ansn;
			for(ll i = 1; i <= ansn; i++) d1[i]=dp[i];
		}
		n2 = 0;
	}
	cout << ans << endl;
	return 0;
} 
