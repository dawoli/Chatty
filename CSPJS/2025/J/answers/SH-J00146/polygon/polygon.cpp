#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxs=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	int t=3,cnt=0,f=0;
	while(t<=n){
		for(int i=1;i<=n-t+1;i++){
			cnt=0;
			maxs=0;
			for(int j=i;j<=i+t-1;j++){
				cnt+=a[j];
				maxs=max(a[j],maxs);
			}
			if(cnt>maxs*2){
				f++;
				for(int j=i;j<=i+t-1;j++){
					cout<<j<<" ";
				}
				cout<<"\n";
			}
		}
		t++;
	}
	cout<<f;
	return 0;
}
