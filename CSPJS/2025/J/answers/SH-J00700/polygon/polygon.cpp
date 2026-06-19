#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n;
int Cnt=0;
int main(){
freopen("polygon.in","r",stdout);
freopen("polygon.in","w",stdout);
	cin>>n;
	int s[n];
	for(int i=1;i<n;i++){
		cin>>s[i];}
		if(n==3){
int H=	s[1]+s[2]+s[3];
	if(H>2*s[1]&&H>2*s[2]&&H>2*s[3])
	cout<<"1";
	else cout<<"0";}
	if(n==4){
	int H=	s[1]+s[2]+s[3];
	if(H>2*s[1]&&H>2*s[2]&&H>2*s[3])
	Cnt++;
	int Q=s[1]+s[2]+s[4];
	if(Q>2*s[1]&&Q>2*s[2]&&Q>2*s[4])
	Cnt++;
	int W=s[1]+s[3]+s[4];
	if(W>2*s[1]&&W>2*s[3]&&W>2*s[3])
	Cnt++;
	int E=s[2]+s[3]+s[4];
	if(E>2*s[4]&&E>2*s[2]&&E>2*s[3])
	Cnt++;
	int R=s[1]+s[2]+s[3]+s[4];
	if(R>2*s[1]&&R>2*s[2]&&R>2*s[3]&&R>2*s[4])
	Cnt++;
	cout<<Cnt;
	}
	if(n==5){
	int H=s[1]+s[2]+s[3];
	if(H>2*s[1]&&H>2*s[2]&&H>2*s[3])
	Cnt++;
	int Q=s[1]+s[2]+s[4];
	if(Q>2*s[1]&&Q>2*s[2]&&Q>2*s[4])
	Cnt++;
	int W=s[1]+s[3]+s[4];
	if(W>2*s[1]&&W>2*s[3]&&W>2*s[3])
	Cnt++;
	int E=s[2]+s[3]+s[4];
	if(E>2*s[4]&&E>2*s[2]&&E>2*s[3])
	Cnt++;
	H=s[1]+s[2]+s[5];
	if(H>2*s[1]&&H>2*s[2]&&H>2*s[3])
	Cnt++;
	Q=s[1]+s[3]+s[5];
	if(Q>2*s[1]&&Q>2*s[2]&&Q>2*s[4])
	Cnt++;
	W=s[1]+s[4]+s[5];
	if(W>2*s[1]&&W>2*s[3]&&W>2*s[3])
	Cnt++;
	E=s[2]+s[3]+s[4]+s[5];
	if(E>2*s[4]&&E>2*s[2]&&E>2*s[3]&&E>2*s[5])
	Cnt++;
	int R=s[1]+s[2]+s[5]+s[4];
	if(R>2*s[1]&&R>2*s[2]&&R>2*s[5]&&R>2*s[4])
	Cnt++;
	R=s[1]+s[3]+s[5]+s[4];
	if(R>2*s[1]&&R>2*s[2]&&R>2*s[5]&&R>2*s[4])
	Cnt++;
	R=s[1]+s[3]+s[5]+s[4]+s[2];
	if(R>2*s[1]&&R>2*s[2]&&R>2*s[5]&&R>2*s[4]&&R>2*s[3])
	Cnt++;
	cout<<Cnt;
	}
	return 0;
}

