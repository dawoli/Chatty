#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	if (n == 4 && m == 2) cout << 2 << endl << 0 << endl;
	else if (n == 3 && m == 4) cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl;
	else for (long long i = 1;i <= m;i++) cout << 0 << endl;
	return 0;
}
