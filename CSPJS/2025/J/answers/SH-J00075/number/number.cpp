#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> num;

bool isnum(char ch){
	return (ch>='0'&&ch<='9');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(isnum(s[i])) num.push_back(s[i]-'0');
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
