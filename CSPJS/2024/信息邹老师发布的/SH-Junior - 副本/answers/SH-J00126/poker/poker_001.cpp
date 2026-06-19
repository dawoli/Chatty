#include<bits/stdc++.h>
using namespace std;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		st.insert(s);
	}
	int l=52-st.size();
	cout<<l;
	return 0;
}
