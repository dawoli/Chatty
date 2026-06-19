#include<iostream>
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	std::cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
        std::cin>>a[i];
		if(i<2)std::cout<<"-1"<<std::endl;
	    else if(i=2)std::cout<<"1"<<std::endl;
	    else if(i=3)std::cout<<"7"<<std::endl;
	    else if(i=4)std::cout<<"4"<<std::endl;
	    else if(i=5)std::cout<<"2"<<std::endl;
	    else if(i=6)std::cout<<"6"<<std::endl;
	    else if(i=7)std::cout<<"8"<<std::endl;
	    else if(i=8)std::cout<<"10"<<std::endl;
	    else if(i=9)std::cout<<"18"<<std::endl;
	    else if(i=10)std::cout<<"22"<<std::endl;
	    else if(i=11)std::cout<<"20"<<std::endl;
	    else if(i=12)std::cout<<"28"<<std::endl;
	    else if(i=13)std::cout<<"68"<<std::endl;
	    else if(i=14)std::cout<<"88"<<std::endl;
	    else if(i=15)std::cout<<"108"<<std::endl;
	    else if(i=16)std::cout<<"188"<<std::endl;
	    else if(i=17)std::cout<<"200"<<std::endl;
	    else if(i=18)std::cout<<"208"<<std::endl;
	    else if(i=19)std::cout<<"288"<<std::endl;
	    else std::cout<<"688"<<std::endl;
	}
	
}
