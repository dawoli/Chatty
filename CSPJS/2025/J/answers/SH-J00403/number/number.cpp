#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,nums;cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i])) nums+=s[i];
	sort(nums.begin(),nums.end(),[](char a,char b){
		return a>b;
	});
	cout<<nums;
	return 0;
} 
