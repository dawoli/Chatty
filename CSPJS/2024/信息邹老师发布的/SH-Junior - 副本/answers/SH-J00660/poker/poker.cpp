#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
string t;
set<string>s;
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t;
		s.insert(t);
	}
	cout<<52-s.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
