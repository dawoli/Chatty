#include<bits/stdc++.h>

using namespace std;

const int NR = 5e5+10;
int a[NR];
int s[NR];
int b[1048600]; // record the last appear of each num.

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k; cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) s[i] = s[i-1] ^ a[i];
	
//	for(int i = 1; i <= n; i ++) cout << s[i] << ' ';
//	cout << '\n';
	
	memset(b,0xff,sizeof b); // if a num. hasn't appeared yet, it's -1
	b[0] = 0;
	int ans = 0, l = 1;
	for(int r = 1; r <= n; r ++){
		// find left >= l which can satisfy s[r]^k == s[l-1]
		// => find s[r]^k, and judge if it is appeared at left >= l-1
		if(a[r] == k || b[s[r]^k] >= l-1){
//			cout << b[s[r]^k]+1 << '~' << r << '\n';
			ans ++, l = r+1;
		}
		b[s[r]] = r;
	}
	
	cout << ans;
	
	
	return 0;
}
