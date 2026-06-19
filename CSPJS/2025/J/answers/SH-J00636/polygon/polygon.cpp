#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int R=998244353;
long long exp2(int t){
	if(t==0)return 1;
	if(t%2){
		return (2*exp2(t-1))%R;
	}
	return (exp2(t/2)*exp2(t/2))%R;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int s,am=0;
	cin>>s;
	for(int i=1;i<=s;++i){
		cin>>a[i];
	}
	sort(a+1,a+s+1);
	if(a[s]==1){
		long long ans;
		ans=exp2(s);
		ans-=1+s+s*(s-1)/2;
		while(ans<0){
			ans+=R;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=s;++i){
		int an;
		for(int j=2;j<exp2(i);j+=2){
			an=0;
			for(int k=1;k<i;++k){
				if(j/exp2(k)%2)an+=a[k];
			}
			if(an>a[i])am++;
		}
	}
	cout<<am;
	return 0;
}
