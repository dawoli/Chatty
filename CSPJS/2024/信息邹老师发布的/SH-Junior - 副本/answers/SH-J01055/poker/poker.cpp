# include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n;
	cin >> n;
	set<string> st;
	for(int i = 0;i < n;i++){
		string a;
		cin >> a;
		st.insert(a);
	}
	cout << 52-st.size();
	return 0;
}
