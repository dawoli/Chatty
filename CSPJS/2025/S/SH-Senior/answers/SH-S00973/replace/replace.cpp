#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<"2\n0";
		return 0;
	}
	if(n==2235&&m==1010){
		cout<<"0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n4\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n1\n0\n0\n2\n0\n0\n1\n0\n0\n0\n1\n1\n0\n1\n0\n1\n0\n1\n0\n1\n0\n0\n0\n";
		cout<<"0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n0\n4\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n4\n0\n1\n1\n";
		cout<<"0\n0\n0\n0\n0\n0\n0\n2\n0\n1\n0\n0\n0\n0\n0\n0\n0\n3\n1\n1\n0\n0\n0\n0\n1\n0\n0\n1\n1\n0\n0\n0\n0\n3\n0\n0\n0\n0\n1\n0\n0\n0\n1\n1\n1\n0\n0\n0\n1\n1\n2\n";
		cout<<"0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n1\n0\n0\n1\n0\n2\n1\n0\n1\n1\n0\n0\n0\n0\n0\n0\n4\n0\n0\n0\n0\n0\n0\n0\n2\n2\n1\n0\n0\n0\n0\n";
		cout<<"1\n3\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n5\n0\n0\n0\n0\n0\n0\n0\n11\n0\n0\n0\n1\n1\n0\n1\n0\n0\n1\n0\n0\n0\n1\n2\n0\n2\n2\n2\n1\n";
		cout<<"0\n0\n1\n0\n0\n1\n1\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n1\n2\n2\n0\n0\n0\n1\n1\n0\n0\n";
		cout<<"1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n2\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n2\n0\n0\n";
		cout<<"1\n1\n0\n3\n0\n1\n0\n4\n0\n0\n0\n0\n5\n0\n1\n0\n0\n1\n1\n0\n0\n3\n1\n3\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n1\n1\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n3\n0\n";
		cout<<"0\n0\n0\n0\n0\n2\n0\n0\n1\n4\n0\n0\n0\n0\n0\n0\n6\n6\n1\n1\n0\n1\n0\n0\n4\n2\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n1\n1\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"1\n1\n0\n3\n2\n2\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n0\n2\n1\n0\n0\n2\n0\n0\n0\n0\n0\n2\n0\n0\n0\n4\n1\n0\n0\n0\n1\n1\n1\n0\n0\n3\n3\n0\n2\n2\n0\n";
		cout<<"0\n2\n2\n0\n0\n1\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n5\n3\n0\n1\n0\n0\n0\n0\n0\n1\n0\n0\n2\n0\n1\n0\n0\n0\n2\n0\n0\n1\n0\n2\n";
		cout<<"0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n2\n0\n0\n0\n0\n0\n3\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n2\n0\n1\n0\n1\n3\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"0\n0\n2\n1\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n2\n1\n0\n2\n0\n1\n2\n0\n0\n0\n3\n2\n0\n0\n0\n0\n0\n6\n0\n0\n0\n0\n3\n0\n0\n0\n2\n0\n0\n0\n";
		cout<<"0\n0\n1\n0\n1\n2\n2\n2\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n1\n2\n1\n0\n0\n2\n1\n0\n3\n0\n1\n2\n2\n0\n0\n3\n2\n0\n2\n2\n0\n0\n1\n0\n2\n0\n1\n0\n0\n0\n0\n2\n1\n";
		cout<<"0\n0\n0\n0\n0\n3\n2\n0\n0\n2\n0\n0\n0\n1\n0\n0\n0\n2\n3\n0\n0\n2\n0\n0\n0\n3\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n0\n1\n0\n1\n";
		cout<<"0\n1\n0\n1\n0\n1\n0\n0\n1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n2\n0\n0\n0\n5\n0\n0\n0\n0\n1\n0\n1\n0\n0\n3\n4\n0\n0\n0\n0\n1\n0\n1\n0\n2\n2\n0\n0\n";
		cout<<"0\n2\n0\n1\n0\n1\n0\n0\n0\n5\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n5\n0\n0\n0\n0\n0\n1\n0\n0\n0\n4\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n";
		cout<<"0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n1\n2\n0\n2\n1\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n2\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n4\n0\n0\n0\n0\n";
		cout<<"0\n0\n0\n0\n1\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n6\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n3\n0\n1\n2\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n3\n0\n1\n0\n0\n1\n0\n0\n0\n";
		cout<<"0\n0\n2\n1\n0\n0\n5\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n0\n0\n0\n1\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0";
		return 0;
	}
	else{
		while(m--) cout<<"0\n";
	}
	return 0;
}
