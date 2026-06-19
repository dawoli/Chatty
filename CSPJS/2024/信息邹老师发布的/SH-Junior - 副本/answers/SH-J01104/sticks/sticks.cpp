#include<bits/stdc++.h>
using namespace std;
long long maxn=-2147483648,minn=2147483647,ans=0;
long long a[1005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long n;
		cin>>n;
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
		}
		else if(n%7==1&&n!=1){
			cout<<10;
			for(int i=0;i<(n/7)-1;i++){
				cout<<8;
			}
		}
		else if(n<=1){
			cout<<-1;
		}
		else if(n==2){
			cout<<1;
		}
		else if(n==3){
			cout<<7;
		}
		else if(n==4){
			cout<<4;
		}
		else if(n==5){
			cout<<2;
		}
		else if(n==6){
			cout<<6;
		}
		else if(n==9){
			cout<<18;
		}
		else if(n==10){
			cout<<22;
		}
		else if(n==11){
			cout<<20;
		}
		else if(n==12){
			cout<<28;
		}
		else if(n==13){
			cout<<68;
		}
		else if(n==16){
			cout<<188;
		}
		else if(n==17){
			cout<<200;
		}
		else if(n==18){
			cout<<208;
		}
		else if(n==19){
			cout<<288;
		}
		else if(n==20){
			cout<<688;
		}
		else if(n%7==2&&n>=22){
			cout<<1;
			for(int i=0;i<(n/7);i++){
				cout<<8;
			}
		}
		else if(n%7==3&&n>=22){
			cout<<200;
			for(int i=0;i<(n/7)-2;i++){
				cout<<8;
			}
		}
		else if(n%7==4&&n>=22){
			cout<<20;
			for(int i=0;i<(n/7)-1;i++){
				cout<<8;
			}
		}
		else if(n%7==5&&n>=22){
			cout<<2;
			for(int i=0;i<(n/7);i++){
				cout<<8;
			}
		}
		else if(n%7==6&&n>=22){
			cout<<6;
			for(int i=0;i<(n/7);i++){
				cout<<8;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
