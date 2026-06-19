#include<iostream>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	bool lis[54];
	for(int i=1;i<=52;i++){
		lis[i]=1;
	}
	int a;
	cin>>a;
	string poker;
	int sum=52;
	for(int i=0;i<a;i++){
		cin>>poker;
		int pn=0;
		if(poker[0]=='C'){
			pn+=13;
		}else if(poker[0]=='H'){
			pn+=26;
		}else if(poker[0]=='S'){
			pn+=39;
		}
		if(poker[1]=='A'){
			pn++;
		}else if(poker[1]=='T'){
			pn+=10;
		}else if(poker[1]=='J'){
			pn+=11;
		}else if(poker[1]=='Q'){
			pn+=12;
		}else if(poker[1]=='K'){
			pn+=13;
		}else if(poker[1]=='2'){
			pn+=2;
		}else if(poker[1]=='3'){
			pn+=3;
		}else if(poker[1]=='4'){
			pn+=4;
		}else if(poker[1]=='5'){
			pn+=5;
		}else if(poker[1]=='6'){
			pn+=6;
		}else if(poker[1]=='7'){
			pn+=7;
		}else if(poker[1]=='8'){
			pn+=8;
		}else if(poker[1]=='9'){
			pn+=9;
		}
		if(lis[pn]){
			sum--;
			lis[pn]=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
