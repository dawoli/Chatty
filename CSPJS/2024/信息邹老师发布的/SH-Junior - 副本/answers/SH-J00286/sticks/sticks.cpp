#include<bits/stdc++.h>
using namespace std;
int q[10000];
bool stickk(int x){
	int minn;
	if(x==1){
		minn=-1;
		
	}
	else if(x==2){
		minn=1;
	}
	else if(x==3){
		minn=7;
	}
	else if(x==4){
		minn=-4;
	}
	else if(x==5){
		minn=2;
	}
	else if(x==6){
		minn=6;
	}
	else if(x==7){
		minn=3;
	}
	else{
		int w=x/7;
		x=x%7;	
		for(int i=1;i<=w;i++){
			q[i]=8;
		}
		stickk(x);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	int a[100000]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stickk(a[i]);
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
		cout<<a[i];
	}
	
	return 0;
}
