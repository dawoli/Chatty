#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int>d;
	for(size_t i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')d.push_back(int(s[i]-'0'));
	}
	sort(d.begin(),d.end(),cmp);
	for(size_t i=0;i<d.size();i++)cout<<d[i];
	cout<<endl;
	return 0;
}


