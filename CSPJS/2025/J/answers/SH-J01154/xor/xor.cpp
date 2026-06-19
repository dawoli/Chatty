#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3+5;
// expected: 50pts: (spdata:A,B)
int n,k,a[N],cnt0 = 0,ans = 0;
bool vis[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	memset(vis,false,sizeof(vis));
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		cnt0 += a[i] == 0;
	}
	
	if(cnt0 == 0 && k == 0) { // spdata:A
		cout << n/2+(n%2 == 1) << "\n";
		return 0;
	}
	
	//spdata:B
	if(k == 1) {
		cout << n-cnt0 << "\n";
	} else if(k == 0) {
		for(int i = 1;i <= n;i++) {
			if(a[i] == a[i+1] && !vis[i] && !vis[i+1]) {
				vis[i] = vis[i+1] = true;
				ans++;
			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
