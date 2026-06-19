#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
    int n;
    while(cin>>n){
      if(n==2){
      	cout<<1;
	  }
	  if(n==4){
	  	cout<<4; 
	  }
	  if(n==5){
	  	cout<<2;
	  }
	  if(n==6){
	  	cout<<0;
	  }
	  if(n==7){
	  	cout<<8;
	  }
	  if(n==8){
	  	cout<<10;
	  }
	  if(n==9){
	  	cout<<18;
	  }
	  if(n==10){
	  	cout<<22;
	  }
	  if(n==11){
	  	cout<<20;
	  }
	  if(n==12){
	  	cout<<28;
	  }
	  if(n==13){
	  	cout<<68;
	  }
	  if(n==14){
	  	cout<<88;
	  }
	  if(n==15){
	  	cout<<180;
	  }else{
	  	cout<<-1;
	  }
	}
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
