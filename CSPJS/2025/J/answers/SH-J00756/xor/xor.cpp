#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m;cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	if(n==1){
		if(a[0]==k)cout<<"1";
		else cout<<"0";
	}
	else{
		if(a[1]==a[0])m=1;
		else m=0;
		if(m==k)cout<<"1";
		else cout<<"0";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
