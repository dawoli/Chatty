#include <bits/stdc++.h>
using namespace std;
string ans[100005];
long long T,n; 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ans[1] = "-1",ans[2] = "1",ans[3] = "7",ans[4] = "4",ans[5] = "2",ans[6] = "6",ans[7] = "8",ans[8] = "10",ans[9] = "18",ans[10] = "22",ans[11] = "20",ans[12] = "28",ans[13] = "68",ans[14] = "88",ans[15] = "108",ans[16] = "188",ans[17] = "200",ans[18] = "208",ans[19] = "288",ans[20] = "688";
	for (long long i = 21;i <= 100000;i++) ans[i] = ans[i - 7] + "8";
	cin >> T;
	while (T--) cin >> n,cout << ans[n] << endl;
	return 0;
}
