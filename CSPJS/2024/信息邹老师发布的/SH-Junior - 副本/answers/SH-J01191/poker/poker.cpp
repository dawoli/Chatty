#include<bits/stdc++.h>
#define maxn 123456
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
string s;
set<string>st;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		st.insert(s);
	}
	cout<<52-st.size()<<endl;
	return 0;
}

// code written by luogu user #951212
