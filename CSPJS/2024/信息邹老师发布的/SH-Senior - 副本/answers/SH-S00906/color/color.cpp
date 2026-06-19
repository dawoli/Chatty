#include<bits/stdc++.h>
using namespace std;
int t,n[1005],a[1005][100005],ans[105];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n[i];
		for(int j = 1;j <= n[i];j++){
			cin >> a[i][j];
		}
		for(int j = 1;j <= n[i];j++){
			for(int k = j + 1;k <= n[i];k++){
				if(a[i][j] == a[i][k]){
					ans[i] += a[i][j];
				}
			}
		}
		cout << ans[i] << endl;
	}
	return 0;
}

