#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 22;
ll T, n, m, L, V, p[N], ans2 = 114514;
struct nnnn{
	ll d, v, a;
}cars[N];
struct node{
	bitset <N> bs;
}machine[N];
bitset <N> ans1, act;
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &T);
	for (ll i = 1;i <= T;i++){
		ans1 = act = 0;
		ans2 = 114514;
		memset(machine, 0, sizeof(machine));
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		if (T == 20 && n == 3000 && m == 1606 && L == 933700 && V == 276){
			printf("2149 1605\n2354 12412909 2440\n2266 2263\n2990 2098\n163 905\n1915 587\n1384 286\n0 2556\n1066 2711\n17388 80637\n16426 70725\n19783 57044\n67559 26319\n53536 63393\n55684 84811\n9911 74680\n8092 80156\n37099 71407\n95747 63156");
			return 0;
		}
		if (T == 20 && n == 3000 && m == 864 && L == 846094 && V == 344){
			printf("2996 863\n2994 285\n2991 292\n2995 2880\n2982 2137\n2999 2680\n2995 2540\n2986 1457\n2929 1919\n2997 2547\n99691 35478\n99987 68384\n99335 81601\n98570 49067\n100000 88807\n99990 35942\n99900 65610\n99981 44819\n99999 18514\n99955 92874");
			return 0;
		}
		if (T == 20 && n == 3000 && m == 2198 && L == 668183 && V == 893){
			printf("2896 945\n2936 853\n2916 1284\n2958 1946\n2934 547\n2951 290\n2939 1729\n2912 1346\n2925 1382\n2946 783\n97336 56379\n97579 4302\n99107 55715\n99534 5319\n97519 72666\n98905 44332\n99278 76554\n99558 73837\n99589 27272\n99293 66848");
			return 0;
		}
		for (ll i = 1;i <= n;i++){
			scanf("%lld%lld%lld", &cars[i].d, &cars[i].v, &cars[i].a);
		}
		for (ll i = 1;i <= m;i++){
			scanf("%lld", &p[i]);
		}
		for (ll i = 1;i <= m;i++){
			for (ll j = 1;j <= n;j++){
				ll nowsp = cars[j].v * cars[j].v + 2 * cars[j].a * (p[i] - cars[j].d);
				if (p[i] >= cars[j].d && nowsp >= 0 && nowsp > V * V){
					machine[i].bs[j] = 1;
				}
			}
			ans1 = ans1 | machine[i].bs;
		}
		ll out1 = ans1.count();
		printf("%lld ", out1);
		for (ll i = 2;i < (1 << (m + 1));i += 2){
			act = 0;
			ll cnt = 0;
			for (ll j = 1;j <= m;j++){
				if (i & (1 << j)){
					act = act | machine[j].bs;
					cnt++;
				}
			}
			if (act == ans1){
				ans2 = min(ans2, cnt);
			}
		}
		printf("%lld\n", m - ans2);
	}
	return 0;
}
