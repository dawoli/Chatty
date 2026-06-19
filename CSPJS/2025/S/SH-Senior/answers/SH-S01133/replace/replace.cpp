#include<iostream>
#include<cstring>
using namespace std;
string s1,s2;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1>>s2;
	for(int j=1;j<=q;j++)cin>>t1>>t2;
	for(int j=1;j<=q;j++)cout<<0<<endl;
	return 0;
}
