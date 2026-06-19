#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char> a;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a.push_back(s[i]);
	}
	sort(a.begin(),a.end());
	string ans="";
	for(int i=a.size()-1;i>=0;i--){
		if(ans==""&&a[i]=='0')continue;
		else ans+=a[i];
	}
	cout<<ans;
	return 0;
}

