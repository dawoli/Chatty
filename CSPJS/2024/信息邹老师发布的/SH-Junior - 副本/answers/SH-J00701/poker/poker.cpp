#include<bits/stdc++.h>
using namespace std;
long long n;
set<string> s;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		string ss;
		cin>>ss;
		s.insert(ss);
	}
	cout<<52-s.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
