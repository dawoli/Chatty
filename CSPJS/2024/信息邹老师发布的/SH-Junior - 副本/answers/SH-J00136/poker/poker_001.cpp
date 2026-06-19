#include<bits/stdc++.h>
using namespace std;
int n;
bool fl[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=52;i++){
		fl[i]=false;
	}
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int pp,pl;
		if(a=='D'){
			pp=0;
		}
		else if(a=='C'){
			pp=1;
		}
		else if(a=='H'){
			pp=2;
		}
		else{
			pp=3;
		}
		if(b=='A'){ 
			pl=1;
		} 
		else if(b=='T'){ 
			pl=10;
		}
		else if(b=='J'){ 
			pl=11;
		} 
		else if(b=='Q'){ 
			pl=12;
		} 
		else if(b=='K'){ 
			pl=13;
		}
		else{
			pl=b-'0';
		}
		fl[pp*13+pl]=true;
	}
	int cnt=0;
	for(int i=1;i<=52;i++){
		if(fl[i]==false){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
