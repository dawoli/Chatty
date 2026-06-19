#include<bits/stdc++.h>
const int N = 1e5 + 5;
int a[N][4],ord[N][4],cHoose[N],cnt[4];
struct node{
	int a,b,c;
	bool operator<(node &x){return c < x.c;} 
}; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int t;
	for (std::cin >> t;t--;){
		int n,ans = 0;std::cin >> n;
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= n;i++){
			std::cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				ans += a[i][1];
				++cnt[1]; 
				cHoose[i] = 1;
				ord[i][1] = 1;
				ord[i][2] = a[i][2] > a[i][3] ? 2 : 3;
				ord[i][3] = a[i][2] < a[i][3] ? 2 : 3;
			}
			else if (a[i][2] >= a[i][3]){
				ans += a[i][2];
				++cnt[2]; 
				cHoose[i] = 2;
				ord[i][1] = 2;
				ord[i][2] = a[i][1] > a[i][3] ? 1 : 3;
				ord[i][3] = a[i][1] < a[i][3] ? 1 : 3;
			}
			else{
				ans += a[i][3];
				++cnt[3];
				cHoose[i] = 3;
				ord[i][1] = 3;
				ord[i][2] = a[i][1] > a[i][2] ? 1 : 2;
				ord[i][3] = a[i][1] < a[i][2] ? 1 : 2;
			}
		}
		for (int i = 1;i <= 3;i++)
			if (cnt[i] > n / 2){
				std::vector<node> v;
				for (int j = 1;j <= n;j++)
					if (cHoose[j] == i){
						v.push_back({j,ord[j][2],a[j][ord[j][1]] - a[j][ord[j][2]]});
					}
				std::sort(v.begin(),v.end());
				for (int j = 0;cnt[i] > n / 2;j++){
					--cnt[i];
					++cnt[v[j].b];
					cHoose[v[j].a] = v[j].b;
					ans -= v[j].c;
				}
				break;
			}
		std::cout << ans << '\n';
	}
	return 0;
}
