#include<bits/stdc++.h>
using namespace std;
int t,n;
long long jg[55];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for (int i;i<t;i++){
		cin>>n;
		if (n==1){
			jg[i=-1];
			continue;
		}
		if (n<=7){
			if(n==2) jg[i]=1;
			if(n==3) jg[i]=7;
			if(n==4) jg[i]=4;
			if(n==5) jg[i]=2;
			if(n==6) jg[i]=6;
			if(n==7) jg[i]=8;
			continue;
		}
		if (n%7==0){
			jg[i]=8;
			for (int j=1;j<n/7;j++){
				jg[i]=jg[i]*10+8;
				continue;
			}
		}
		if (n%7==1){
			jg[i]=10;
			for (int j=1;j<(n-1)/7;j++){
				jg[i]=jg[i]*10+8;
				continue;
			}
		}
	}
	for (int i;i<t;i++){
		cout<<jg[i]<<endl;
	}
	return 0;
}
