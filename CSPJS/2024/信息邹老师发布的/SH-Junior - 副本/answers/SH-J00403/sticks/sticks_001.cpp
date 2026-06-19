#include<bits/stdc++.h>
using namespace std;
int a[6][15];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,c,t;
	string s;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>c;
		if(c<=1){
			cout<<-1<<endl;
			continue;
		}
		else if(c%7==0){
			for(int j=0;j<c/7;j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c%7==1){
			cout<<1;
			cout<<0;
			for(int j=0;j<(c/7-1);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c==2){
			cout<<1<<endl;
			continue;
		}
		else if(c==3){
			cout<<7<<endl;
			continue;
		}
		else if(c==4){
			cout<<4<<endl;
			continue;
		}
		else if(c==5){
			cout<<2<<endl;
			continue;
		}
		else if(c==6){
			cout<<6<<endl;
			continue;
		}
		else if(c==7){
			cout<<8<<endl;
			continue;
		}
		else if(c==8){
			cout<<10<<endl;
			continue;
		}
		else if(c==9){
			cout<<18<<endl;
			continue;
		}
		else if(c==10){
			cout<<22<<endl;
			continue;
		}
		else if(c==11){
			cout<<20<<endl;
			continue;
		}
		else if(c==12){
			cout<<28<<endl;
			continue;
		}
		else if(c==13){
			cout<<68<<endl;
			continue;
		}
		else if(c==14){
			cout<<88<<endl;
			continue;
		}
		else if(c==15){
			cout<<108<<endl;
			continue;
		}
		else if(c==16){
			cout<<188<<endl;
			continue;
		}
		else if(c==17){
			cout<<200<<endl;
			continue;
		}
		else if(c==18){
			cout<<208<<endl;
			continue;
		}
		else if(c==19){
			cout<<288<<endl;
			continue;
		}
		else if(c==20){
			cout<<688<<endl;
			continue;
		}
		else if(c%7==2){
			cout<<1;
			for(int j=0;j<(c/7);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c%7==3){
			cout<<2<<0<<0;
			for(int j=0;j<(c/7-2);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c%7==4){
			cout<<2<<0;
			for(int j=0;j<(c/7-1);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c%7==5){
			cout<<2;
			for(int j=0;j<(c/7);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(c%7==6){
			cout<<6;
			for(int j=0;j<(c/7);j++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}
/*
5
1
2
3
6
18
*/
