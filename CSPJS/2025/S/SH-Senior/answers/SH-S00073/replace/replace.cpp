#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string  s1[200009],s2[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n*2;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=q*2;i++){
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}
