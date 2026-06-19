#include<bits/stdc++.h>
using namespace std;
int n;
char a[10];
set<string>x;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		x.insert(a);
	}
	cout<<52-x.size();
	return 0;
}
