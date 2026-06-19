#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, l, V;
bool cnt[114514];
double lastover, overleave;
int lastm;
int ans1, ans2;
int z = 1;
struct car{
	int d, v, a;
	int drivetime = 1, speed;
	double drivedis = 0;
	double overpoint = 10000007;
	bool overspeed = false;
	int leavepoint = 10000007;
} c[114514];
stack<car> badcar;
car bad[114514];
bool cmp(car a, car b){
	return a.d < b.d;
}
inline bool checkover(car x){
	while(x.drivedis < l){
		x.speed = x.v + x.a * x.drivetime;
		x.drivedis = x.v * x.drivetime + 0.5 * x.a * x.drivetime * x.drivetime;
		if(sqrt(x.v * x.v + (2 * x.a * x.drivedis)) > V){
			x.overpoint = x.drivedis + x.d;
			lastover = max(lastover, x.overpoint);
			bad[z++] = x;
			return true;
			}
		x.drivetime++;
		}
	return false;
}
inline bool checkleave(car x){
	int left = x.d;
	while(true){
		x.speed = x.v + x.a * x.drivetime;
		x.drivedis = x.v * x.drivetime + 0.5 * x.a * x.drivetime * x.drivetime;
		for(int i = left; i <= x.drivedis; i++){
			if(cnt[i] == true){
				overleave = min(overleave, x.drivedis + x.d);
				
				return true;
			}
		}
		if(x.v * x.v + (2 * x.a * x.drivedis) <= 0 || sqrt(x.v * x.v + (2 * x.a * x.drivetime)) < V){
			return false;
		}
		x.drivetime++;
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> l >> V;
		for(int i = 1; i <= n; i++){
			cin >> c[i].d >> c[i].v >> c[i].a;
		}
		int num;
		for(int i = 1; i <= m; i++){
			cin >> num;
			cnt[num] = true;
			lastm = max(lastm, num);
		}
		for(int i = 1; i <= n; i++){
			if(c[i].a == 0 && c[i].d == 0 && c[i].v <= V){
				continue;
			}
			if(c[i].v > V && c[i].a >= 0 && c[i].d < lastm){
				ans1++;
				bad[z++] = c[i];
				lastover = max(lastover, double(c[i].d));
			}
			if(!(c[i].a <= 0)){
				if(checkover(c[i]) == true){
					ans1++;
				}
			}
			else if(c[i].a < 0 && c[i].v > V){
				if(checkleave(c[i]) == true){
					ans1++;
				}
			}
		}
		int j = 0;
		sort(bad+1, bad+z+1, cmp);
		for(int i = 1; i <= z; i++){

		}
		int rt = 1919810, lt = 0;
		int outen = 1;
		for(int i = 1; i <= z; i++){
			rt = min(rt, min(bad[i].leavepoint, int(bad[i].overpoint)));
			lt = bad[i].d;
			if(lt >= rt){
				for(j = rt; cnt[j] = false; j--){
					
				}
				for(; bad[outen].d <= j; outen++){
					
				}
				ans2++;
				lt = bad[outen].d;
				rt = bad[outen].leavepoint;
				i = outen;
			}
		}
	}
	cout << ans1 << " " << m-ans2-1;
	return 0;
}
