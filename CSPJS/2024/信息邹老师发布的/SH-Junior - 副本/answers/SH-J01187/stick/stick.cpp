#include<bits/stdc++.h>
using namespace std;
int T,n;
int stk[10]={6,2,5,5,4,5,6,3,7,6};
void solve(int x){
	if(x==1){
		cout<<-1;
		return;
	}
	int x8=x/7;
	if(x%7!=0){
		if(x%7==1)x8--,cout<<16;
		if(x%7==2)cout<<1;
		if(x%7==3)cout<<7;
		if(x%7==4)x8--,cout<<20;
		if(x%7==5)cout<<2;
		if(x%7==6)cout<<6;
	}
	for(int i=1;i<=x8;i++)cout<<8;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		solve(n);
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
