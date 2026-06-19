#include<bits/stdc++.h>
using namespace std;
int sti[10]={6,2,5,5,4,5,6,3,7,6},n,w,rst[20]={-1,-1,1,7,4,2,0,8,-1,-1},ans;
void solve20(){
	int biao[29]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,80,88,180,188,200,208,288,808};
	cout<<biao[n]<<endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>w;
	for(int i=0;i<w;i++){
		cin>>n;
		ans=0;
		if(n%7==0&&n!=0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1&&n!=1){
			cout<<10;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n<=20){
			solve20();
		}
		else if(n%7==2){
			cout<<1;
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==3){
			cout<<200;
			for(int i=0;i<n/7-2;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
			cout<<endl;
		}
		else{
			cout<<80;
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
