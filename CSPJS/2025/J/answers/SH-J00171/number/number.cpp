#include <bits/stdc++.h>
using namespace std;

string s;
int t[66];
vector <int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9')  a.push_back(s[i]-'0');
	for (auto i:a)  t[i]++;
	for (int i=9;i>=0;i--){
		while (t[i]--)  cout<<i;
	}
	return 0;
} 
