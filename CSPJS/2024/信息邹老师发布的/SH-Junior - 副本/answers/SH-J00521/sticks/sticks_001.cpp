#include<bits/stdc++.h>
using namespace std;
int b[10]={0,0,1,7,4,2,6,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T; cin>>T;
	for(int x=1;x<=T;x++){
		int n,sum,yushu,ans=10,st; cin>>n;
		yushu=n%7;
		if(yushu) sum=n/7+1;
		else sum=n/7,yushu=7;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		if(sum==1){
			cout<<b[n]<<endl;
			continue;
		}
		if(yushu<=2) cout<<1,yushu+=5;
		else if(yushu<=5) cout<<2,yushu+=2;
		else if(yushu==6) cout<<6,yushu++;
		else cout<<8;
		sum--;
		while(sum>1&&yushu<=6){
			cout<<0;
			yushu+=1;
			sum--;
		}
		if(sum==1){
			cout<<b[yushu]<<endl;
			continue;
		}
		while(sum>0) cout<<8,sum--;
		cout<<endl;
	}
	return 0;
}

