#include<bits/stdc++.h> 
using namespace std;
long long n,t,a[25];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	a[2]=3,a[3]=7;
	a[4]=4,a[5]=2,a[6]=6;
	a[7]=8,a[8]=10,a[9]=18;
	a[10]=23,a[11]=20,a[12]=28,a[13]=68,a[14]=88;
	while(t--){
		cin>>n;
		int w;
		if(n%7==0){
			w=n/7;
		}else{
			w=n/7+1;
		}
		if(n==1){
			cout<<-1<<endl;
			continue;
		}else if(n==2){
			cout<<1<<endl;
			continue;
		}else if(n==3){
			cout<<7<<endl;
			continue;
		}else if(n==4){
			cout<<4<<endl;
			continue;
		}else if(n==5){
			cout<<2<<endl;
			continue;
		}else if(n==6){
			cout<<6<<endl;
			continue;
		}else if(n==7){
			cout<<8<<endl;
			continue;
		}else if(n==8){
			cout<<10<<endl;
			continue;
		}else if(n==9){
			cout<<18<<endl;
			continue;
		}else if(n==10){
			cout<<23<<endl;
			continue;
		}else if(n==11){
			cout<<20<<endl;
			continue;
		}else if(n==12){
			cout<<28<<endl;
			continue;
		}else if(n==13){
			cout<<68<<endl;
			continue;
		}else if(n==14){
			cout<<88<<endl;
			continue;
		}else if(n==15){
			cout<<108<<endl;
			continue;
		}else if(n==16){
			cout<<220<<endl;
			continue;
		}else if(n==17){
			cout<<228<<endl;
			continue;
		}else if(n==18){
			cout<<208<<endl;
			continue;
		}else if(n==19){
			cout<<288<<endl;
			continue;
		}else if(n==20){
			cout<<688<<endl;
			continue;
		}else if(n==22){
			cout<<2288<<endl;
			continue;
		}else if(n%7==0){
			for(int i=1;i<=w;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}else if(n%7==1){
			cout<<10;
			w-=2;
			for(int i=1;i<=w;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		for(int i=1;i<=w;i++){
			int z=n-(w-i)*7;
			if(z==6 and i!=1){
				cout<<0;
			}else{
				if(z<=20){
					cout<<a[z];
				}
			}
			n-=z;
			if(n%7==0){
				for(int j=1;j<=w-i;j++){
					cout<<8;
				}
				break;
			}
		}
		cout<<endl;
	}
	return 0;
}
