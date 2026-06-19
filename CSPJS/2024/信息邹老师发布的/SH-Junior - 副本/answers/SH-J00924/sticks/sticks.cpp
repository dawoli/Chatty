#include<bits/stdc++.h>
using namespace std;

int d[11000005];
int t;

int ff(int k){
	if(k==0){
		return 6;
	}
	if(k==1){
		return 2;
	}
	if(k==2){
		return 5;
	}
	if(k==3){
		return 5;
	}
	if(k==4){
		return 4;
	}
	if(k==5){
		return 5;
	}
	if(k==6){
		return 6;
	}
	if(k==7){
		return 3;
	}
	if(k==8){
		return 7;
	}
	else{
		return 6;
	}
}

int f(int k){
	int a[10];
	int ans=0;
	int p=0;
	while(k){
		a[++p]=k%10;
		k/=10;
		ans+=ff(a[p]);
	}
	return ans;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=1;i<=11000000;i++){
		d[i]=f(i);
	}
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0 || n==1){
			cout<<"-1\n";
			continue;
		}
		if(n<=50){
			for(int i=1;i<=11000000;i++){
				if(d[i]==n){
					cout<<i<<"\n";
					break;
				}
			}
			continue;
		}
		else if(n%7==0){
			int w=n/7;
			for(int i=1;i<=w;i++){
				cout<<"8";
			}
			continue;
		}
		else if(n%7==1){
			cout<<"10";
			n-=8;
			int w=n/7;
			for(int i=1;i<=w;i++){
				cout<<"8";
			}
			continue;
		}
	}
	return 0;
}
