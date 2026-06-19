#include<bits/stdc++.h>
using namespace std; 
int t,n,s,m; 
int main(){
	freopen("sticks.in","r",stdin); 
	freopen("sticks.out","w",stdout);
	cin>>t; 
	for(int i=1; i<=t; i++){
		cin>>n; 
		if(n==1) cout<<"-1"<<endl; 
		else{
			for(int j=1; ; j++){
				s=j; 
				m=0; 
				while(s/10!=0){
					if(s%10==0 || s%10==6 || s%10==9) m+=6; 
					if(s%10==1) m+=2; 
					if(s%10==2 || s%10==3 || s%10==5) m+=5; 
					if(s%10==4) m+=4; 
					if(s%10==7) m+=3; 
					if(s%10==8) m+=7;  
					s=s/10; 
				}
				if(s==0 || s==6 || s==9) m+=6; 
				if(s==1) m+=2; 
				if(s==2 || s==3 || s==5) m+=5; 
				if(s==4) m+=4; 
				if(s==7) m+=3; 
				if(s==8) m+=7;  
				if(m==n){
					cout<<j<<endl; 
					break; 
				}
			}
		}
	}
	fclose(stdin); 
	fclose(stdout); 
}
