#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100009;
struct Node{
	int f, g; 
	bool operator< (const Node &qq) const{
	    return ((f < qq.f) || ((f == qq.f )&& (g < qq.g)));
	}
}pp[N];
ll d[N], v[N], a[N], p[N], f[N], g[N];
ll n, m, lmt, l, cnt, num;
int t;
void solve_mx_dec(ll x, ll y, ll z){
	ll tmp = (y * y - lmt * lmt - 1);
	tmp /= (2 * z); tmp += x; 
	pp[++num].g = (upper_bound(p + 1, p + m + 1, tmp) - p - 1);
	if(pp[num].g == m + 1) pp[num].g = m;
}
//void solve_mx_dec(ll x, ll y, ll z){
//	for(int i = m; i >= 1; i--){
//		if((y * y - 2 * z * (p[i] - x)) >= (lmt * lmt + 1)){
//			pp[++num].g = i; return;
//		}
//	}
//}
bool check_acc(ll x, ll y, ll z){
	if(x > p[m]) return 0;
	if((y * y + 2 * z * (p[m] - x)) >= (lmt * lmt + 1)) return 1;
	return 0;
}
bool check_dec(ll x, ll y, ll z){
	int k = lower_bound(p + 1, p + m + 1, x) - p;
	if(k == m + 1) return 0;
	if((y * y + 2 * z * (p[k] - x)) >= (lmt * lmt + 1)){
		solve_mx_dec(x, y, -z);
		pp[num].f = k; 
//		cout << 1 << endl;
		return 1;
	}
	return 0;
}
bool check_accdec(ll x, ll y, ll z, ll k){
	if(x > p[m]) return 1;
	if(x > p[k] && ((y * y + 2 * z * (p[m] - x)) >= (lmt * lmt + 1))) return 0;
	if((y * y + 2 * z * (p[k] - x)) >= (lmt * lmt + 1)) return 1;
	return 0;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detcet.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
    while(t--){
//    	bool flag = 0;
    	cnt = 0;
    	for(int i = 1; i <= num; i++)pp[i].f = 0, pp[i].g = 0;
    	num = 0;
    	cin >> n >> m >> l >> lmt;
    	for(int i = 1; i <= n; i++){
    		cin >> d[i] >> v[i] >> a[i];
		}
		for(int i = 1; i <= m; i++) cin >> p[i];
		for(int i = 1; i <= n; i++){
			if(a[i] >= 0){
				if(check_acc(d[i], v[i], a[i])) cnt++;
			}
			else{
				if(check_dec(d[i], v[i], a[i])) cnt++;
			}
		}
		cout << cnt << " ";
		if(cnt == 0){
			cout << m << endl;
			continue;
		}
		sort(pp + 1, pp + num + 1);
		int nmn, nmx, mxdec;
		ll ans = 0;
		nmn = pp[1].f, nmx = pp[1].g, mxdec = 1;
		for(int i = 2; i <= num; i++){
			if(pp[i].f > nmx){
				ans++;  mxdec = max(mxdec, nmx); nmx = pp[i].g, nmn = pp[i].f;
//				cout << i << endl;
//            if(i == num - 1) flag = 1;
			}
			else{
				nmn = max(nmn, pp[i].f);
				nmx = min(nmx, pp[i].g);
			}
		}
//		for(int i = 1; i <= num; i++) cout << pp[i].f << " " << pp[i].g << endl;
//		cout << num;
        if(num)ans++;
		mxdec = max(mxdec, nmx);
//		cout << mxdec;
		    for(int i = 1; i <= n; i++){
			    if(a[i] >= 0){
				if(!check_accdec(d[i], v[i], a[i], mxdec)){
					ans++; break; 
				}
		    }
		}	
		cout << m - ans << endl;
	} 
	return 0;
}

