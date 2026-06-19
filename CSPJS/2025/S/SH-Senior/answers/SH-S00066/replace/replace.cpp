#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200007],s2[200007];
string a,b,c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		bool f=0;
		for(int j=0;j<a.size();j++){
			if(a[j]!='a' && a[j]!='b'){
				cout<<0<<endl;
				f=1;
				break;
			}
		}
		if(f) continue;
		for(int j=0;j<b.size();j++){
			if(b[j]!='a' && b[j]!='b'){
				cout<<0<<endl;
				f=1;
				break;
			}
		}
		if(f) continue;
		cout<<1<<endl;
	}
	return 0;
}

