#include<iostream>
using namespace std;
int to(char x){
	if(x=='A')return 0;
	else if(x=='T')return 9;
	else if(x=='J')return 10;
	else if(x=='Q')return 11;
	else if(x=='K') return 12;
	else return int(x)-49;
}
int front(char x){
	if(x=='D')return 0;
	else if(x=='C')return 1;
	else if(x=='H')return 2;
	else if(x='S')return 3;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	bool pok[4][13];
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			pok[i][j]=false;
		}
	}
	char ap,ao;
	for(int i=0;i<n;i++){
		cin>>ap>>ao;
		pok[front(ap)][to(ao)]=true;
	}
	int ans=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(!pok[i][j]){
				++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
