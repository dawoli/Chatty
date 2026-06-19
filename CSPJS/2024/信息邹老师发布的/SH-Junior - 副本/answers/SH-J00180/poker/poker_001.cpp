#include<bits/stdc++.h>
using namespace std;
int n;
string x;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x;
		s.insert(x);
	}
	cout<<52-s.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
