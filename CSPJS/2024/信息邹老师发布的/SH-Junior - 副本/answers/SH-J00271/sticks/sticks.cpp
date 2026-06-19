#include<bits/stdc++.h>
using namespace std;
int T,n,min;
int sti[6]={6,2,5,4,3,7};
int stick[20]={-1,1,7,4,2,6,8,10,18,22,20,27,68,88,108,188,227,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>T;
    for(int a=0;a<T;a++){
    	cin>>n;
		//20以内 
//    	if(n==1)cout<<"-1"<<endl;
//    	else if(n==2)cout<<"1"<<endl;
//    	else if(n==3)cout<<"7"<<endl;
//    	else if(n==4)cout<<"4"<<endl;
//    	else if(n==5)cout<<"2"<<endl;
//    	else if(n==6)cout<<"6"<<endl;
//    	else if(n==7)cout<<"8"<<endl;
//    	else if(n==8)cout<<"10"<<endl;
//    	else if(n==9)cout<<"18"<<endl;
//    	else if(n==10)cout<<"22"<<endl;
//    	else if(n==11)cout<<"20"<<endl;
//    	else if(n==12)cout<<"27"<<endl;
//    	else if(n==13)cout<<"68"<<endl;
//    	else if(n==14)cout<<"88"<<endl;
//    	else if(n==15)cout<<"108"<<endl;
//    	else if(n==16)cout<<"188"<<endl;
//    	else if(n==17)cout<<"227"<<endl;
//    	else if(n==18)cout<<"208"<<endl;
//    	else if(n==19)cout<<"288"<<endl;
//    	else if(n==20)cout<<"688"<<endl;
		if(n<=20)cout<<stick[n-1]<<endl;
    	//50以内
    	if(n<=50){
    		if(n-6<=15)cout<<6*100+stick[n-6-1];
    		else if(n-7<=15)cout<<8*100+stick[n-7-1];
		}
    }
	return 0;
}

