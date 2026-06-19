#include<bits/stdc++.h>
using namespace std;
const int N=59;
set<string> s;
string n[N];
int ans,m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n[i];
		s.insert(n[i]);
	}
	cout<<52-s.size()<<endl;
	return 0;
} 
