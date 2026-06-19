#include<bits/stdc++.h>
using namespace std;
int n1,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks1.in","r",stdin);
	freopen("sticks1.out","w",stdout);
	cin>>n1;
	for(int i=1;i<=n1;i++){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		int t=n/7+1;
		for(int i=1;i<=t-1;i++){
			int tt;
			if(n%7==0) tt=7;
			else tt=n%7;
			for(int j=0+(i==1);j<=9;j++){
				if(a[j]>=tt){
					n-=a[j];
					cout<<j;
					break;
				}
			}
		}
		for(int i=0+(t==1);i<=9;i++){
			if(a[i]==n){
				cout<<i;
				break;
			}
		}
		cout<<endl;
	}
	return 0;
}
