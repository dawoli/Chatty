#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],ans,last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}for(int i=n;i>=1;i--){
		long long cnt=a[i];
		bool flag=0;
		if(cnt==k){
			b[i]=i;
			continue;
		}
		for(int j=i-1;j>=1;j--){
			cnt=(cnt|a[j])-(cnt&a[j]);
			if(cnt==k){
				b[i]=j;
				flag=1;
				break;
			}
		}if(!flag)b[i]=n+1;
	}last=n+1;
	for(int i=n;i>=1;i--){
		if(i<last and b[i]!= n+1){
			ans++;
			last=b[i];
		}if(b[i]>last and b[i]!=n+1){
			last=b[i];
		}
	}cout<<ans;
	return 0;
}

