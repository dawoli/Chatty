#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string x;
	int rest=52;
	for(int i=0;i<n;i++){
		cin>>x;
		if(!s.count(x)){
			rest--;
		}
		s.insert(x);
	}
	cout<<rest;
	return 0;
}
