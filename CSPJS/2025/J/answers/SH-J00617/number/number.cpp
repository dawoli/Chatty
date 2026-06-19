#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>q;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//cin.tie(0);
	getline(cin,s);
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			q.push_back(s[i]-'0');
		}
	}
	sort(q.begin(),q.end(),cmp);
	for(auto v:q){
		printf("%d",v);
	}
	return 0;
}
