#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;
int n, r[N], hd;

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> r[i];
	sort(r+1,r+n+1);
	hd = 1;
	for(int i = 1; i <= n; i++)
		if(i > hd && r[i] > r[hd])
			hd++;
	cout << n-hd+1 << endl;
}
