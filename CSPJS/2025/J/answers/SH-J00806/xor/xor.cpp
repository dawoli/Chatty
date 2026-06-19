//#include<bits/stdc++.h>
//using namespace std;
//const int N=5e5+10;
//int n,k,a[N],sum[N],maxx,cnt;
//void dfs(int ans,int q){
//	bool flag=0;
//	if(n-q<ans)return;
//	for(int i=q;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(int(sum[j]^sum[i-1])==k){
//				maxx=max(maxx,ans+1);
////				cout<<i<<' '<<j<<' ';
////				cout<<int(sum[j]^sum[i-1])<<endl;
//				dfs(ans+1,j+1);
//				flag=1;
//			}
//		}
//	}
//	if(flag==0)return;
//}
//int main(){
//	//freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
//	cin>>n>>k;
//	bool flag1=1;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		sum[i]=sum[i-1]^a[i];
//		if(a[i]>1)flag1=0;
//		if(a[i]==1)cnt++;
//	}
//	if(flag1){
//		cout<<cnt;
//		return 0;
//	}
//	dfs(0,1);
//	cout<<maxx;
////	for(int i=1;i<=n;i++){
////		cout<<sum[i]<<' ';
////	}
//	
//	return 0;
//} 

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],sum[N],maxx,cnt,ans;
pair<int,int> p[N];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]>1)flag1=0;
		if(a[i]==1)cnt++;
	}
	if(flag1){
		if(k>1)cout<<0;
		else cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(int(sum[j]^sum[i-1])==k){
				p[++cnt].first=i;
				p[cnt].second=j;
			}
		}
	}
	sort(p+1,p+1+cnt);
	int now=0;
	for(int i=1;i<=cnt;i++){
		if(p[i].first>now){
			ans++;
			now=p[i].second;
		}
	}
	cout<<ans;
	return 0;
} 
