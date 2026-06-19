#include <bits/stdc++.h> 
using namespace std;
int t,n;      //0  1  2 3 4 5 6 7 8  9  10 11 12 13 14 15  16  17  18  19  20  21  22
int ans[10005]={-1,-1,1,7,4,2,6,8,10,17,22,20,28,68,88,108,202,200,208,288,688,888,1008};
void func(int a){
	if(a%7==0){
		for(int i=0;i<a/7;i++) cout<<'8';
		cout<<endl;
		return ;
	}
	else if(a%7==1&&a!=1&&a!=8){
		cout<<'1';
		for(int i=0;i<a/7-1;i++) cout<<'0';
		cout<<'8';
		return ;
	}
	cout<<ans[a]<<endl;
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		func(n);
	}
	return 0;
}
