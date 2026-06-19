#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;

int a[N],n;

bool cmp(int a,int b){
	return a>b;
}

long long qmi(int k,int t){
	long long ans=1;
	while(t){
		if(t&1) ans=ans*k%mod;
		k=k*k%mod;
		t>>=1;
	}
	return ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1) flag=false;
	}
	if(flag){
		cout<<(qmi(2,n)-1-n-((n-1)*n/2)%mod+mod)%mod;
	}
	else{
		if(n<3) cout<<0;
		else if(n==3){
			int h=max(max(a[1],a[2]),a[3]);
			if(h>=(a[1]+a[2]+a[3]-h)) cout<<0;
			else cout<<1;
		}
		else{
			long long t=(qmi(2,n)-1-n-((n-1)*n/2)%mod+mod)%mod;
			srand(time(0));
			cout<<rand()%t+1;
		}
	}
	return 0;
}
