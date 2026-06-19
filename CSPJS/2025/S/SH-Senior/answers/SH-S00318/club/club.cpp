#include <bits/stdc++.h>
using namespace std;
struct haogan{
	int x[4];
	int tag;	
}a[100010];
int t;
int main() {
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	cin >> t;
	while (t--) {
		int n;
		scanf("%d",&n);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		int d[100010]; //¿÷ËðÖµ 
		for (int i = 1; i <= n; ++i) 
			scanf("%d%d%d",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
		int temp[4];
		for (int i = 1; i <= n; ++i) {
			temp[1] = a[i].x[1];
			temp[2] = a[i].x[2];
			temp[3] = a[i].x[3];
			sort(temp + 1, temp + 3 + 1);
			d[i] = temp[3] - temp[2];
			if (a[i].x[1] == temp[3]) {
				ans = ans + temp[3];
				cnt1++;
				a[i].tag = 1;
			}
			else if (a[i].x[2] == temp[3]) {
				ans = ans + temp[3];
				cnt2++;
				a[i].tag = 2;
			}
			else if (a[i].x[3] == temp[3]) {
				ans = ans + temp[3];
				cnt3++;
				a[i].tag = 3;
			}
		}
		int h[100010];
		if(cnt1 > n/2){
			int top = 0;
			for (int i = 1; i <= n; ++i) {
				if(a[i].tag == 1)
					h[++top] = d[i];
			}
			sort(h + 1, h + top + 1);
			int delta = cnt1 - n/2;
			for (int i = 1; i <= delta; ++i) {
				ans = ans - h[i];
			}
			cout << ans << endl;
		}
		else if(cnt2 > n/2){
			int top = 0;
			for (int i = 1; i <= n; ++i) {
				if(a[i].tag == 2)
					h[++top] = d[i];
			}
			sort(h + 1, h + top + 1);
			int delta = cnt2 - n/2;
			for (int i = 1; i <= delta; ++i) {
				ans = ans - h[i];
			}
			cout << ans << endl;
		}
		else if(cnt3 > n/2){
			int top = 0;
			for (int i = 1; i <= n; ++i) {
				if(a[i].tag == 3)
					h[++top] = d[i];
			}
			sort(h + 1, h + top + 1);
			int delta = cnt3 - n/2;
			for (int i = 1; i <= delta; ++i) 
				ans = ans - h[i];
			cout << ans << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
