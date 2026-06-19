#include<iostream>
#include<cstdio>
bool d[15],c[15],h[15],s[15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	std::cin>>n;
	int sum=52;
	for(int i=0;i<n;i++){
		std::string y;
		std::cin>>y;
		char a=y[0],x=y[1];
		int ans;
		if(x=='T')ans=10;
		else if(x=='J')ans=11;
		else if(x=='Q')ans=12;
		else if(x=='K')ans=13;
		else if(x=='A')ans=1;
		else ans=x-'0';
		if(a=='D'&&d[ans]==0){
			sum--; 
			d[ans]=1;
		}
		if(a=='C'&&c[ans]==0){
			sum--; 
			c[ans]=1;
		}
		if(a=='H'&&h[ans]==0){
			sum--; 
			h[ans]=1;
		}
		if(a=='S'&&s[ans]==0){
			sum--; 
			s[ans]=1;
		}
	}
	std::cout<<sum;
	return 0;
} 
