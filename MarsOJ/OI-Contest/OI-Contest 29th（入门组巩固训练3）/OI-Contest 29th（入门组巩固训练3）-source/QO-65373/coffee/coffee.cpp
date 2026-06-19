#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,x,ans,day[10]; 
string s; signed main(){
//	freopen("coffee.in","r",stdin);
//	freopen("coffee.out","w",stdout);
	cin >> T; while(T--){ 
		x = ans = 0;
		for(int i = 1;i <= 5;i++){
			cin >> s;
			for(int j = 1;j <= 7;j++){
				cin >> s;
				if(s == "math"){
					day[i] += 5; 
					x += 5;
				}
			}
		} cin >> n >> m;
		if(m != 1){
			while(m < 7){
				ans += day[m]; 
				m++; n--;
			}
		} ans += x * (n / 7);
		n %= 7;
		for(int i = 1;i <= n;i++){
			ans += day[i];
		} cout << ans << "\n";
	} return 0;
}
