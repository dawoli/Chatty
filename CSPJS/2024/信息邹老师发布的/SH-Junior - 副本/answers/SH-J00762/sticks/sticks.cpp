#include<bits/stdc++.h>
using namespace std;

int x[15]={6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n,ans=0;
	cin>>T;
	for (int q=1;q<=T;q++){
		cin>>n;
		if (n<2){
			cout<<-1<<endl;
			continue;
		}
		int l=1000;
		for (int i=0;i<10;i++){
			if (n==x[i] && i!=0){
				cout<<ans+i<<endl;
				l=0;
				break;
			}
		}
		if (l==0){
			continue;
		}
		for (int i=0;i<10 && n>0;i++){
			if (n>=x[i+1]){
				i+=1;
				n-=x[i];
				if (ans){
					ans=ans*10+i;
				} else{
					ans+=i;
				}
				continue;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
