#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a=n/7;
		for(int j=0;j<a;j++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
