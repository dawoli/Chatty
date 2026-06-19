#include <bits/stdc++.h>
using namespace std;
int n, a[100005], cnt[100005], d[100005], ans, fi = 1;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1, a+n+1);
	for(int i = 2;i <= n;i++){
		if(a[fi] != a[i]){
			ans++;
			fi++;
		}
	}
	cout<<n-ans;
	return 0;
}
