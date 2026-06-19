#include<iostream>
using namespace std;
long long a[100005],k;
int dp[100005];
struct node{
	int s,l;
}b[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m=0;
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[i-1]^a[j])==k){
				m++;
				b[m].s=j;
				b[m].l=j-i+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=b[i].s;j--){
			dp[j]=max(dp[j],dp[j-b[i].l]+1);
		}
	}
	cout<<dp[n];
	return 0;
	fclose(stdin);
	fclose(stdout);
}
