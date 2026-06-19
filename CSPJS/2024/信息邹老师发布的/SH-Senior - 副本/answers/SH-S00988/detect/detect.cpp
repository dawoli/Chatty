#include <bits/stdc++.h>
using namespace std;

int n , m , L , V;

long double cam[5009];
bool overspeed[5009];
int num[5009];
bool mp[5009][5009];
bool full[5009];

struct car{
	long double d , v , a;
	long double l , r;
}c[5009];

bool sped(car c , double cam){
	if(c.a < 0){
		double dis = -c.v * c.v / c.a / 2;
		if(cam >= c.d && cam <= c.d + dis){
			double sp2 = c.v * c.v + 2 * c.a * (cam - c.d);
			if(sp2 > V * V) return true;
			else return false;
		}
		else return false;
	}
	else if(c.a == 0){
		if(c.v > V && c.d < cam) return true;
		else return false;
	}
	else{
		if(cam < c.d) return false;
		double sp2 = c.v * c.v + 2 * c.a * (cam - c.d);
		if(sp2 > V * V) return true;
		else return false;
	}
}

void add(bool* a , bool* b){
	for(int i = 1 ; i <= m ; i ++){
		a[i] = a[i] | b[i];
	}
}

bool f(bool* a){
	for(int i = 1 ; i <= m ; i ++){
		if(!a[i] && overspeed[i]) return false;
	}
	return true;
}

int solve(){
	int ans = n;
	for(int i = 1 ; i <= pow(2 , m) ; i ++){
		memset(full , false , sizeof(full));
		for(int j = 1 ; j <= m ; j ++){
			int cnt = 0;
			if(int(pow(2 , j - 1)) & i){
				add(full , mp[j]);
				cnt ++;
			}
			if(f(full)) ans = min(ans , cnt);
		}
	}
	return ans;
}

int main(){
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int T;
	cin >> T;
	
	for(int e = 1 ; e <= T ; e ++){
		int cnt = 0 , cnt2 = 0;
		cin >> n >> m >> L >> V;
		memset(cam , 0 , sizeof(cam));
		memset(overspeed , false , sizeof(overspeed));
		
		for(int i = 1 ; i <= n ; i ++){
			cin >> c[i].d >> c[i].v >> c[i].a;
		}
		for(int i = 1 ; i <= m ; i ++){
			cin >> cam[i];
			bool used = false;
			for(int j = 1 ; j <= n ; j ++){
				if(sped(c[j] , cam[i]) == true){
					used = true;
					num[i] ++;
					mp[i][j] = true;
					if(!overspeed[j]){
						overspeed[j] = true;
						cnt2 ++;
					}
				}
			}
		}
		
		cout << cnt2 << " " << n - solve() << endl;
		
	}
	

	return 0;
}


