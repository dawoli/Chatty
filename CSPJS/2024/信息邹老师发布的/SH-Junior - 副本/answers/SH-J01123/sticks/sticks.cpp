#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int num;
		cin>>num;
		int sum=0,cnt;
		if(num<=1)cout<<-1<<endl;
		else if(num<=7){
			if(num==2)cout<<1<<endl;
			if(num==3)cout<<7<<endl;
			if(num==4)cout<<4<<endl;
			if(num==5)cout<<2<<endl;
			if(num==6)cout<<6<<endl;
			if(num==7)cout<<8<<endl;
		}else{
			if(num>42){
				sum=num/7-6,cnt=num%7+42;
				if(cnt==48)cout<<6888888;
				if(cnt==47)cout<<2888888;
				if(cnt==46)cout<<2088888;
				if(cnt==45)cout<<2008888;
				if(cnt==44)cout<<1888888;
				if(cnt==43)cout<<1088888;
				if(cnt==42)cout<<888888;
			}
			else if(num>35){
				sum=num/7-5,cnt=num%7+35;
				if(cnt==41)cout<<688888;
				if(cnt==40)cout<<288888;
				if(cnt==39)cout<<208888;
				if(cnt==38)cout<<200888;
				if(cnt==37)cout<<188888;
				if(cnt==36)cout<<108888;
				if(cnt==35)cout<<88888;
			}
			else if(num>28){
				sum=num/7-4,cnt=num%7+28;
				if(cnt==34)cout<<68888;
				if(cnt==33)cout<<28888;
				if(cnt==32)cout<<20888;
				if(cnt==31)cout<<20088;
				if(cnt==30)cout<<18888;
				if(cnt==29)cout<<10888;
				if(cnt==28)cout<<8888;
			}
			else if(num>21){
				sum=num/7-3,cnt=num%7+21;
				if(cnt==27)cout<<6888;
				if(cnt==26)cout<<2888;
				if(cnt==25)cout<<2088;
				if(cnt==24)cout<<2008;
				if(cnt==23)cout<<1888;
				if(cnt==22)cout<<1088;
				if(cnt==21)cout<<888;
			}
			else if(num>14){
				sum=num/7-2,cnt=num%7+14;
				if(cnt==20)cout<<688;
				if(cnt==19)cout<<288;
				if(cnt==18)cout<<208;
				if(cnt==17)cout<<200;
				if(cnt==16)cout<<188;
				if(cnt==15)cout<<108;
				if(cnt==14)cout<<88;
			}
			else if(num>7){
				sum=num/7-1,cnt=num%7+7;
				if(cnt==13)cout<<68;
				if(cnt==12)cout<<28;
				if(cnt==11)cout<<20;
				if(cnt==10)cout<<22;
				if(cnt==9)cout<<18;
				if(cnt==8)cout<<10;
			}
			for(int i=1;i<=sum;i++)cout<<8;
			cout<<endl;
		}
	}
}
