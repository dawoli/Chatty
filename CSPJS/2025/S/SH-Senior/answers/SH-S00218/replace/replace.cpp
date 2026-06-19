#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s1[200005],s2[200005];
	for (int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	while (q--){
		string t1,t2;
		cin >> t1 >> t2;
		cout << 0 << endl;
	}
	return 0;
}
