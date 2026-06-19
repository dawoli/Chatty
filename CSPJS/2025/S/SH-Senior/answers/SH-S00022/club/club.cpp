#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn = 1e5 + 10;
struct node{
	int x,y,z,sum1,sum;
}a[maxn];
long long ans;
int cnt[10];
int cnt1,cnt2,cnt3;
bool cmp(node x,node y){
	if(x.sum1 != y.sum1){
		return x.sum1 > y.sum1;
	}
	return x.sum > y.sum;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t --){
		cnt1 = 0,cnt2 = 0,cnt3 = 0;
		ans = 0;
		int n;
		cin >> n;
		int m = n / 2;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].sum = a[i].x + a[i].y + a[i].z;
			if(a[i].x == 0){
				a[i].sum1 ++;
			}
			if(a[i].y == 0){
				a[i].sum1 ++;
			}
			if(a[i].z == 0){
				a[i].sum1 ++;
			}
		}
		sort(a + 1 , a + n + 1 , cmp);
		for(int i = 1 ; i <= n ; i++){
			int maxi = 0,maxj = 0;
			if(cnt[1] < m && cnt[2] < m && cnt[3] < m){
				if(a[i].x > maxi){
					maxj = 1;
					maxi = a[i].x;
				}
				if(a[i].y > maxi){
					maxj = 2;
					maxi = a[i].y;
				}
				if(a[i].z > maxi){
					maxj = 3;
					maxi = a[i].z;
				}
				cnt[maxj] ++;
				ans += maxi;
				continue;
			}
			if(cnt[1] >= m){
				if(cnt[2] >= m || cnt[3] >= m){
					if(cnt[2] >= m){
						cnt[3]++;
						ans += a[i].z; 
					}else{
						cnt[2] ++;
						ans += a[i].y;
					}
				}else{
					if(a[i].y > maxi){
						maxj = 2;
						maxi = a[i].y;
					}
					if(a[i].z > maxi){
						maxj = 3;
						maxi = a[i].z;
					}
					cnt[maxj] ++;
					ans += maxi;
				}
				continue;
			}else if(cnt[2] >= m){
				if(cnt[3] >= m){
					cnt[1]++;
					ans += a[i].x;
				}else{
					if(a[i].z > maxi){
						maxj = 3;
						maxi = a[i].z;
					}
					if(a[i].x > maxi){
						maxj = 1;
						maxi = a[i].x;
					}
					cnt[maxj] ++;
					ans += maxi;
				}
				continue;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
