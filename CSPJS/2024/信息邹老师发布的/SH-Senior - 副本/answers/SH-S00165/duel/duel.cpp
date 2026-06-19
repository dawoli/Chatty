#include<bits/stdc++.h>
using namespace std;
int n,r[100010],vis[100010];
bool check(int r[],int n){
	for(int i=1;i<=n;i++){
		if(r[i]>2)  return false;
	}
	return true;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>r[i];
	sort(r+1,r+n+1);
	if(check(r,n)){
		int t=0;
		for(int i=1;i<=n;i++){
			if(r[i]==2) {
				t=i;
				break;
			} 
		}
		if(t==0) {
			cout<<n<<endl;
		}
		else if(n>=2*(t-1)) {
			cout<<n-t+1;
		} 
		else{
			cout<<t-1;
		}
	}
	else if(n<=sqrt(1e9)){
		int cnt=n;
		for(int i=1;i<=n-1;i++){
			for(int j=i;j<=n;j++){
				if(vis[j]==1||vis[i]==-1||r[i]==r[j])  continue;
				cnt--,vis[i]=-1,vis[j]=1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
