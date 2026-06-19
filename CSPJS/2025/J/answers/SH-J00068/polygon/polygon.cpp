#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],cnt[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n<=2){
		cout << 0;
		return 0;
	}
	sort(a+1,a+n+1);
	if (a[1]+a[2]>a[3]){
		ans++;
	}
	cout <<ans;
	return 0; 
}
