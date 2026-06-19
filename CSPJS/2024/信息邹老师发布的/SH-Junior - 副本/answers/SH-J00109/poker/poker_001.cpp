#include<bits/stdc++.h>
using namespace std;
set<string> sl;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string q;
		cin>>q;
		sl.insert(q);
	}
	cout<<52-sl.size()<<endl; 
}
