#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,m,k,b[100001],c[1000001],maxn=-1;
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> n >> m >> k;
		int a[n+1][k+1];
		for (int j=1;j<=n;j++){
			int x;
			cin >> x;
			for (int k=1;k<=x;i++){
				cin >> a[j][k];
				maxn = max(maxn,a[j][k]);
			}
		}
		for (int j=1;j<=k;k++){
			cin >> b[i] >> c[i]; 
		}
		for (int i=1;i<=k;i++){
			if (c[i] >= maxn){
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
	}
	return 0;
} 
