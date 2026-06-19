#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		st.insert(s);
	}
	cout<<52-st.size();
}
