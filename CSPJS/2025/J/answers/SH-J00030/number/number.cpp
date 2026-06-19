#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> v;
	for(char c:s){
		if(isdigit(c)){
			v.push_back(c-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int x:v) cout<<x;
	return 0;
}
