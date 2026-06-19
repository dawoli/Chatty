#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005]={},t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i+=1){
		cin>>s[i];
	}
	for(int i=0;i<q;i+=1){
		cin>>t;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
