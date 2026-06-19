#include<bits/stdc++.h>
using namespace std;

int n,cnt=0;
bool cards[4][13];

void update(char color,char num){
	int c=0,n=1;
	if (color=='C') c=1;
	else if (color=='H') c=2;
	else if (color=='S') c=3;
	
	if (num=='T') n=10;
	else if (num=='J') n=11;
	else if (num=='Q') n=12;
	else if (num=='K') n=13;
	else if (num!='A') n=num-'0';
	
	if (cards[c][n-1]) return;
	cards[c][n-1]=true;
	cnt++;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		char color,num;
		cin>>color>>num;
		update(color,num);
	}
	
	cout<<52-cnt<<'\n';
} 
