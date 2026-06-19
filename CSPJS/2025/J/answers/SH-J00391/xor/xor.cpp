#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500009],s[500009],cnt;
struct node{
	long long l,r;
}x[500009];
bool cmp(const node&i,const node&j){
	if(i.r!=j.r)return i.r<j.r;
	return i.l<j.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(long long r=n;r>0;r--){
		for(long long l=r;l>0;l--){
			if((s[r]^s[l-1])==k){
				x[++cnt]=(node){l,r};
				break;
			}
		}
	}
	if(cnt==0){
		cout<<0<<endl;
		return 0;
	}
	sort(x+1,x+cnt+1,cmp);
	int ans=1,last=x[1].r;
	for(int i=2;i<=cnt;i++){
		if(x[i].l>last){
			ans++;
			last=x[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}
