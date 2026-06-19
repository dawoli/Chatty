#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[13]={6,2,5,5,4,5,6,3,7,6};
int ans[100100];

void print(){
	for(int i=1;i<=(n-1)/7+1;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return;
}

void f(int n){
	int m=(n-1)/7+1,sum=0;
	if(m==1){
		if(n==2)cout<<1<<endl;
		if(n==3)cout<<7<<endl;
		if(n==4)cout<<4<<endl;
		if(n==5)cout<<3<<endl;
		if(n==6)cout<<6<<endl;
		if(n==7)cout<<8<<endl;
		return;
	}
	for(int i=1;i<=m;i++){
		if(i==1)ans[i]=2,sum+=5;
		else ans[i]=0,sum+=6;
	}
	for(int i=m;i>=1;i--){
		if(n-sum==0){
			print();
			return;
		}
		if(n-sum<0){
			if(sum-n>=4)ans[i]=1,sum-=4;
			else if(sum-n==1)ans[i]=2,sum--;
			else if(sum-n==2)ans[i]=4,sum-=2;
			else ans[i]=7,sum-=3;
		}
		if(n-sum>0){
			if(i!=1){
				ans[i]=8;sum++;
			}
			else{
				if(n-sum==1)ans[i]=6,sum++;
				if(n-sum==2)ans[i]=8,sum+=2;
				print();
				return;
			}
		}
	}
	return;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(ans,0,sizeof(ans));
		if(n<=1)cout<<-1<<endl;
		else f(n);
	}
	return 0;
}
