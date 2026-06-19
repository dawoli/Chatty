#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string l;
	set<string> a;
	for(int i=1;i<=n;i++){
		cin>>l;
		a.insert(l);
	}
	cout<<52-a.size();
	return 0;
}
