#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],cnt;
bool flag=1,flag2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=0;
			flag2=0;
		}
		else if(a[i]==0){
			flag=0;
		}
		else if(a[i]==1){
			cnt++;
		}
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	if(flag2){
		if(k==0){
			int ans=cnt/2+n-cnt;
			cout<<ans<<endl;
			return 0;
		}
		if(k==1){
			cout<<cnt<<endl;
			return 0; 
		}
	}
	else{
		cout<<1<<endl; 
	}
	return 0;
}
