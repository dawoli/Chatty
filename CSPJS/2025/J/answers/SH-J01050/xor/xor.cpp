#include<iostream>
using namespace std;
int a[500005],n,k,ans,f,cnt;
int vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			if(vis[i]>=1){
				vis[i]++;
			} 
		}
		cnt=0;
		int L=1,R=L+l-1;
		int t=a[L];
		if(vis[L]){
			cnt++;
		}
		for(int i=L+1;i<=R;i++){
			if(vis[i]){
				cnt++;	
			}
			t^=a[i];
		}
		while(R<=n){
			if(t==k&&cnt==0){
				ans++;
				for(int i=L;i<=R;i++){
					vis[i]=1;
				}
			}
			t^=a[L];
			L++;
			R++;
			t^=a[R]; 
			if(vis[L-1]>1){
				cnt--;
			}
			if(vis[R]){
				cnt++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
