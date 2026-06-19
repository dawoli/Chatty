#include<bits/stdc++.h>
using namespace std;
int kk[14]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,68};
void solve7(int n){
	for(int i=1;i<=n/7;i++)
		cout<<8;
	cout<<endl;
}
void solve71(int n){
	cout<<10;
	for(int i=1;i<=n/7-1;i++)
		cout<<8;
	cout<<endl;
}
void solve72(int n){
	cout<<1;
	for(int i=1;i<=n/7;i++)
		cout<<8;
	cout<<endl;
}
void solve73(int n){
	cout<<200;
	for(int i=1;i<=n/7-2;i++)
		cout<<8;
	cout<<endl;
}
void solve74(int n){
	cout<<20;
	for(int i=1;i<=n/7-1;i++)
		cout<<8;
	cout<<endl;
}
void solve75(int n){
	cout<<2;
	for(int i=1;i<=n/7;i++)
		cout<<8;
	cout<<endl;
}
void solve76(int n){
	cout<<6;
	for(int i=1;i<=n/7;i++)
		cout<<8;
	cout<<endl;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		if(n<0){
			cout<<-1<<endl;
			continue;
		}
		if(n>=0&&n<=13){
			cout<<kk[n]<<endl;
			continue;
		}
		if(n%7==0)solve7(n);
		else if(n%7==1)solve71(n);
		else if(n%7==2)solve72(n);
		else if(n%7==3)solve73(n);
		else if(n%7==4)solve74(n);
		else if(n%7==5)solve75(n);
		else solve76(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
