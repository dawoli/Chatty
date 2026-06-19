#include<bits/stdc++.h>
using namespace std;
int n;
int r[10005];
bool b[100];
int ans,t;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans = n;
	r[0] = 1000000;
	for(int i = 1;i <= n;i++){
		cin >> r[i];
		if(r[i] > r[i - 1]){
			ans--;
		}
	}
	cout << ans;
	
	return 0;
}
