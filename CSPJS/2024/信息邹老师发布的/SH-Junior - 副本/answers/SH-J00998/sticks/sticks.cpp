#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    int t,n,x,y,flag;
    cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;flag=0;
		if(n==1){
			cout<<-1<<endl;
		}else if(n==3){
			cout<<7<<endl;
		}else if(n==4){
			cout<<4<<endl;
		}
		else{
			x=(n-1)/7+1;
		while(n>0){
			if(double(1+(n-2)/7.0)<=double(x)){
				cout<<1;
				n-=2;
				x--;
			}else if(double(1+(n-5)/7.0)<=double(x)){
				cout<<2;
				n-=5;
				x--;
			}else if(double(1+(n-6)/7.0)<=double(x)){
				if(flag==0){
					cout<<6;
				}else{
	    			cout<<0;
				}
				n-=6;
    			x--;
    		}else{
    			cout<<8;
    			n-=7;
	        	x--;
	    	}flag=1;			     			
	    }cout<<endl;
		}		
	} 
	return 0;
}

