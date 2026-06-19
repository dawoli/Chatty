#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
void solve(){
	int n,ans,temp=1,x;
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
	}
	else if(n<=7&&n>=2){ 
		for(int i=1;i<=9;i++){
			if(n==s[i]){
				cout<<i<<endl;
				break;
			}
		}
	}
	else{
		if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else{
			for(int i=1;i<=n/2;i++){
				x+=temp*1;
				temp*=10;
			}
			for(int i=1;i<=x;i++){
				int num=i,sum=0;
				while(num){
					sum+=s[num%10];
					num/=10;
				}
				if(sum==n){
					ans=i;
					break;
				}
			} 
			cout<<ans;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
