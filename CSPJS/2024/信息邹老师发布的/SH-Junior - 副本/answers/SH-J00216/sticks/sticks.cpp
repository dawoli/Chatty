#include<iostream>
#include<cstdio>
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;std::cin>>t;
	for(int d=0;d<t;d++){
		int n;std::cin>>n;
		if(n==1)std::cout<<-1<<"\n";
		else if(n%7==0){
			for(int i=0;i<n/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}
		else if(n%7==1){
			std::cout<<"10";
			for(int i=0;i<(n-1)/7-1;i++)std::cout<<"8";
			std::cout<<"\n";
		}
		else if(n%7==2){
			std::cout<<"1";
			for(int i=0;i<(n-2)/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}
		else if(n%7==3){
			if(n==3)std::cout<<"7"<<"\n";
			else if(n==10)std::cout<<"22"<<"\n";
			else{
				std::cout<<"200";
				for(int i=0;i<(n-17)/7;i++)std::cout<<"8";
				std::cout<<"\n";
			}
		}
		else if(n%7==4){
			std::cout<<"20";
			for(int i=0;i<(n-11)/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}
		else if(n%7==5){
			std::cout<<"2";
			for(int i=0;i<(n-5)/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}
		else{
			std::cout<<"6";
			for(int i=0;i<(n-6)/7;i++)std::cout<<"8";
			std::cout<<"\n";
		}
	}
	return 0;
}
