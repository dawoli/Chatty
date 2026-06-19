#include<bits/stdc++.h>
using namespace std;
string s[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> s[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (s[i] == s[j] and i != j){
				n -= 1;
				s[j] = "0";
			}
		}
	}
	int ans = 52-n;
	cout << ans << endl;
	return 0;
}
