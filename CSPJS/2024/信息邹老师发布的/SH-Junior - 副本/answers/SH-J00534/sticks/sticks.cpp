#include<bits/stdc++.h>
using namespace std;
int t,n,m,sum;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		for(int j=1;j<=10000000;j++){
			m=j;
			sum=0;
			while(m>0){
				sum+=a[m%10];
				m/=10;
			}
			if(sum==n){
				cout<<j<<endl;
				break;
			}
		}
		if(sum!=n) cout<<-1<<endl;
	}
	return 0;
}
