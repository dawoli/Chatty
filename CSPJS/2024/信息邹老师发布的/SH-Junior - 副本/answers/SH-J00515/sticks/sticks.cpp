#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int T;
void solve1(){
	int times=n/7;
	for (int i=0;i<times;i++){
		cout<<8;
	}
}
void solve2(){
	int times=n/7;
	cout<<10;
	for (int i=1;i<times;i++){
		cout<<8;
	}
}
void solve3(){
	if (n%7==0){
		int times=n/7;
		for (int i=0;i<times;i++){
			cout<<8;
		}
	}
	else if (n%5==0){
		int times=n/5;
		for (int i=0;i<times;i++){
			cout<<2;
		}
	}
	else if (n%6==0){
		int times=n/6;
		cout<<6;
		for (int i=1;i<times;i++){
			cout<<0;
		}
	}
	else if (n%3==0){
		int times=n/3;
		for (int i=0;i<times;i++){
			cout<<7;
		}
	}
	else if (n%4==0){
		int times=n/4;
		for (int i=0;i<times;i++){
			cout<<4;
		}
	}
	else if (n%2==0){
		int times=n/2;
		for (int i=0;i<times;i++){
			cout<<1;
		}
	}
	
	else {
		int tim=1000000009;
		int num1=0;
		int num2=0;
		for (int i=8;i<=13;i++){
			int nn=n-i;
			for (int j=2;j<=7;i++){
				if (nn%j==0){
					if (nn/j<tim){
						tim=nn/j;
						num1=j;
						num2=i;
					}
				}
			}
		}
		if (num2==8){
			cout<<10;
		}
		else if (num2==9){
			cout<<18;
		}
		else if (num2==10){
			cout<<22;
		}
		else if (num2==11){
			cout<<20;
		}
		else if (num2==12){
			cout<<28;
		}
		else if (num2==13){
			cout<<68;
		}
		if (num1==7){
			int times=n/7;
			for (int i=0;i<times;i++){
				cout<<8;
			}
		}
		else if (num1==5){
			int times=n/5;
			for (int i=0;i<times;i++){
				cout<<2;
			}
		}
		else if (num1==6){
			int times=n/6;
			cout<<6;
			for (int i=1;i<times;i++){
				cout<<0;
			}
		}
		else if (num1==3){
			int times=n/3;
			for (int i=0;i<times;i++){
				cout<<7;
			}
		}
		else if (num1==4){
			int times=n/4;
			for (int i=0;i<times;i++){
				cout<<4;
			}
		}
		else if (num1==2){
			int times=n/2;
			for (int i=0;i<times;i++){
				cout<<1;
			}
		}
		
	} 
}
void solve4(){
	if (n<=1){
		cout<<-1;
	}
	else if (n==2){
		cout<<1;
	}
	else if (n==3){
		cout<<7;
	}
	else if (n==4){
		cout<<4;
	}
	else if (n==5){
		cout<<2;
	}
	else if (n==6){
		cout<<6;
	}
	else if (n==7){
		cout<<8;
	}
	else if (n==8){
		cout<<10;
	}
	else if (n==9){
		cout<<18;
	}
	else if (n==10){
		cout<<22;
	}
	else if (n==11){
		cout<<20;
	}
	else if (n==12){
		cout<<27;
	}
	else if (n==13){
		cout<<68;
	}
	
	else if (n==14){
		cout<<100;
	}
	else if (n==15){
		cout<<108;
	}
	else if (n==16){
		cout<<220;
	}
	else if (n==17){
		cout<<227;
	}
	else if (n==18){
		cout<<208;
	}
	else if (n==19){
		cout<<668;
	}
	else if (n==20){
		cout<<827;
	}
}
int main(){
	freopen ("sticks.in","r",stdin);
	freopen ("sticks.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		
		if (n<=1){
			cout<<-1<<endl;
		}
		else if (n<=20){
			solve4();
			cout<<endl;
		}
		else if (n%7==0){
			solve1();
			cout<<endl;
		}
		else if (n%7==1){
			solve2();
			cout<<endl;
		}
		else{
			if (n<=1){
				cout<<-1<<endl;
			}
			else{
				solve3();
				cout<<endl;
			}
		}
	}
	return 0;
} 
