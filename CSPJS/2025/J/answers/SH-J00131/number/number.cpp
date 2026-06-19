#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			vec.push_back((s[i]-'0'));
		}
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<vec.size();i++){
		cout<<vec[i];
	}
	return 0;
} 
