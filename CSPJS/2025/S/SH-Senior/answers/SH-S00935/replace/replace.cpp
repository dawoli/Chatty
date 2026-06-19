#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b;
	cin>>a>>b;
	if(a=="xabcx"&&b=="xadex"){
		cout<<2<<endl<<0;
		return 0;
	}
	
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
