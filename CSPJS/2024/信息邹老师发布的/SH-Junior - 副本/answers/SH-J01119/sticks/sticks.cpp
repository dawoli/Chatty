#include<bits/stdc++.h>
using namespace std;
int t,n,num[10] = {6,2,5,5,4,5,6,3,7,6},al,ans[52];
bool ch(int r){
	bool f = false;
	while (r > 0){
		int x = r%10;
		r /= 10;
		al += num[x];
	}
	if (al == n){
		return true;
	}
	else {
		return false;
	}
}
int main(){
	freopen("sticks.in ","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> n; 
		if (n < 2){
			ans[i] = -1;
			continue;
		}
		long long sum=1;
		while (true){
			al = 0;
			if (ch(sum)){
				ans[i] = sum;
				break;
			}
			sum++;
		}
	}
	for (int i=1;i<=t;i++){
		cout << ans[i] << endl;
	}
	return 0;	
}
