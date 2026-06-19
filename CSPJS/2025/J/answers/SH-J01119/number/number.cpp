#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector <char> a;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>=48 && s[i]<58) {
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),greater<char>());
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
