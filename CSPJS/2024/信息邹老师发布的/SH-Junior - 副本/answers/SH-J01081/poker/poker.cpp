#include<bits/stdc++.h>
using namespace std;
string t;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		st.insert(t);
	}
	cout<<(52-st.size())<<endl;
	return 0;
}

