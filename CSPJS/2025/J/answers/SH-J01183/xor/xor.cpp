#include<bits/stdc++.h>
using namespace std;
long long n,a[111111],k,d=1,ans=0,cnt=0;
struct o{
	long long be,en;
}b[111111];
bool cmp(const o&a,const o&b){
	if(a.en==b.en){
		return a.be>b.be;
	}
	return a.en<b.en;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long c=a[i];
		if(c==k){
			b[d].be=i;
			b[d].en=i;
			d++;
		}
		for(int j=1;j<=n-i;j++){
			c=c^a[j+i];
			if(c==k){
			b[d].be =i;
			b[d].en =j+i;
			d++;
			}
		}
	}
	sort(b+1,b+d,cmp);
	for(int i=1;i<d;i++){
		if(b[i].be>cnt){
			cnt=b[i].en;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
