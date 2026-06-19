#include<bits/stdc++.h>
using namespace std;
bool isn(char a){
	return a>='0'&&a<='9';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<char>num;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isn(s[i])){
			num.push_back(s[i]);
		}
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
