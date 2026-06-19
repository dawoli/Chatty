#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	int n;
	cin>>n;
	set<string> l;
	for (int i=0;i<n;i++){
		string a;
		cin>>a;
		l.insert(a);
	}
	cout<<52-l.size();
	return 0;
} 
