#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int> num;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num.push_back(s[i]-'0');
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--)
		cout<<num[i];
	return 0;
}
