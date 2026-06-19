#include<iostream>
#include<cstdio>
using namespace std;
int dp[200006];
int a[500005];
int n,k,cnt=0;
int max_cnt=0;
int qujian(int l,int r){
	int t=a[l];
	for(int i=l+1;i<=r;i++){
		t=t^a[i];
	}
	return t;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}

	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int l=i;l<=n;l++){
			for(int r=l;r<=n;r++){
				if(qujian(l,r)==k){
					cnt++;
					l=r+1;
				}
			}
		}
		if(cnt>max_cnt)max_cnt=cnt;
		cnt=0;
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=n;j>=1;j--){
//			for(int l=i;l<=n;l++){
//				for(int r=l;r<=n;r++){
//					if(qujian(l,r)==k&&dp[j-r+1]+1>=dp[j]){
//						dp[j]=dp[j-r]+1;
//						l=r+1;
//					}
//				}
//			}
//		}
//	}
//	cout<<dp[n];
	
	cout<<max_cnt;
	return 0;
}

