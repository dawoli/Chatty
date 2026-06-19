#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int t;
int n;
int s[N];
void check(){
	for(int i=1;i<=N;i++){
		int x=i;
		while(x!=0){
			s[i]+=num[x%10];
			x/=10;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	check();
	while(t--){
		cin>>n;
		int ans=-1;
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else{
			for(int i=1;i<=N;i++){
				if(s[i]==n) {
					ans=i;
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
