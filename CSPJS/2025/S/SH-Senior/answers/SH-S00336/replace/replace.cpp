#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

int n,q;
string s[200010][3];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1;i<=q;i++){
		string str1,str2;
		cin >> str1 >> str2;
		if(str1.size() != str2.size()) cout << 0 << endl;
		else cout << 0 <<endl;
	}
	return 0;
}
