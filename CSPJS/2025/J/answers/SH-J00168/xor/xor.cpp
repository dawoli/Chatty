#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[2000000],b[2000000];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0) return false;
	}
	return true;
}
bool checkk(){
	for(int i=1;i<=n;i++){
	if(a[i]!=1) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(checkk()){
		cout<<1;
		return 0;}
	else if(check()){
		if(k==0){
			cout<<2;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
