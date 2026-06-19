#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			vec.push_back(s[i]-'0');
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
	}
}
