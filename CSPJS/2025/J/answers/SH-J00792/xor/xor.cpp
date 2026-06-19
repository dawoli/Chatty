#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i]==1&&a[i+1]==1&&!vis[i]){
				cnt++;
				vis[i]=1;
			}  
		}
		cout<<cnt;
		return 0;
	}
	else if(k==1){
		int cnt1=0;
		int cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt2++;
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(a[i]==1 &&a[i+1]==0){
					cnt1++;
					vis[i+1]=1;
				}
				else if(a[i+1]==1 &&a[i]==0){
					cnt1++;
					vis[i+1]=1;
				}
			}
		}
		cout<<max(cnt1,cnt2);
	}
	return 0;
}
