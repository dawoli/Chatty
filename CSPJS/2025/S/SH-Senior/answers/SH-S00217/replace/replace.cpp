#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,q;
string s1[200005],s2[200005];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) {
		cin >> s1[i] >> s2[i];
		int l=1,r=0;
		for (int j=0;j<s1[i].size();j++) {
			if (s1[i][j]!=s2[i][j]) {
				l=j;
				break;
			}
		}
		for (int j=s1[i].size()-1;j>=0;j--) {
			if (s1[i][j]!=s2[i][j]) {
				r=j;
				break;
			}
		}
		s1[i]=s1[i].substr(l,r);
		s2[i]=s2[i].substr(l,r);
		//cout << s1[i] << endl << s2[i] << endl;
	}
	for (int i=1;i<=q;i++) {
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size()!=t2.size()) {
			cout << 0 << endl;
			continue;
		}
		int l=1,r=0;
		for (int j=0;j<t1.size();j++) {
			if (t1[j]!=t2[j]) {
				l=j;
				break;
			}
		}
		for (int j=t1.size()-1;j>=0;j--) {
			if (t1[j]!=t2[j]) {
				r=j;
				break;
			}
		}
		t1=t1.substr(l,r);
		t2=t2.substr(l,r);
		int ans=0;
		for (int i=1;i<=n;i++) {
			if (s1[i]==t1&&s2[i]==t2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
