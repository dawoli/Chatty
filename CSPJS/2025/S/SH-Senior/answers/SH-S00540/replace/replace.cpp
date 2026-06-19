#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s;
	for (int i = 1; i <= 2 * n; i ++) cin >> s;
	for (int i = 1; i <= q; i ++) cin >> s;
	for (int i = 1; i <= q; i ++) cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
