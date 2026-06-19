#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;
const int N=52;
set<string> se;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n; cin>>n;
	for(int i=0;i<n;i++){
		string s; cin>>s;
		se.insert(s);
	}
	cout<<N-se.size();
	return 0;
}
//SH-J00805
