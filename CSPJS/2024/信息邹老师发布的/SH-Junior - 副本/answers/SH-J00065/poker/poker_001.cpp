#include<bits/stdc++.h>
using namespace std;
int n;
string a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set<string> st;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		st.insert(a[i]);
	}
	int cnt=0;
	for(auto v:st){
		cnt++;
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
