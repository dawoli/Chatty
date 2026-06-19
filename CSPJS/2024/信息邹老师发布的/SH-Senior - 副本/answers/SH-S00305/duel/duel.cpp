#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,maxx;int x;
int val[100005];
//int num[100005];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	int pos = 0;
	for(int i = 1; i <= n; ++ i){
		cin >> x;
		if(x > maxx) maxx = x;
//		if(val[x] == 0){
//			num[++ pos] = x; 
//		}
		val[x] ++; 
	}
	// cout << val[1] << endl << val[2];
	// sort(num + 1, num + pos + 1); 
    int ans = 0; int st = maxx;
	for(int j = maxx; j >= 1; -- j){
		if(val[st] > val[j]){
		    val[st] -= val[j]; ans += val[j]; val[j] = 0;}
		else{
			ans += val[st];
			val[j] -= val[st];
			val[st] = 0;
			st = j;
		}
	}
    cout << n - ans;
} 
