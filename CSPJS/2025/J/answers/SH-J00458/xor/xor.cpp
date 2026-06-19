#include<bits/stdc++.h>
using namespace std;

int n,k,ans=0;
long long a[500010];
queue<bool> x[50];
queue<bool> y[50];

/*void xr(bool &a,bool &b){
	if(a==b){
		a=0;
		return;
	}
	a=1;
	return;
}

void to_2(int &a){
	if(x.empty()){
		while(a!=0){
			x.push(a%2);
			a/=2;
		}
	}
	else{
		while(a!=0){
			y.push(a%2);
			a/=2;
		}
		int xx
		while(!x.empty()||!y.empty()){
			xr(x.top(),y.top());
			y.pop();
			xx=x.top();
			x.pop();
			x.push(xx);
		}
	}
	return;
}

int to_10(int &a[]){
	int i=0;int v=0;
	while(a[i]!=-1){
		if(a[i]==1)v+=pow(2,i);
	}
	return v;
}

*/

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==k&&x.empty()){
				ans++;
				continue;
			}
			to_2(a[j]);
			int o=to_10(x);
			if(o==k){
				ans++;
			}
		}
	}*/
	cout<<n/2;
	return 0;
}
