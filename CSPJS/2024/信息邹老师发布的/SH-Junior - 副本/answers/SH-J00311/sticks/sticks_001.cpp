#include<bits/stdc++.h>
using namespace std;
int n,a[55],ans,num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=0;
		if(a[i]%7==0){
			ans=a[i]/7;
			for(int j=1;j<=ans;j++)cout<<8;
			cout<<endl;
			continue;
		}
		else if(a[i]<2){
			cout<<"-1"<<endl;
			continue;
		}
		else if(a[i]==5){
			cout<<2<<endl;
			continue;
		}
		else if(a[i]==6){
			cout<<6<<endl;
			continue;
		}
		else if(a[i]==4){
			cout<<4<<endl;
			continue;
		}
		else if(a[i]==3){
			cout<<7<<endl;
			continue;
		}
		else if(a[i]==2){
			cout<<1<<endl;
			continue;
		}
		else if(a[i]%7==1){
			ans=(a[i]-1)/7;
			cout<<1;
			for(int j=1;j<=ans;j++)cout<<8;
			cout<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
