#include <iostream>
#include <algorithm>
int T;
int n;
int a[200010];
int color[200010];
void solve(){
	int max_cnt = 0;
	for(int plan = 0;plan <= (1 << n); plan++){
		for(int i = 0;i < n;++i){
			color[i] = (plan & (1 << i)) > 0;
		}
		int cnt = 0;
		for(int i = 0;i < n;++i){
			int j = i - 1;
			while(j >= 0){
				if(color[j] == color[i]){
					cnt += (a[j] == a[i] ? a[i] : 0);
					break;
				}
				j--;
			}
		}
		max_cnt = std::max(max_cnt, cnt);
	}
	std::cout << max_cnt << std::endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);	
	std::cin >> T;
	for(int i = 0;i < T;++i){
		std::cin >> n;
		for(int j = 0;j < n;++j)
			std::cin >> a[j];
		solve();
	}
	return 0;
}
