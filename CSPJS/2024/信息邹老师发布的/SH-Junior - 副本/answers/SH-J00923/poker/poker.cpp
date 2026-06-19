#include <bits/stdc++.h>
using namespace std;
long long n;
set<string> ms;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		string t;
		cin >> t;
		if(ms.count(t) <= 0){
			ms.insert(t);
			ans ++;
		} 
	}
	cout << (52-ans);
	return 0;
}
