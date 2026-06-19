#include<bits/stdc++.h>
using namespace std;
int a[20]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		int k=n/7;
		if(n%7==0){
			while(k--){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		k--;
		int stic=n%7+7;
		for(int i=1;i<=9;i++){
			int qwe=0;
			for(int j=0;j<=9;j++){
				if(a[i]+a[j]==stic){
					cout<<i<<j;
					qwe=1;
					break;
				} 
			}
			if(qwe){
				break;
			}
		}
		while(k--){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
