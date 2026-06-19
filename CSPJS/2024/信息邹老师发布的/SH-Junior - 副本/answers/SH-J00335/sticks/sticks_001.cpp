#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			int p=n/7;
			for(int i=1;i<=p;i++){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		if(n==8){
			cout<<10<<endl;
			continue;
		}
		if(n%7==1){
			int p=(n-8)/7;
			cout<<"10";
			for(int i=1;i<=p;i++){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		if(n==7){
			cout<<8<<endl;
			continue;
		}
		if(n==9){
			cout<<18<<endl;
			continue;
		}
		if(n==10){
			cout<<22<<endl;
			continue;
		}
		if(n==11){
			cout<<20<<endl;
			continue;
		}
		if(n==12){
			cout<<28<<endl;
			continue;
		}
		if(n==13){
			cout<<68<<endl;
			continue;
		}
		if(n==14){
			cout<<88<<endl;
			continue;
		}
		if(n==15){
			cout<<108<<endl;
			continue;
		}
		if(n==16){
			cout<<188<<endl;
			continue;
		}
		if(n==17){
			cout<<200<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
		if(n==19){
			cout<<288<<endl;
			continue;
		}
		if(n==20){
			cout<<808<<endl;
			continue;
		}
		int p,n1=n;
		if(n%7==0) p=n1/7;
		else p=n1/7+1;
		for(int i=1;i<=p;i++){
			int minn=1e6,numm;
			if(i==1){
				for(int j=1;j<=9;j++){
					int cnt;
					if((n1-num[j])%7==0){
						cnt=(n1-num[j])/7;
					}
					else{
						cnt=(n1-num[j])/7+1;
					}
					if(cnt<minn){
						minn=cnt;
						numm=j;
					}
				}
			}
			else{
				for(int j=0;j<=9;j++){
					int cnt;
					if((n1-num[j])%7==0){
						cnt=(n1-num[j])/7;
					}
					else{
						cnt=(n1-num[j])/7+1;
					}
					if(cnt<minn){
						minn=cnt;
						numm=j;
					}
				}
			}
			n1-=num[numm];
			cout<<numm;
		}
		cout<<endl;
	}
	return 0;
}
