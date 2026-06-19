#include<iostream>
using namespace std;
int test(long long m){
	int sum=0;
	while(m){
		int n=m%10;
		if(n==1){
			sum+=2;
		}else if(n==2){
			sum+=5;
		}else if(n==3){
			sum+=5;
		}else if(n==4){
			sum+=4;
		}else if(n==5){
			sum+=5;
		}else if(n==6){
			sum+=6;
		}else if(n==7){ 
			sum+=3;
		}else if(n==8){
			sum+=7;
		}else if(n==9){
			sum+=6;
		}else if(n==0){
			sum+=6;
		}
		m/=10;
	}
	return sum;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7==0){
			int q=n/7;
			while(q--){
				cout<<8;
			}
			continue;
		}
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		for(long long i=1;i<9223372036854775807;i++){
			int m=test(i);
			if(m==n){
				cout<<i<<endl;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
