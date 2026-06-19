#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
	}
	cout<<52-n;
	return 0;
}
