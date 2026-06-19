#include<bits/stdc++.h>
using namespace std;
string h[55];
int n;
int ans;
bool c;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	c = true;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> h[n];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j < n;j++){
			if(h[i] == h[j]){
				n = n - 1;
			}
		}
	}
	
	ans = 52 - n;
	cout << ans;
	return 0;
}


