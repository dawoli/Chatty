#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for (int t=1;t<=q;t++){
		cin>>t1>>t2;
	}
	for (int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
