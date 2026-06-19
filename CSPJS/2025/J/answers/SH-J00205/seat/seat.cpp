#include<bits/stdc++.h>
using namespace std;
int num[105];
bool cmp(int x,int y){
	if(y>x)return false;
	else return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int loca,y;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>num[i];
	}
	int tion=num[0];
	cout<<tion<<endl;
	sort(num,num+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(num[i]==tion){
			loca=i+1;
			break;
		}
	}
	for(int i=0;i<n*m;i++)cout<<num[i]<<endl;
	if(loca%n==0) y=loca/n;
	else y=(loca/n)+1;
	cout<<y<<endl;
	if(y*n==loca){
		if(y%2==0)cout<<y<<" "<<1;
		if(y%2==1)cout<<y<<" "<<n;
	}
	else{
		if(y%2==0)cout<<y<<" "<<((n+1-((y*n)%loca)))%n;
		if(y%2==1){
			if(loca==1)cout<<y<<" "<<1;
			if(loca==n)cout<<y<<" "<<n;
			else cout<<y<<" "<<n-((y*n)%loca);
		}
	}
	return 0;
}
