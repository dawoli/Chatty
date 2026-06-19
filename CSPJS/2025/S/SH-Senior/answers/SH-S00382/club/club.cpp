#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >>t;
	long long ans=0;
	int n;
	long long x[100005];
	bool flg=0;
	long long ans2=0;
	for(int i=1; i<=t; ++i){
		cin >> n;
		for(int i=1; i<=n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		x[i]=a;
		if(b!=0 || c!=0) flg=1;
		ans+=max(max(a, b), max(b, c));
		//	cout << ans;
		}
		if(flg==0){
			sort(x+1, x+1+n);
			for(int i=n; i>n/2; i--){
				ans2+=x[i];
			}
			cout << ans2 << endl;
		} 
		else cout << ans << endl;
		ans=0;
	}
	return 0;
} 
