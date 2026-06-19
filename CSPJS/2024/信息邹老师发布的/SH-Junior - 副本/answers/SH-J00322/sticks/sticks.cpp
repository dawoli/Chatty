#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
void freopen(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
}
void work(){
	if(n==1) cout<<-1<<"\n";
	else if(n==2) cout<<1<<"\n";
	else if(n==3) cout<<7<<"\n";
	else if(n==4) cout<<4<<"\n";
	else if(n==5) cout<<2<<"\n";
	else if(n==6) cout<<6<<"\n";
	else if(n==7) cout<<8<<"\n";
}
bool check(int x){
	int w=0,res=0;
	while(x>9){
		w=x%10;
		if(w==1) res+=2;
		else if(w==2 || w==3 ||w==5) res+=5;
		else if(w==4 )res+=4;
		else if(w==6 || w==9 || w==0) res+=6;
		else if(w==7) res+=3;
		else if(w==8) res+=7;
		x/=10;
	}
	if(x==1) res+=2;
	else if(x==2 || x==3 ||x==5) res+=5;
	else if(x==4 )res+=4;
	else if(x==6 || x==9 || w==0) res+=6;
	else if(x==7) res+=3;
	else if(x==8) res+=7;
	if(res==n) return 1;
	else return 0;
}
void work1(){
	int ans=0,b=1;
	int l=n/7,y=n%7;
	if(y==1) l--;
	while(l--) ans+=8*b,b*=10;
	if(y==1) ans+=10*b;
	else{
		 if(y==2) ans+=1*b;
		else if(y==3) ans+=7*b;
		else if(y==4) ans+=4*b;
		else if(y==5) ans+=2*b;
		else if(y==6) ans+=6*b;
		else if(y==7) ans+=8*b;
	}
	//cout<<ans;
	for(int i=1;i<=ans;i++){
		if(check(i)){
			cout<<i<<"\n";
			return ;
		}
	}
}
void work2(){
	int l=n/7;
	for(int i=1;i<=l;i++) cout<<8;
	cout<<"\n";
}
void work3(){
	int l=(n/7)-1;
	cout<<1<<0;
	for(int i=1;i<=l;i++) cout<<8;
	cout<<"\n";
}
int main(){
	freopen();
	sync();
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=7) work();
		else if(n<=50) work1();
		else if(n%7==0) work2();
		else if(n%7==1) work3();
	}
	return 0;
}
