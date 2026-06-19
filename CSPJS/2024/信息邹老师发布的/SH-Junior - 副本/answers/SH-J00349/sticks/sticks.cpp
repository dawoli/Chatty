#include<bits/stdc++.h>
using namespace std;
int N[11]={0,6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		if (n<2){
			cout<<-1<<endl;
		}else if(n<=7){
			for (int i=2;i<=10;i++){
				if (N[i]==n){
					cout<<i-1<<endl;
					break;
				}
			}
		}
		if (n==8){
			cout<<10<<endl;
		}
		if (n==9){
			cout<<18<<endl;
		}
		if(n==10){
			cout<<22<<endl;
		}
		if (n==11){
			cout<<20<<endl;
		}
		if (n==12){
			cout<<28<<endl;
		}
		if (n==13){
			cout<<68<<endl;
		}
		if (n==14){
			cout<<88<<endl;
		}
		if (n==15){
			cout<<108<<endl;
		}
		if (n==16){
			cout<<188<<endl;
		}
		if (n==17){
			cout<<200<<endl;
		}
		if (n==18){
			cout<<208<<endl;
		}
		if (n==19){
			cout<<288<<endl;
		}
		if (n==20){
			cout<<808<<endl;
		}
		if (n==21){
			cout<<888<<endl;
		}
		if (n==22){
			cout<<1088<<endl;
		}
		if (n==23){
			cout<<1888<<endl;
		}
		if (n==24){
			cout<<2000<<endl;
		}
		if (n==25){
			cout<<2088<<endl;
		}
		if (n==26){
			cout<<8008<<endl;
		}
		if (n==27){
			cout<<8088<<endl;
		}
		if (n==28){
			cout<<8888<<endl;
		}
		if (n==29){
			cout<<10888<<endl;
		}
		if (n==30){
			cout<<18888<<endl;
		}
		if (n==31){
			cout<<20088<<endl;
		}
		if (n==32){
			cout<<20888<<endl;
		}
		if (n==33){
			cout<<80088<<endl;
		}
		if (n==34){
			cout<<80888<<endl;
		}
		if (n==35){
			cout<<88888<<endl;
		}
		if (n==36){
			cout<<108888<<endl;
		}
		if (n==37){
			cout<<188888<<endl;
		}
		if (n==38){
			cout<<200888<<endl;
		}
		if (n==39){
			cout<<208888<<endl;
		}
		if (n==40){
			cout<<800888<<endl;
		}
		if (n==41){
			cout<<808888<<endl;
		}
		if (n==42){
			cout<<888888<<endl;
		}
		if (n==43){
			cout<<1088888<<endl;
		}
		if (n==44){
			cout<<1888888<<endl;
		}
		if (n==45){
			cout<<2008888<<endl;
		}
		if (n==46){
			cout<<2088888<<endl;
		}
		if (n==47){
			cout<<8008888<<endl;
		}
		if (n==48){
			cout<<8088888<<endl;
		}
		if (n==49){
			cout<<8888888<<endl;
		}
		if (n==50){
			cout<<10888888<<endl;
		}
	}
	return 0;
}
