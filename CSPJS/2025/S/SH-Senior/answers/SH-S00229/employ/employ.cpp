#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n,m,a[505],b[505],cnt,flg,ans,have,have2,Have,Have2;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s,s = " " + s;
	for (long long i = 1;i <= n;i++) cin >> a[i],have += (s[i] == '0'),have2 += (s[i] == '1'),b[i] = i;
	Have = have,Have2 = have2;
	do{
		cnt = 0,flg = 0;
		for (long long i = 1;i <= n;i++){
			if (cnt >= a[b[i]]){
				cnt++;
				continue;
			}
			if (n - i + 1 <= have2){
				flg += n - i + 1;
				break;
			}
			if (a[b[i + 1]] > cnt + 1) have--,cnt++;
			else if (have2 > 0) flg++,have2--;
			else have--,cnt++;
		}
		if (flg >= m){
			ans++;
			cout << "Yes:(" << flg << ")"; 
		}else cout << "No:(" << flg << ")"; 
		for (long long i = 1;i <= n;i++) cout << b[i] << " ";
		cout << endl;
		have = Have,have2 = Have2;
	}while (next_permutation(b + 1,b + n + 1));
	cout << ans;
	return 0;
}
