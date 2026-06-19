#include<bits/stdc++.h>
using namespace std;
int n,t,a[10]={0,-1,1,7,4,2,6};
void print8(int x){
	for(int i=1;i<=x;++i){
		cout<<8;
	}
	cout<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;++i){
    	cin>>n;
    	if(n<7){
    		cout<<a[n];
		}else if(n%7==0){
    		print8(n/7);
		}else if(n%7==1){
			cout<<10;
			print8(n/7-1);
		}else if(n%7==2){
			cout<<1;
			print8(n/7);
		}else if(n%7==3){
			if(n==10)
		    	cout<<22;
		    else{
		    	cout<<200;
		    	print8(n/7-2);
			}
		}else if(n%7==4){
			cout<<20;
			print8(n/7-1);
		}else if(n%7==5){
			cout<<2;
			print8(n/7);
		}else if(n%7==6){
			cout<<6;
			print8(n/7);
		}
	}
	return 0;
}
