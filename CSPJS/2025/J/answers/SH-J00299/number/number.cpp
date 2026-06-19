#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s, new_str;
vector<char> nums;
string ans;
int main(){
	freopen("numbe r.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i<=10005;i++){
		bool flag = false;
		for(int j=0;j<=15;j++){
//			if (s[i] == numbers[j]) flag = true;
			if (s[i]=='0') flag = true;
			if (s[i]=='1') flag = true;
			if (s[i]=='2') flag = true;
			if (s[i]=='3') flag = true;
			if (s[i]=='4') flag = true;
			if (s[i]=='5') flag = true;
			if (s[i]=='6') flag = true;
			if (s[i]=='7') flag = true;
			if (s[i]=='8') flag = true;
			if (s[i]=='9') flag = true;
		}
		if (flag == true) new_str+=s[i];
	}
	
	// cout << new_str << endl;
	
	for(int i = 0;i<=sizeof(new_str);i++){
		nums.push_back(new_str[i]);
	}
	
	for(int j=0;j<=nums.size();j++)
		for (int i=0;i<=nums.size();i++){
			if(nums[i]<nums[i+1]){
				int a = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = a;
			}
	
			
		}
	 
	for(int i = 0;i<=nums.size();i++){
		if (nums[i]=='0') ans[i] = '0';
		if (nums[i]=='1') ans[i] = '1';
		if (nums[i]=='2') ans[i] = '2';
		if (nums[i]=='3') ans[i] = '3';
		if (nums[i]=='4') ans[i] = '4';
		if (nums[i]=='5') ans[i] = '5';
		if (nums[i]=='6') ans[i] = '6';
		if (nums[i]=='7') ans[i] = '7';
		if (nums[i]=='8') ans[i] = '8';
		if (nums[i]=='9') ans[i] = '9';
		
	}
	
	for (int i=0;i<=nums.size();i++){
		cout << ans[i];
	}

	return 0;
	
	
}
