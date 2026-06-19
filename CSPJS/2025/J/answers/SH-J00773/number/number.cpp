#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<char> nums;
	for (int i = 0;i < int(s.size());i++){
		if (s[i] >= '0' && s[i] <= '9'){
			nums.push_back(s[i]);
		}
	}
	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 1;i >= 0;i--){
		cout << nums[i];
	}
	cout << 123;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
