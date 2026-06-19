#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long n, r[N], cnt, ans;
bool flag[N];
long long lt, rt;
long long pre, idx;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);  
	cin>> n;
	ans = 0;
	for(int i = 1; i<= n; i++){
		cin>> r[i];
		//if(r[i] == 2) ++cnt;
	}
	sort(r + 1, r + n + 1);
	lt = rt = 1;
	while(rt <= n){
		while(r[rt] <= r[lt]){
			rt++;
		}
		flag[lt] = 1;
		lt += 1; rt += 1;
	}
	for(int i = 1; i<= n; i++){
		if(flag[i] == 0) ans++;
	}
	
	cout<< ans;
	return 0;
} 
