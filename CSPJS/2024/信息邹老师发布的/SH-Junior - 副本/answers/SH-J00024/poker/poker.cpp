#include <bits/stdc++.h>
using namespace std;

int n;
string s[60];
set<string> st;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		st.insert(s[i]);
	}
	cout<<52-st.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
