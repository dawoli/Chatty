#include <bits/stdc++.h>
using namespace std;
set<pair<char,char>> st;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;scanf("%d",&n);
	while (n--) {
		char op[5];scanf("%s",op);
		st.insert(make_pair(op[0],op[1]));
	}
	printf("%d",52-st.size());
	return 0;
}
