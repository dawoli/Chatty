#include<bits/stdc++.h>

using namespace std;

string s;
int c;
int nums[1000005];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i ++){
		if((s[i] - '0') <= 9 && (s[i] - '0' >= 0)){
			nums[c] = s[i] - '0';
			c++;
		}
	}
	sort(nums, nums + c);
	for(int i = c - 1; i >= 0; i --){
		cout << nums[i];
	}
	cout << endl;
	return 0;
}
