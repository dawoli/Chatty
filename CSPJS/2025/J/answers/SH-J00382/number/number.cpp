#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
string s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n=s.size()-1;
	for(int i=0;i<=n;i++){
		if(s[i]>='0' and s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto u:v){
		cout << u;
	}
	return 0;
}

