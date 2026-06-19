#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int T;
//int st[15]={6,2,5,5,4,5,6,3,7,6};
int dabiao[55]={-1,-1,1,7,4,2,6,8,10,18,78,
48,58,68,88,108,188,408,208,288,808};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=20){
			cout<<dabiao[n]<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==1){
			cout<<10;
			for(int i=0;i<(n/7-1);i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==2){
			cout<<1;
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==3){
			cout<<40;
			for(int i=0;i<(n/7-1);i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==4){
			cout<<20;
			for(int i=0;i<(n/7-1);i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==5){
			cout<<2;
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(n%7==6){
			cout<<80;
			for(int i=0;i<(n/7-1);i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
