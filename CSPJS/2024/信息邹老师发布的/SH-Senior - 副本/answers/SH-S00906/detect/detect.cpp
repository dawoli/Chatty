#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int d[1005],v[1005],a[1005];
int p[1005];
int y[1005];
bool c[1005];
int s[1005];
int b[1005];
int ans1,ans2;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	cin >> n >> m >> L >> V;
	for(int i = 1;i <= n;i++){
		cin >> d[i] >> v[i] >> a[i];
	}
	for(int i = 1;i <= m;i++){
		cin >> p[i];
	}
	for(int i = 1;i <= n;i++){
		s[i] = (3 * 3 - v[i] * v[i]) / (2 * a[i]);
		b[i] = d[i] + s[i];
		if(b[i] > 15){
			break;
		} else {
			ans1++;
		}
		for(int j = d[i];j <= b[i];j++){
			for(int k = 1;k <= m;k++){
				if(j == p[k]){
					c[k] == false;
				}
			}
		}	
	}
	for(int i = 1;i <= m;i++){
		if(c[i] == true){
			ans2++;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
