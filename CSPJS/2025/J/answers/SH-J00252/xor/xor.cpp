#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500009],_l[500009],_r[500009];
int n,k,ans=0,cur=0;
bool check(int l,int r){
	for(int i=1;i<=cur;i++){
		if(l>=_l[i]&&l<=_r[i]||r<=_l[i]&&r<=_r[i])  return false;
	}
	return true;
}
signed main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n+1;i++){
		int last=a[i];
		for(int j=i+1;j<=n+1;j++){
			if(last==k&&check(i,j-1)){
				ans++;
				_l[++cur]=i;
				_r[cur]=j-1;
				break;
			}
			last=last xor a[j];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//²î²»¶à60°É 
