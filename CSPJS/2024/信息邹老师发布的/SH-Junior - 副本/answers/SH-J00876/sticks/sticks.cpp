#include<bits/stdc++.h>
using namespace std;
int n,T,gs[10]={6,2,5,5,4,5,6,3,7,6},ans[50005],c=50001,a[50005];
//void dfs(int n,int cs){
//	if(cs>c||n<0){
//		return;
//	}
//	if(n==0){
//		int flag1=1;
//		if(cs=c){
//			for(int i=1;i<=c;i++){
//				if(a[i]<ans[i]){
//					flag1=0;
//					break;
//				}
//			}
//		}
//		if(cs<c||flag1){
//			for(int i=1;i<=c;i++){
//				ans[i]=a[i];
//			}
//			for(int i=c+1;i<=cs;i++){
//				ans[i]=0;
//			}
//		}
//		cs=c;
//		return;
//	}
//	for(int i=9;i>=0;i--){
//		if(cs==0&&i==0) break;
//		a[cs]=i;
//		dfs(n-gs[i],cs+1);
//	}
//}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int ij=1;ij<=T;ij++){
		cin>>n;
		for(int i=1;i<=50000;i++){
			ans[i]=10;
		}
		if(n%7==0){
			for(int i=0;i<n/7;i++){
				cout<<8;
			}
		}
		else if(n%7==1){
			cout<<10;
			for(int i=0;i<=n/7-2;i++) cout<<8;
		}
		else if(n==1) cout<<-1;
//		dfs(n,0);
//		for(int i=1;i<=c;i++){
//			cout<<ans[i];
//		}
//		cout<<endl;
	}
	return 0;
}
