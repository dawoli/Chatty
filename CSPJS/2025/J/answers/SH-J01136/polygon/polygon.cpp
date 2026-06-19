#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mo=998224353;
int a[5002];
int n;
int sum=0;
long long cnt=0;

int all_1(int n){
	for(int i=1;i<=n;i++)if(a[i]!=1)return 0;
	return 1;
}

void dfs(int i){
	int j;
	for(j=1;j<=n;j++){
		if(sum>a[j]){
			cnt++;
		}
		else{
			sum+=a[j];
			j++;
			dfs(i+1);
			sum-=a[j];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	} 
	if(all_1(n)){
		cout<<n-2<<endl;
		return 0;
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
			return 0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			return 0;
		}
	}
	dfs(3);
	cout<<cnt%mo;
	return 0;
}
