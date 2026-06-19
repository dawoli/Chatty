#include<bits/stdc++.h>
using namespace std;
int n,T;
void solveC(){
	if(n==1) cout<<-1<<endl;
	else if(n==2) cout<<1<<endl;
	else if(n==3) cout<<7<<endl;
	else if(n==4) cout<<4<<endl;
	else if(n==5) cout<<5<<endl;
	else if(n==6) cout<<6<<endl;
	else if(n==7) cout<<8<<endl;
}
void solveA(){
	for(int i=1;i<=n/7;i++) cout<<8;
	cout<<endl;
}
void solveB(){
	cout<<10;
	for(int i=1;i<n/7;i++) cout<<8;
	cout<<endl;
}
void solve(){
	int dgt=n/7,dgt2=0;
	if(n%7!=0) dgt++; dgt2=dgt;
	for(int i=1;i<=dgt2;i++){
		int mnus=n-7*(dgt-1);
		if(i==1){
			if(mnus==1||mnus==2) cout<<1,n-=2;
			else if(mnus<=5) cout<<2,n-=5;
			else if(mnus==6) cout<<6,n-=6;
			else cout<<8,n-=7;
		}else if(i!=dgt2){
			if(mnus<=6) cout<<0,n-=6;
			else cout<<8,n-=7;
		}else{
			if(mnus==1) cout<<-1;
			else if(mnus==2) cout<<1;
			else if(mnus==3) cout<<7;
			else if(mnus==4) cout<<4;
			else if(mnus==5) cout<<2;
			else if(mnus==6) cout<<0;
			else cout<<8;
		}
		dgt--;
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=7) solveC();
		else if(n%7==0&&n>=100) solveA();
		else if(n%7==1&&n>=100) solveB();
		else solve();
	}
	return 0;
}

