#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> nums;
	for(int i=0;i<s.size();++i){
		int num=s[i];
		if(num>=48&&num<=57){
			nums.push_back(num-48);
		}
	} 
	sort(nums.begin(),nums.end());
	int len=nums.size();
	vector<int>c=nums;
	for(int i=0;i<len;++i){
		nums[i]=c[len-i-1];
	}
	if(nums[0]==0){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<len;++i){
			cout<<nums[i];
		}
	}
	return 0;	
}
