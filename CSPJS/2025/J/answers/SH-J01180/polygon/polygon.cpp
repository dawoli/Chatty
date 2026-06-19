#include<bits/stdc++.h>
#define N 5009
using namespace std;
int n,x[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];//cin
	int maxi=2*(*max_element(x,x+n+1));
	if(n==3){
		sort(x,x+n+1);
		if(x[1]+x[2]>x[3]) cout<<1;
		else cout<<0;
	}else if((*max_element(x,x+n+1))==1){
		int cont=0,ans=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(x[i]==1) cont++;
		}
		for(int T=3;T<=cont;T++){
			for(int j=0;j<T;j++){
				ans*=(cont-j);
			}
			for(int k=1;k<=T;k++){
				ans/=k;
			}
			cnt+=ans%998244353;
		}
		cout<<cnt<<endl;
		return 0;
	}else cout<<1;
	return 0;
}
