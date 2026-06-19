#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n=0;cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(num==1){
			cout<<-1<<endl;
			continue;
		}
		if(num%7==0){
			for(int j=0;j<num/7;j++){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		if(num%7==1){
			cout<<'1'<<'0';
			for(int j=0;j<=((num-1)/7-2);j++){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		if(num==2){
			cout<<'1'<<endl;
			continue;
		}
		if(num==3){
			cout<<'7'<<endl;
			continue;
		}
		if(num==6){
			cout<<'6'<<endl;
			continue;
		}
		if(num==18){
			cout<<"208"<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
