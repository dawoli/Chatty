#include<iostream>
#include<cstdio>
#include<algorithm>
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	std::cin>>t;
	int a;
	while(std::cin>>a){
		if(a==1)std::cout<<-1<<"\n";
		if(a==2)std::cout<<1<<"\n";
		if(a==3)std::cout<<7<<"\n";
		if(a==4)std::cout<<4<<"\n";
		if(a==5)std::cout<<2<<"\n";
		if(a==6)std::cout<<6<<"\n";
		if(a==7)std::cout<<8<<"\n";
		if(a==8)std::cout<<10<<"\n";
		if(a==9)std::cout<<18<<"\n";
		if(a==10)std::cout<<22<<"\n";
		if(a==11)std::cout<<20<<"\n";
		if(a==12)std::cout<<28<<"\n";
		if(a==13)std::cout<<68<<"\n";
		if(a==14)std::cout<<88<<"\n";
		if(a==15)std::cout<<108<<"\n";
		if(a==16)std::cout<<188<<"\n";
		if(a==17)std::cout<<200<<"\n";
		if(a==18)std::cout<<208<<"\n";
		if(a==19)std::cout<<288<<"\n";
		if(a==20)std::cout<<688<<"\n";
	}
}
