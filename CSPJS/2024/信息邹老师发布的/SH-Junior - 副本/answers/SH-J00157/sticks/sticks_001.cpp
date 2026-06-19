#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int mnnum[maxn];
const int stick[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,pre=7;cin>>n;
		string ans;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int digit=n/7+(n%7==0?0:1);
		for(int i=1;i<=digit;i++){
			for(int j=0;j<=9;j++){
				if(i==1&&j==0) continue;
				if(n-stick[j]<=(digit-i)*7&&n-stick[j]>=(digit-i)*2){
					ans+=to_string(j);
					n-=stick[j];
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

