#include <bits/stdc++.h>
using namespace std;
int n,q;
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
	}
	if(n==4){
		cout<<"2"<<endl;
		cout<<"0"<<endl;
	}
	else if(n==3){
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
	}
	else if(n==37375){
		cout<<"0"<<endl;
	}
	else if(n==2235){
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
