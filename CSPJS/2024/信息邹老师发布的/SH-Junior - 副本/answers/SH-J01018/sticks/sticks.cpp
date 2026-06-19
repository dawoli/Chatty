#include <bits/stdc++.h>
using namespace std;
int a[20];
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[2]=1;
	a[3]=7;
	a[4]=4;
	a[5]=2;
	a[6]=6;
	a[7]=8;
	a[8]=10;
	a[9]=18;
	a[10]=22;
	a[11]=20;
	cin>>t;
	while(t--){
		int x=0;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;	
		}
		else{
			while(n>11){
				n-=7;
				x++;
			}
			cout<<a[n];	
			for(int i=1;i<=x;i++){
				cout<<8;
			}
			cout<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
