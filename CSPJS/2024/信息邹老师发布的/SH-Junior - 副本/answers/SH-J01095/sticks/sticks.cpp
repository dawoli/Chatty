#include<iostream>
#include<cstring>
using namespace std;
int main(){
	/*
	思路：
	1.假设n%7==0:
		全部输出8(位数最少)
	2.假设n%7==1: 
		10888...8((n-1)/7-1个8)
	3.假设n%7==2:
		18888...8((n-2)/7个8) 
	4.假设n%7==3:
		22888...8((n-3)/7个8) (n=3除外)
	5.假设n%7==4:
		20888...8((n-4)/7-1个8) (n=4除外) 
	6.假设n%7==5:
		28888...8((n-5)/7个8) 
	7.假设n%7==6:
		68888...8((n-6)/7个8)
	*/ 
	freopen("sticks.in","r",stdin); 
	freopen("sticks.out","w",stdout); 
	int t;
	cin>>t;
	int l[t];
	string numbers[t];
	string k;
	int sum=0;
	for(int i=0;i<t;i++){
		cin>>l[i];
		if(l[i]==1){
			numbers[i]="-1";
			continue;
		}
		else if(l[i]==3){
			numbers[i]="7";
			continue;
		}
		else if(l[i]==4){
			numbers[i]="4";
			continue;
		}
		else{
			if(l[i]%7==0){
				numbers[i]="88";
				for(int j=0;j<(l[i]-1)/7;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==1){
				numbers[i]="10";
				for(int j=0;j<(l[i]-1)/7-1;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==2){
				numbers[i]="1";
				for(int j=0;j<(l[i]-2)/7;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==3){
				numbers[i]="22";
				for(int j=0;j<(l[i]-3)/7;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==4){
				numbers[i]="20";
				for(int j=0;j<(l[i]-4)/7-1;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==5){
				numbers[i]="2";
				for(int j=0;j<(l[i]-5)/7;j++){
					numbers[i]+="8";
				}
			}
			else if(l[i]%7==6){
				numbers[i]="6";
				for(int j=0;j<(l[i]-6)/7;j++){
					numbers[i]+="8";
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<numbers[i]<<endl;
	}
	return 0;
}
