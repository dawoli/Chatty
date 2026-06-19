#include<iostream>
using namespace std;
int n,ans;
int a[10];
int st(int s,int sn){
	if(sn==0&&ans>s){
		ans=s;
	}
	for(int j=0;j<=9;j++){
		if(a[j]<=sn){
			st(s*10+j,sn-a[j]);
		}
	}
}
int main(){
	fopen("sticks.in","r");
	fopen("sticks.out","w");
	int t;
	
	a[0]=6;a[1]=2;a[2]=5;a[3]=5;a[4]=4;a[5]=5;a[6]=6;a[7]=3;a[8]=7;a[9]=6;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=1e9;
		for(int j=1;j<=9;j++){
			if(a[j]<=n){
				st(j,n-a[j]);
			}
		}
		if(ans!=1e9)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
