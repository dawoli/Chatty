#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5] = {0},rs[3] = {0},pd[3],di1,di2,di3,rscl,chaju[100005] = {0},wz;
int long long ans = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int T = 0;T < t;T++){
		ans = 0;
		rs[1] = 0;
		rs[2] = 0;
		rs[0] = 0;
		for(int i = 0;i < 100002;i++){
			for(int j = 0;j < 5;j++){
				a[i][j] = 0;
			}
			chaju[i] = 0;
		}
		
		
		cin >> n;
		
		for(int i = 0;i < n;i++){
			scanf("%d %d %d",&pd[0],&pd[1],&pd[2]);
			for(int j = 0;j < 3;j++){
				a[i][j] = pd[j];
			}
			if(pd[0] >= pd[1]&&pd[0] >= pd[2]){
				di1 = 0;
				if(pd[1] >= pd[2]){
					di2 = 1;
					di3 = 2;
				}
				else{
					di2 = 2;
					di3 = 1;
				}
			}
			else if(pd[0] <= pd[1]&&pd[0] <= pd[2]){
				di3 = 0;
				if(pd[1] >= pd[2]){
					di1 = 1;
					di2 = 2;
				}
				else{
					di1 = 2;
					di2 = 1;
				}
			}
			else{
				di2 = 0;
				if(pd[1] >= pd[2]){
					di1 = 1;
					di3 = 2;
				}
				else{
					di1 = 2;
					di3 = 1;
				}
			}
			ans += pd[di1];
			rs[di1]++;
			a[i][3] = di1;
			a[i][4] = di2;
			continue;
		}
		
		
		if(rs[0] <= n/2&&rs[1] <= n/2&&rs[2] <= n/2){
			cout << ans << "\n";
			continue;
		}
		if(rs[0] > n/2)rscl = 0;
		if(rs[1] > n/2)rscl = 1;
		if(rs[2] > n/2)rscl = 2;
		wz = 0;
		for(int i = 0;i < n;i++){
			if(a[i][3] == rscl){
				chaju[wz] = a[i][a[i][3]]-a[i][a[i][4]];
				wz++;
			}
		}
		sort(chaju,chaju+rs[rscl]);
		for(int i = 0;i < rs[rscl]-(n/2);i++){
			ans -= chaju[i];
		}
		
		cout << ans << "\n";
		

	}
	return 0;
}
