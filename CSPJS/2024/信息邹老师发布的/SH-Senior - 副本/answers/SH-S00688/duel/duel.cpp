#include<bits/stdc++.h>
using namespace std;
int a[100010],n,cnt,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l = 1,r = 1;
	while (r<=n){
		if (a[r]>a[l]) l++;
		r++;
	}
	cout<<n-l+1;
	return 0;
}
