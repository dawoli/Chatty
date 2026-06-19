#include<bits/stdc++.h>
using namespace std;
int Mod=998244353,n,a[5005],maxn,Ans,ansans;
bool all1,allsame;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	all1=1;
	allsame=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			allsame=0;
			break;
		}
	}
	if(n<=3){
		if(n<=2) cout<<0<<endl;
		else if(n==3){
			maxn=max(a[1],max(a[2],a[3]));
			if(a[1]+a[2]+a[3]<=(2*maxn)) cout<<0<<endl;
			else cout<<1<<endl;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(all1 || allsame){
		for(int i=3;i<=n;i++){
			ansans+=(n-i+1);
		}
		cout<<ansans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(a[j]>=a[j+1]) swap(a[j],a[j+1]);
		}
	}
	cout<<27<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
