#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char>a;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0; i<a.size(); i++) {
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
