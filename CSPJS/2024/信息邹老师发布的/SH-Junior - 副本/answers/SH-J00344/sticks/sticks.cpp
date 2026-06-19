#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int te,ans[100009]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108};
	cin>>te;
	for(int i=1;i<=te;i++){
		int n,cnt=0;
		cin>>n;
		while(1){
			if(n<=15){
				cout<<ans[n];
				for(int j=0;j<cnt;j++)
					cout<<8;
				cout<<endl;
				break;
			}
			else{
				n-=7;
				cnt++;
			}
		}
	}
	return 0;
}
