#include<bits/stdc++.h>
using namespace std;
void f(int n){
	int m=n/7;
	n=n-m*7;
	if(n==1){
		if(m>0){
		cout<<"10";
		}
		else{
			cout<<"-1";
			return;
		}
}
	if(n==2){
		if(m>0){
		cout<<"18";
		}
		else{
			cout<<"1";
		}
}
	if(n==3){
		if(m>0){
		cout<<"22";
		}
		else{
			cout<<"7";
		}}
	if(n==4){
		if(m>0){
		cout<<"20";
		}
		else{
			cout<<"4";
		}}
	if(n==5){
		if(m>0){
		cout<<"28";
		}
		else{
			cout<<"2";
		}}
	if(n==6){
		if(m>0){
		cout<<"68";
		}
		else{
			cout<<"6";
		}}
	if(n==0) cout<<"8";
	for(int i=1;i<m;i++){
		cout<<"8";
	}
	cout<<endl;
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;cin>>t;
	for(int i=0;i<t;i++){
		int n;cin>>n;
		f(n); 
	}
	return 0;
}
