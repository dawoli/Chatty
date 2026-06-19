#include<bits/stdc++.h>
using namespace std;
//int order[]={6,2,5,4,3,7};
void doit(int n){
	int bb=floor(n/7)+1;
	int k=n%7;
	if(k==2) {
		cout<<1;
		k-=2;
	}
	else if(k>2&&k<=5) {
		cout<<2;
		k-=5;
	}
	else if(k==6) {
		cout<<6;
		k-=6;
	}
	if(k==0){
		for(int i=0;i<bb-1;i++){
			printf("%d",8);
		}
	}
	if(k<0){
		if(bb==2){
			if(k==-2){
				cout<<2;
			}
			if(k==-1){
				cout<<0;
			}
		}
		else{
			
			if(k==-2){
				cout<<0;
				cout<<0;
				for(int i=0;i<bb-3;i++)printf("%d",8);
			}
			if(k==-1){
				cout<<0;
				for(int i=0;i<bb-2;i++)printf("%d",8);
			}
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
	    cin>>n;
	    if(n%7==0&&n!=0){
	    	for(int i=0;i<n/7;i++) printf("%d",8);
	    }
	    else if(n%7==1){
	    	if(n==1){
	    		cout<<-1;
			}
			else{
				cout<<1;
	    	    cout<<0;
	    	    for(int i=0;i<(n-8)/7;i++){
	    		    printf("%d",8);
	    	    }
			}
	    }
		else{
			if(n==2){
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
			else if(n==7){
				cout<<8;
			}
			else{
				doit(n);
			}
		}
	    cout<<endl;
	}
}
