#include<bits/stdc++.h>
using namespace std;
bool poke[4][15]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
    int n;
    cin>>n;
    int res=52;
    for(int i=0;i<n;i++){
    	char a,b;
    	cin>>a>>b;
    	int num;
    	if(b=='A') num=1;
    	else if(b=='T') num=10;
    	else if(b=='J') num=11;
    	else if(b=='Q') num=12;
    	else if(b=='K') num=13;
    	else{
    		num = b-'0';
		}
		int num1;
		if(a=='D') num1=0;
		else if(a=='C') num1=1;
		else if(a=='H') num1=2;
		else num1=3;
		if(!poke[num1][num]){
			poke[num1][num]=1;
			res--;
		}
	}
	cout<<res;
}
