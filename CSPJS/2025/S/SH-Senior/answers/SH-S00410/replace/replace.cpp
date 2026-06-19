#include <iostream>
#include <string>
using namespace std;
int n,q,ans,l,r,pos1,pos2;
bool f;
string sa[200001],sb[200001],s_a[200001],s_b[200001],s1,s2;
int size1[200001],size2[200001];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> s_a[i] >> s_b[i];
		size1[i] = s_a[i].size();
		pos1 = 0,pos2 = size1[i]-1;
		while(s_a[i][pos1]==s_b[i][pos1] && pos1 < size1[i]) ++pos1;
		while(s_a[i][pos2]==s_b[i][pos2] && pos2) --pos2;
		sa[i] = s_a[i].substr(pos1,pos2-pos1+1);
		sb[i] = s_b[i].substr(pos1,pos2-pos1+1);
	}
	while(q--) {
		cin >> s1 >> s2;
		ans = 0;
		for(int i=0; i<s1.size(); ++i) {
			if(s1[i] != s2[i]) {
				l=i;
				break;
			}
		}
		for(int i=s1.size()-1; i>=1; --i) {
			if(s1[i] != s2[i]) {
				r=i;
				break;
			}
		}
		if(l <= r) {
			f=0;
			string s_1 = s1.substr(l,r-l+1),s_2 = s2.substr(l,r-l+1);
			for(int i=1; i<=n; ++i) {
				if(sa[i] == s_1 && sb[i] == s_2) {
					f=1;
					break;
				}
			}
			if(!f) {
				cout << 0 << "\n";
				continue;
			}
		}
		for(int i=1; i<=n; ++i) {
			int pos = s1.find(s_a[i]);
			while(pos != -1) {
				if(s_b[i] == s2.substr(pos,size1[i]) && (pos+size1[i] == s1.size() || s1.substr(pos+size1[i]) == s2.substr(pos+size1[i])) && s1.substr(0,pos) == s2.substr(0,pos))
					++ans;
				pos = s1.find(s_a[i],pos+1);
			}
		}
		cout << ans << "\n";
	}
}
