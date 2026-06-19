#include <bits/stdc++.h> 
using namespace std;
#define maxn 100010
int a[maxn];
bool vis[maxn];
int cnt=0,cnt1=0,cnt2=0;
int main(){
	freopen("duel.in ","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt2++;
		if(a[i]==1) cnt1++;
	} 
	if(cnt2>30){
		int rest2=n-cnt1;
		if(rest2>=cnt1){
			cout<<rest2;
			return 0;
		}
		else{
			cout<<cnt1;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--){
		for(int j=i-1;j>=1;j--){
			if((a[i]>a[j])&&(vis[j]==0)){
				vis[j]=1;
				cnt++;
				break;
			} 
		}
	}
	cout<<n-cnt;
	return 0;
}
