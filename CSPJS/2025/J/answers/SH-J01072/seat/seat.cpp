#include <bits/stdc++.h>
using namespace std;

int n,m,a[110],vis,k;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	vis=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(vis==a[i]){
			k=i;
		}
	}
	int num=(k+n-1)/n;
	cout<<num<<" ";
	if(num%2==1){
		if(k%n==0)cout<<n;
		else cout<<k%n;
	}else{
		cout<<num*n-k+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
