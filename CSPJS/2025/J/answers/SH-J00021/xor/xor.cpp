#include<iostream> 
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool flag1=1;
	bool flag2=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=0;
		if(a[i]>1)  flag2=0;
	}
	if(flag1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(flag2&&k==0){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==0) ans++;
			else{//a[i]==1
				if(i+1==n) continue;
				if(a[i+1]==a[i]) ans++,i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(flag2&&k==1){
		int ans=0;
		for(int i=0;i<n;i++) if(a[i]) ans++;
		cout<<ans;
	}
}
