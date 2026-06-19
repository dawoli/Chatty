#include<bits/stdc++.h>
#define N 111009
using namespace std;
int n;
int a[N];
int to[N];//第i号位置第一个比他大的位置j 
int vis[N];


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    if(a[1]==1 and a[n]<=2){
    	if(a[n]==1){
    		cout<<n;
    		return 0;
		}
    	int mid=0;
    	int l=1,r=n;
    	while(l<r){
    		mid=(l+r)>>1;
    		if(a[mid]==2){
    			r=mid;
			}
			else{
				l=mid+1;
			}
		}
		if(a[mid]==1){
			int l1=mid,r2=n-mid;
			cout<<max(l1,r2);
		}
		else{
			int l1=mid-1,r2=n-mid+1;
			cout<<max(l1,r2);
		}
		
		return 0;
	}
    int pre=2;
    for(int i=1;i<=n;i++){
    	int x=a[i];
    	for(int j=pre;j<=n;j++){
    		if(a[j]>x){
    			to[i]=j;
    			pre=j;
    			break;
			}
		}
	}
    int front=1;
    int prenum=0;
    while(1){
    	if(to[front]==0) break;
    	int on_off=0;
    	for(int j=max(prenum+1,to[front]);j<=n;j++){
    		if(vis[j]==0){
    			vis[j]=1;
    			prenum=j;
    			ans--;
    			on_off=1;
    			break;
			}
		}
		front++;
		if(on_off==0){
			break;
		}
	}
	cout<<ans;
	return 0;
}

