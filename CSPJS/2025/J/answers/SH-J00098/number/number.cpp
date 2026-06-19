#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=s[i]-'0';
			ans.push_back(k);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
