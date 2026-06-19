#include<bits/stdc++.h>
using namespace std;
int n,ans;
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
	ans=52-st.size();
	cout<<ans;
	return 0;
} 
