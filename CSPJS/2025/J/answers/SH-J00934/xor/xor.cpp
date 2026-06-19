#include<bits/stdc++.h>
using namespace std;

int n,k,p,ans,a[500010],s[500010],lst[2200000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		int tmp=s[i]^k;
		if(lst[tmp]>=p){
			p=i;
			ans++;
		}
		lst[s[i]]=i;
	}
	cout<<ans;
	return 0;
}
