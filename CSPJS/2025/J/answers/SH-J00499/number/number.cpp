#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			nums.push_back(s[i]-'0');
		}
	}
	int n=nums.size();
	sort(nums.begin(),nums.end(),greater<int>());
	for(int i=0;i<n;i++){
		cout<<nums[i];
	}
	return 0;
}
