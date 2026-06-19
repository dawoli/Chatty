#include <bits/stdc++.h>
using namespace std;
#define int long long
int a1[100005];
int a2[100005];
int a3[100005];
int tj1[100005];
int tj2[100005];
int tj3[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		//先把所有人放在最满意的社团，然后从最多的社团里面挑选损耗最少的人调剂
		int sum = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++){
			if (a1[i] >= a2[i] && a1[i] >= a3[i]){
				sum += a1[i];
				cnt1++;
				tj1[cnt1] = a1[i] - max(a2[i], a3[i]);
			} else if (a2[i] >= a1[i] && a2[i] >= a3[i]){
				sum += a2[i];
				cnt2++;
				tj2[cnt2] = a2[i] - max(a1[i], a3[i]);
			} else {
				sum += a3[i];
				cnt3++;
				tj3[cnt3] = a3[i] - max(a1[i], a2[i]); 
			}
		} 
		sort(tj1 + 1, tj1 + cnt1 + 1);
		sort(tj2 + 1, tj2 + cnt2 + 1);
		sort(tj3 + 1, tj3 + cnt3 + 1);
//		cout << sum << " " ;
		if (cnt1 >= cnt2 && cnt1 >= cnt3){
			
			for (int i = 1; i <= cnt1 - n / 2; i++){
				sum -= tj1[i];
			}
		} else if (cnt2 >= cnt1 && cnt2 >= cnt3){
			for (int i = 1; i <= cnt2 - n / 2; i++){
				sum -= tj2[i];
			}
		} else{
//			cout << "hello";
			for (int i = 1; i <= cnt3 - n / 2; i++){
				sum -= tj3[i];
//				cout << i << " " << tj3[i] << " ";
			}
		}
		cout << sum << endl;
	}
} 
