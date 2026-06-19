#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,q = 1,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 2;i<=n*m;i++){
		cin >> s;
		if(s>k) q++;
	}
	t = q%n;
	if(t==0) t = n;
	cout << (q-1)/n+1 << ' ';
	if(((q-1)/n+1)%2==0) cout << n+1-t;
	else cout << t;
	return 0;
}
