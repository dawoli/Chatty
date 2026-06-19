#include<bits/stdc++.h>
using namespace std;
//0--6 1--2 2--5 3--5(useless) 4--4 5--5(useless) 6--6 7--3 8--7 9--6(useless)
//1--2 7--3 4--4 2--5 0--6(6--6) 8--7
void solve(){
	int n;
	cin>>n;
	if(n%7==0) {
		for(int i=1;i<=n/7;i++) cout<<8;
		cout<<"\n";
		return ;
	}
	else if(n<7){
		if(n==1) cout<<-1<<"\n";
		else if (n==2) cout<<1<<"\n";
		else if(n==3) cout<<7<<"\n";
		else if(n==4) cout<<4<<"\n";
		else if(n==5) cout<<2<<"\n";
		else if(n==6) cout<<6<<"\n";
		return ; 
	}
	else if(n==10) {
		cout<<22<<"\n";
		return ;
	}
	int mini=n%7;//1-6
	int min8=n/7;
	int cha=0;
	if(mini==1) { cha=1;cout<<10; } 
	else if(mini==2) { cout<<1; }
	else if(mini==3) { cha=2;cout<<200; }
	else if(mini==4) { cha=1;cout<<20; }
	else if(mini==5) { cout<<2; }
	else if(mini==6) { cout<<6; }
	min8-=cha;
	for(int i=1;i<=min8;i++) cout<<8;
	cout<<"\n";
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
