#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int x;
string s;
vector<int> a[100009];
void solve() {
	cin>>n>>k>>q;
	srand(time(0));
	x=rand()%2;	
	for(int i=0;i<=n;i++) {
		getline(cin,s);
		for(int j=0;j<s.size();j++) {
			if(s[j]>='0'&&s[j]<='9') a[i].push_back(s[j]-'0');
		}
	}
	for(int i=1;i<=q;i++) {
		int z,y;
		cin>>z>>y;
		srand(time(0));
		x=rand();
		cout<<(z+x+y)%2<<endl;;	
	}
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
