#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	//begin
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	//input
	int n, k;
	cin >> n >> k;
	vector<int> nums(n + 1);
	nums[0];
	for (int i = 1;i <= n;i++) cin >> nums[i];
	//start
	int now, stick = 0, before, cnt = 0;
	for (int i = 1;i <= n;i++){
		now = 0;
		before = -1;
		for (int j = i;j >= 0;j--){
			now = now ^ nums[j];
			if (now == k){
				before = j;
				break;
			}
		}
		if (before > stick){
			stick = i;
			cnt++;
		}
	} 
	cout << cnt;
	//end
	fclose(stdin);
	fclose(stdout);
	return 0;
}
