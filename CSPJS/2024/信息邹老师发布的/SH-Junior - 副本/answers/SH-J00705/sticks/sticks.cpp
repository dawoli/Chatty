#include<bits/stdc++.h>
using namespace std;
#define int long long
int z;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>z;	
	for(int j = 0;j<z;j++){
		int a;
		cin>>a;
		if(a<=50){
			if(a==0) cout<<-1<<endl;
			if(a==1) cout<<-1<<endl;
			if(a==2) cout<<1<<endl;
			if(a==3) cout<<7<<endl;
			if(a==4) cout<<4<<endl;
			if(a==5) cout<<2<<endl;
			if(a==6) cout<<6<<endl;
			if(a==7) cout<<8<<endl;
			if(a==8) cout<<10<<endl;
			if(a==9) cout<<18<<endl;
			if(a==10) cout<<22<<endl;
			if(a==11) cout<<20<<endl;
			if(a==12) cout<<28<<endl;
			if(a==13) cout<<68<<endl;
			if(a==14) cout<<88<<endl;
			if(a==15) cout<<108<<endl;
			if(a==16) cout<<188<<endl;
			if(a==17) cout<<200<<endl;
			if(a==18) cout<<208<<endl;
			if(a==19) cout<<288<<endl;
			if(a==20) cout<<688<<endl;
			if(a==21) cout<<888<<endl;
			if(a==22) cout<<1088<<endl;
			if(a==23) cout<<1888<<endl;
			if(a==24) cout<<2288<<endl;
			if(a==25) cout<<2088<<endl;
			if(a==26) cout<<2888<<endl;
			if(a==27) cout<<6888<<endl;
			if(a==28) cout<<8888<<endl;
			if(a==29) cout<<10888<<endl;
			if(a==30) cout<<18888<<endl;
			if(a==31) cout<<22888<<endl;
			if(a==32) cout<<20888<<endl;
			if(a==33) cout<<28888<<endl;
			if(a==34) cout<<68888<<endl;
			if(a==35) cout<<88888<<endl;
			if(a==36) cout<<108888<<endl;
			if(a==37) cout<<188888<<endl;
			if(a==38) cout<<228888<<endl;
			if(a==39) cout<<208888<<endl;
			if(a==40) cout<<288888<<endl;
			if(a==41) cout<<688888<<endl;
			if(a==42) cout<<888888<<endl;
			if(a==43) cout<<1088888<<endl;
			if(a==44) cout<<1888888<<endl;
			if(a==45) cout<<2288888<<endl;
			if(a==46) cout<<2088888<<endl;
			if(a==47) cout<<2888888<<endl;
			if(a==48) cout<<6888888<<endl;
			if(a==49) cout<<8888888<<endl;
			if(a==50) cout<<10888888<<endl;
			continue;
		}
		if(a%7==0){
			int n = a/7;
			for(int i = 0;i<n;i++) {
				cout<<8;
			}
			cout<<endl; 
			continue;
		}if(a%7==1){
			int n = a/7-1;
			cout<<10;
			for(int i = 0;i<n;i++) {
				cout<<8;
			}
			cout<<endl;
			continue;
		}if(a%7==2){
			int n = a/7;
			cout<<1;
			for(int i = 0;i<n;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}if(a%7==3){
			int n = a/7-1;
			cout<<22;
			for(int i = 0;i<n;i++) {
				cout<<8;
			}
			cout<<endl;
			continue;
		}if(a%7==4){
			int n = a/7-1;
			cout<<20;
			for(int i = 0;i<n;i++) {
				cout<<8;
			}
			cout<<endl;
			continue;
		}if(a%7==5){
			int n = a/7;
			cout<<2;
			for(int i = 0;i<n;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}if(a%7==6){
			int n = a/7;
			cout<<6;
			for(int i = 0;i<n;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
} 
