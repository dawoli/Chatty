#include<bits/stdc++.h>
using namespace std;
int a[18]={0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		int n;
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
		}
		else{
			int b=0;
			while(n>17){
				n-=7;
				b=b*10+a[7];
			}
			cout<<a[n];
			if(b!=0) cout<<b<<endl;
			else cout<<endl;
		}
	}
	return 0;
}
