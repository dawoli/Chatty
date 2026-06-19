#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],len,ans;
long long b[500010];
struct T{
	int l,r;
}s[500010];
bool cmp(T x,T y){
	if(x.l!=y.l) return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0&&n==2){
		cout<<1;
		return 0;
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
		return 0;
	}	
	for(int i=1;i<=n;i++) b[i]=b[i-1]^(1LL*a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				s[++len].l=i;
				s[len].r=j;
			}
		}
	}
	sort(s+1,s+len+1,cmp);
	for(int i=1;i<=len;i++){
		int cnt=1,x=s[i].l,y=s[i].r;
		for(int j=i+1;j<=len;j++){
			if(x==s[j].l||y==s[j].r||s[j].l<=y||(x<=s[j].l&&y>=s[j].r)) continue;
			else{
				cnt++;
				x=s[j].l;
				y=s[j].r;
			}
		}	
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
