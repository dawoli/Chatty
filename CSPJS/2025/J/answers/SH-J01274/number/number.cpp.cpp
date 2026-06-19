#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<s.length();i++){
		if((int)s[i]>=48&&(int)s[i]<=57){
			v.push_back((int)s[i]-48);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}

