#include<bits/stdc++.h>
using namespace std;

vector<int> num;
bool cmp(int a,int b) {
	return a>b;
}
 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' && s[i]>='0') num.push_back(s[i]-'0');
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++){
		cout<<num[i];
	} 
	return 0;
}
