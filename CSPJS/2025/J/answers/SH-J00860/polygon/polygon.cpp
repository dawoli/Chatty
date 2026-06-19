#include<bits/stdc++.h> 
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n <= 2){
		cout << "0";
	}if(n==3){
		int maxn = max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3] > 2 * maxn){
			cout << "1";
			return 0;
		}else{
			cout << "0";
			return 0;
		}
	}
	return 0;
}
