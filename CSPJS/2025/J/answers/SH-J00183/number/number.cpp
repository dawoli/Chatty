#include <bits/stdc++.h>
using namespace std;
int nums[15];
vector<int> ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		nums[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(nums[i]--){
			ans.push_back(i);
		}
	}
	if(ans.size()==0) cout<<0;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}
	return 0;
}
