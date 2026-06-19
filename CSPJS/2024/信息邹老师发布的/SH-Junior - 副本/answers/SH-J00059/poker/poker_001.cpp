#include<iostream>
#include<set>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	set<string> st;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		st.insert(x);
	}
	int s=st.size();
	cout<<52-s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
