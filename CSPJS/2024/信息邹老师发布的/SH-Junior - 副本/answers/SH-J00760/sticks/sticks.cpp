#include<bits/stdc++.h>
using namespace std;
int T,n,a[20];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[1]=-1,a[2]=1,a[3]=7,a[4]=4,a[5]=2,a[6]=6,a[7]=8,a[8]=10,a[9]=18,a[10]=22,a[11]=20,a[12]=28,a[13]=68,a[14]=88;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		if(n<=14)cout<<a[n]<<endl;
		else{
			cout<<a[n%7+7];
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
