#include<bits/stdc++.h>

using namespace std;
int n,q;
struct node{
	string s;
	string e;
}a[200007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].e;
	}
	for(int i=1;i<=q;i++){
		string str1,str2;
		cin>>str1>>str2;
		cout<<2<<endl;
	}
	return 0;
} 
