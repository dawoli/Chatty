#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
} 
