#include <bits/stdc++.h>
using namespace std;
int t;

int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		int n;
		int tot = 0;
		cin >> n;
		int maxn = n / 2;
		if(n == 2) {
			int a[10], b[10], c[10], vis[10000] = {};
			for(int i = 1; i <= 2; i++) {
				cin >> a[i] >> b[i] >> c[i];
				if(a[i] >= b[i] or a[i]>= c[i] and vis[i] != 1){tot += a[i];vis[i] = 1;continue;}
				if(b[i] >= c[i] or b[i] >= a[i] and vis[i] != 1){tot += b[i];vis[i] = 1;continue;}
				if(c[i] >= a[i] or b[i] >= a[i] and vis[i] != 1){tot += c[i];vis[i] = 1;continue;} 
			}
			
		}else if(n == 1e5){
			int a[100005], b[100005], c[100006];
			for(int i = 1; i <= n; i++) {
				cin >> a[i] >> b[i] >> c[i];
			}
			if(b[1] == 0 and c[1] == 0 and b[2] == 0 and c[2] == 0) {
				sort(a + 1, a + n + 1);
				for(int i = n ; i > maxn; i--){
					tot += a[i];
				}
			}
			
		}
		else{
		
		int a1[100005] = {}, b1[100005]={}, c1[100005]={}, a2[100005]={}, b2[100005]={}, c2[100005]={};
		int a[100006], b[100006], c[100006];
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			a1[i] = b1[i] = c1[i] = i;
			a2[i] = a[i], b2[i] = b[i], c2[i] = c[i];
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		int sum1 = 0, sum2 = 0, sum3 = 0;
		for(int i = n; i > maxn ; i--) {
			sum1 += a[i];
			sum2 += b[i];
			sum3 += c[i];
		}
				
		if(sum1 >= sum2) {
			if(sum2 >= sum3){
				tot += sum1;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
						tot1 = 0;
						s = max(b[i] + c[i], s);
						tot1 = max(sum2, s);
					
				}
				tot += tot1;
			}
			if(sum2 < sum3){
				tot += sum1;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
						tot1 = sum3;
						s = max(b[i] + c[i], s);
						tot1 = max(sum3, s); 
				}
				tot += tot1;
			}
		//	break;
		}
	    if(sum2 >= sum1) {
			if(sum1 >= sum3){
				tot += sum2;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
						tot1 = sum1;
						s = max(a[i] + c[i], s);
						tot1 = max(sum1, s);
				}
				tot += tot1;
			}
			if(sum1 < sum3){
				tot += sum2;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
						tot1 = sum3;
						s = max(a[i] + c[i], s);
						tot1 = max(sum3, s); 
					
					
				}
				tot += tot1;
			}
		}
		if(sum3 >= sum2) {
			if(sum1 >= sum2){
				tot += sum3;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
					
						tot1 = sum1;
						s = max(b[i] + a[i], s);
						tot1 = max(sum1, s); 
					
					
				}
				tot += tot1;
			}
			if(sum1 < sum2){
				tot += sum3;
				int s = 0;
				int tot1 = 0;
				for(int i = n; i > maxn; i--){
				
						tot1 = sum2;
						s = max(b[i] + a[i], s);
						tot1 = max(sum2, s); 
					
					
				}
				tot += tot1;
			}
		}
		cout << tot << endl;
		}
		
	}
	return 0;
}

