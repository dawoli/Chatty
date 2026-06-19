#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string l[62];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	int poker[62]={0},sum=0;
	for(int i=0;i<n;i++){
		char a=l[i][0],b=l[i][1];
		int num=0;
		if(a=='D'){
			num+=0;
		}else if(a=='C'){
			num+=13;
		}else if(a=='H'){
			num+=26;
		}else if(a=='S'){
			num+=39;
		}
		
		if(b=='A'){
			num+=1;
		}else if(b=='T'){
			num+=10;
		}else if(b=='J'){
			num+=11;
		}else if(b=='Q'){
			num+=12;
		}else if(b=='K'){
			num+=13;
		}else{
			num+=b;
			num-='0';
		}
		poker[num]+=1;
	}
	for(int i=1;i<=52;i++){
		if(poker[i]!=0){
			sum++;
		}
	}
	sum=52-sum;
	cout<<sum;
	return 0;
}
