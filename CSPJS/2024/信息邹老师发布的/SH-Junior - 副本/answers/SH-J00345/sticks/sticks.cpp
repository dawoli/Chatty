#include <bits/stdc++.h>
using namespace std;
int T,a[10]={6,2,5,5,4,5,6,3,7,6},m[51];
int main() {
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);
cin>>T;
for(int i=1;i<=T;i++){
	cin>>m[i];
}
for(int i=1;i<=T;i++){
	if(m[i]%7==0)
	{
		int ans=m[i]/7;
		for(int j=1;j<=ans;j++){
			cout<<8;
		}
		cout<<endl;
	}
	else if(m[i]%7==1&&m[i]!=1) {
		cout<<10;
		int ans=m[i]/7-1;
		for(int j=1;j<=ans;j++){
			cout<<8;
		}
		cout<<endl;
	}
	else{
		bool f=false;
    	if(m[i]/7==0){
    	for(int j=1;j<=9;j++){
    		if(a[j]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
		if(m[i]/7==1){
    	for(int j=10;j<=99;j++){
    		if(a[j/10]+a[j%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<m[i];
		cout<<endl;
		}
		if(m[i]/7==2){
    	for(int j=100;j<=999;j++){
    		if(a[j/100]+a[j/10%10]+a[j%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
		if(m[i]/7==3){
    	for(int j=1000;j<=9999;j++){
    		if(a[j/1000]+a[j/100%10]+a[j%10]+a[j/10%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
		if(m[i]/7==4){
    	for(int j=10000;j<=99999;j++){
    		if(a[j/10000]+a[j/1000%10]+a[j%10]+a[j/100%10]+a[j/10%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
		if(m[i]/7==5){
    	for(int j=100000;j<=999999;j++){
    		if(a[j/100000]+a[j/10000%10]+a[j%10]+a[j/1000%10]+a[j/100%10]+a[j/10%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
		if(m[i]/7==6){
    	for(int j=1000000;j<=9999999;j++){
    		if(a[j/1000000]+a[j/100000%10]+a[j%10]+a[j/10000%10]+a[j/1000%10]+a[j/100%10]+a[j/100%10]==m[i]){
    			cout<<j;
    			f=true;
    			break;
			}
		}
		if(f==false)
		cout<<-1;
		cout<<endl;
		}
	}
}
	return 0;
fclose(stdin);
fclose(stdout);
}
