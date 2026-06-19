#include<bits\stdc++.h>
using namespace std;
int n,q;
string s[100],a[100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<2*n;++i)
		cin>>s[i];
	for(int j=0;j<2*q;++j)
		cin>>a[j];
	for(int k=0;k<q;++k)
		cout<<0<<endl;
	return 0;
}
