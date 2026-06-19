#include<bits/stdc++.h>
using namespace std;
int n,t,di[10]={6,2,5,5,4,5,6,3,7,6},de[8]={0,-1,1,7,4,2,6,8};
void min(int n,int flag){
	if(n==0)return;
	if(n<=7){
		cout<<de[n];
		return;
	}
	int minl=n/7+1;
	int mind=n-(n/7)*7;
	if(mind==1){
		mind=8;
	}
	if(mind==7){
		for(int i=0;i<minl-1;i++)cout<<8;
		return;
	}else{
		for(int i=flag;i<=9;i++){
			if(di[i]>=mind){
				cout<<i;
				min(n-di[i],0);
				return;
			}
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
		cin>>n;
		min(n,1);
		cout<<endl;
	}
	return 0;
} 
/*
0 6?
1 2
2 5
3 5x
4 4
5 5x
6 6
7 3
8 7
9 6x
*/
