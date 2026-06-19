#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 + 9;

int T, n, A[maxn], c[maxn], ans; 
bool color[maxn];// 0red 1blue

void cal(){
	int C = 0;
	c[1] = 0;
	for(int i = 2; i <= n; i++){
		bool flag = false;
		for(int j = i - 1; j >= 1; j--){
			if(color[i] == color[j]){
				flag = true;
				if(A[i] == A[j]){
					c[i] = A[i];
				}
				else{
					c[i] = 0;
				}
				//cout << c[i] << "* ";
			}
		}
		if(flag == false){
			c[i] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		C += c[i];
		//cout << c[i] << " " << C << endl;
	}
	ans = max(ans, C);
}

void col(){
	for(int i = 1; i <= n; i++){
		//cout << i << ":";
		color[i] = true;
		cal();
		color[i] = false;
	}
}

signed main(){
	
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> n;
		for(int j = 1; j <= n; j++){
			cin >> A[j];
		}
		ans = 0;
		col();
		cout << ans << endl;
	}
	
}
