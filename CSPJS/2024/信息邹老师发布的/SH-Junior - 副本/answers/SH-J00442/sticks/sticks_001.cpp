#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
	cin>>n;
    if (n%7==0){
		for(int i=1;i<=n/7;i++){
			cout<<8;
		}
	}
	if(n%7==1){
		cout<<16;
		for(int i=1;i<=(n-8)/7;i++){
			cout<<8;
		}
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
	
}
