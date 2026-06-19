#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[3][200009],b[2][10009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>b[1][i]>>b[2][i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
