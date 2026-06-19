#include<bits/stdc++.h>
using namespace std;
long long t,n,a[20000]={},len=0;

void stick(long long x){
	if(x<2){
		a[len]=-1;	
	}else if(x==2){
		a[len]=1;
	}else if(x==5){
		a[len]=2;
	}else if(x==4){
		a[len]=4;
	}else if(x==6){
		a[len]=6;
	}else if(x==3){
		a[len]=7;
	}else if(x==7){
		a[len]=8;
	}else if(x==8){
		a[len]=10;
	}else if(x==9){
		a[len]=18;
	}else if(x==10){
		a[len]=22;
	}else if(x==11){
		a[len]=20;
	}else if(x==12){
		a[len]=28;
	}else if(x==13){
		a[len]=48;
	}else if(x==14){
		a[len]=88;
	}else{
		a[len]=8;
		len++;
		stick(x-7);
	}
	return;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		len=0;
		cin>>n;
		stick(n);
		for(long long i=len;i>=0;i--){
			cout<<a[i];
			a[i]=0;
		}
		cout<<endl;
	}
	return 0;
}
