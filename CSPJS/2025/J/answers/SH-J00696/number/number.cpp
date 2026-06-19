#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<char> v;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') v.push_back(s[i]);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) cout<<v[i];
	return 0;
}
