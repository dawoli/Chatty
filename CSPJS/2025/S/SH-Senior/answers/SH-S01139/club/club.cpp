#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lgn = 1e5+10;

struct node{
	ll a, b, c, d, e, f;
}sat[lgn];
ll ncnt[3] = {0};

inline ll maxabc(int a, int b, int c){
	return max(max(a,b),c);
}
inline ll medabc(int a, int b, int c){
	return a+b+c-max(max(a,b),c)-min(min(a,b),c);
}
inline ll minabc(int a, int b, int c){
	return min(min(a,b),c);
}

bool cmp(node A, node B){
	if (A.a != B.a)	return A.a > B.a;
	else if (A.b != B.a) return A.b > B.b;
	return A.c > B.c;
}

bool cmp2(node A, node B){
	return A.a > B.a;
}

/*bool cmp2(node A, node B){
	if (A.a == B.a) return A.b > B.b;
	return 0;
}
bool cmp3(node A, node B){
	if (A.a == B.a && A.b == B.b) return A.c > B.c;
	return 0;
}*/

ll solve(ll n){
	ll maxn = n / 2;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if(ncnt[sat[i].d] < maxn){
			ans += sat[i].a;
			ncnt[sat[i].d] += 1;
		}
		else if(ncnt[sat[i].e] < maxn){
			ans += sat[i].b;
			ncnt[sat[i].e] += 1;
		}
		else{
			ans += sat[i].c;
			ncnt[sat[i].f] += 1;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	ll n;
	cin >> t;
	for (int i = 1; i <= t; i++){
		memset(sat, 0, sizeof(sat));
		memset(ncnt, 0, sizeof(ncnt));
		cin >> n;
		int etrange = 0;
		for (int j = 1; j <= n; j++){
			int x, y, z;
			cin >> sat[j].a >> sat[j].b >> sat[j].c;
			if (sat[j].b == 0 && sat[j].c == 0){
				etrange += 1;
			}
			x = maxabc(sat[j].a, sat[j].b, sat[j].c);
			y = medabc(sat[j].a, sat[j].b, sat[j].c);
			z = minabc(sat[j].a, sat[j].b, sat[j].c);
			if (x == sat[j].a){
				sat[j].d = 1; 
				if (y == sat[j].b) {
					sat[j].e = 2;
					sat[j].f = 3;
				}
				else {
					sat[j].e = 3;
					sat[j].f = 2;
				}
			}
			else if (x == sat[j].b){
				sat[j].d = 2; 
				if (y == sat[j].a) {
					sat[j].e = 1;
					sat[j].f = 3;
				}
				else {
					sat[j].e = 3;
					sat[j].f = 1;
				}
			}
			else {
				sat[j].d = 3; 
				if (y == sat[j].a) {
					sat[j].e = 1;
					sat[j].f = 2;
				}
				else {
					sat[j].e = 2;
					sat[j].f = 1;
				}
			}
			sat[j].a = x;
			sat[j].b = y;
			sat[j].c = z;
		}
		if (etrange >= 100){
			ll ans = 0;
			sort(sat+1, sat+1+n, cmp2);
			for (int k = 1; k <= n / 2; k++){
				ans += sat[k].a;
			}
			cout << ans << endl;
			memset(sat,0,sizeof(sat));
			continue;
		}
		sort(sat+1, sat+1+n, cmp);
		/*sort(sat+1, sat+1+n, cmp2);
		sort(sat+1, sat+1+n, cmp3);*/
		//for (int j = 1; j <= n; j++) cout << n << "   "<< sat[j].a << " "<< sat[j].b << " "<< sat[j].c<< "   ";
		ll ans = solve(n);
		cout << ans << endl;
	}
	return 0;
}
