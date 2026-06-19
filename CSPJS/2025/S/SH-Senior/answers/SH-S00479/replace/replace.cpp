#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,q;
int a[600],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a[i]=s1.length()+s2.length();
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<a[int(abs(s1.length()-11))]+s1.length()+s2.length();
	}
	return 0;
}
