#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			int now=n/7;
			for(int i=1;i<=now;i++){
				putchar('8');
			}
		}else if(n%7==1){
			int now=n/7;
			if(now==0){
				cout<<"-1"<<endl;
				continue;
			}
			cout<<10;
			for(int i=1;i<now;i++){
				putchar('8');
			}
		}else if(n%7==2){
			int now=n/7;
			cout<<1;
			for(int i=1;i<=now;i++){
				putchar('8');
			}
		}else if(n%7==3){
			int now=n/7;
			if(now==0){
				cout<<7<<endl;
				continue;
			}else if(now==1){
				putchar('2');putchar('2');
				continue;
			}
			cout<<200;
			for(int i=1;i<now-1;i++){
				putchar('8');
			}
		}else if(n%7==4){
			int now=n/7;
			if(now==0){
				putchar('4');
				continue;
			}
			putchar('2');putchar('0');
			for(int i=1;i<now;i++){
				putchar('8');
			}
		}else if(n%7==5){
			int now=n/7;
			putchar('2');
			for(int i=1;i<=now;i++){
				putchar('8');
			}
		}else{
			int now=n/7;
			putchar('6');
			for(int i=1;i<=now;i++){
				putchar('8');
			}
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
