#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, q;
struct str{
	string a;
	string b;
};
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	vector<str> s;
	for(int i=1; i<=n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		s.push_back({s1, s2});
	}
	while(q--){
		string t1, t2;
		int ans = 0;
		cin >> t1 >> t2;
		for(int i=0; i<s.size(); i++){
			for(int j=0; j+s[i].a.size()-1<t1.size(); j++){
				string s1, s2, s3, s4, s5, s6, s7, s8;
				s1 = t1.substr(0, j);
				s2 = s[i].b;
				s3 = t1.substr(j+s[i].a.size(), t1.size()-j-s[i].a.size());
				s4 = t2;
				s5 =  t1.substr(j, s[i].a.size());
				s6 = s[i].a;
//				cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << endl;
				if(s1 + s2 + s3 == s4 && s5 == s6){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
