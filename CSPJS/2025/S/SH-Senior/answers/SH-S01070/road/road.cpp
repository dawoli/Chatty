#include <cstdio>
int main() {
    int x;
    scanf("%d",&x);
    printf("#d/n",x);
    return 0;
}
using namespace std;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
      fclose(stdin);
      fclose(stdout);
    return 0 ;
}
int main() {
	for i = 1,i <= m,i++
	for j = 1 + i,j <= k,j++
}
# include <vector>
void permute(vector<int>& nums, int pos){
	if (pos == nums.size()) {
		for (int x : nums) print("%d", x);
		printf("/n");
		return;
	}
	for (int i = pos; i < nums.size(); i++){
		swap(nums[pos], nums[i]);
		permute(nums, pos + 1);
		swap(nums[pos], nums[i]);
	}
}
int lis(vector<int>& a) {
	int n = a.size();
	vector<int> dp(n, 1);
	int ans = 1;
	for (int i = 1; i < n; i++){
		if (a[j] <= a[i]) {
			dp[i] =max(dp[i], dp[j] + 1);
		}
	}
	ans = max (ans dp[i]);
}
return ans;




















