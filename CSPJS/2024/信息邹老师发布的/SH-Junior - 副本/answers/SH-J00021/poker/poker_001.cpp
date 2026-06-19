#include<bits/stdc++.h>
using namespace std;
string a[55];
int ans=52,n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	set<string> s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	int b=s.size();
	cout<<52-b;
	return 0;
}
