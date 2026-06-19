#include<iostream>
#include<cstdio>
#define int long long 
using namespace std; 

int T;

int n, m, length, Vlimit;
int s0[100005], Vstart[100005], a[100005];
int test[100005]; 

void testcase(){
	cin >> n >> m >> length >> Vlimit;
	bool A = true;
	
	for (int i=0; i<n; i++){
		cin >> s0[i] >> Vstart[i] >> a[i];
		if (a[i] != 0) A = false; 
	}
	for (int i=0; i<m; i++){
		cin >> test[i];
	}
	
	if (A){
		int last_test_pos = test[m-1];
		int cnt = 0;
		for (int i=0; i<n; i++){
			if (Vstart[i] > Vlimit){	// 超速
				if (s0[i] <= last_test_pos)	// 会被查到
					cnt ++; 
			}
		}
		cout << cnt << ' ';
		if (cnt) cout << (m - 1);
		else cout << m;
	}
}

signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out","w",stdout);
	
	cin >> T;
	while (T --){
		testcase();
		cout << endl;
	} 
	
	return 0;
}
