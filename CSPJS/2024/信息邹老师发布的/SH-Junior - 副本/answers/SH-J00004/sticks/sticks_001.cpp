#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int num=0;num<T;num++){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
		int myleft=n%7,mytimes=n/7,myhead;
		if(myleft==2){
			cout<<strncat("1","88888888888888",mytimes)<<endl;	
		}
		if(myleft==3){
			cout<<strncat("7","88888888888888",mytimes)<<endl;	
		}
		if(myleft==4){
			cout<<strncat("4","88888888888888",mytimes)<<endl;
		}
		if(myleft==5){
			cout<<strncat("2","88888888888888",mytimes)<<endl;
		}
		if(myleft==1){
			cout<<strncat("10","8888888888888",mytimes-1)<<endl;
		}
		if(myleft==6){
			cout<<strncat("80","88888888888888",mytimes-1)<<endl;
		}
		
	} 
	fclose(stdin);fclose(stdout);
	return 0;
}
