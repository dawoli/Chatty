#include<iostream>
#include<cstdio>
int num[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int n;
		std::cin>>n;
		if(n<2)std::cout<<"-1"<<"\n";
		else if(n==4)std::cout<<"0";
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}else if(n%7==1){
			for(int i=1;i<=(n-8)/7;i++)std::cout<<"8";
			std::cout<<"9"<<"\n";
		}else{
			for(int i=1;i;i++){
				int j=i,sum=0;
				while(j>0){
					sum+=num[j%10];
					j/=10;
				}
				if(sum==n){
					std::cout<<i<<"\n";
					break;
				}
				if(sum>n+10){
					std::cout<<"-1"<<"\n";
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
