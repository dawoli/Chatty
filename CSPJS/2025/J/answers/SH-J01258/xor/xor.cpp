#include<bits/stdc++.h>
using namespace std;

struct node{
	long long x;
	bool y;
}t;
long long n,k,a[500010],l,r,ans;

node calc(long long l){
	long long ans=a[l],i;
	node b;
	b.y=false;
	for(i=l+1;a[i]!=k&&i<=n;i++){
		ans=(ans^a[i]);
		if(ans==k){
			i++;
			b.y=true;
			break;
		}
	}
	b.x=i;
	return b;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=r=1;
	while(l<=n){
		if(l==r&&a[l]==k){
			ans++;
			l++;
			r++;
		}else{
			t=calc(l);
			l=r=t.x;
			if(t.y) ans++;
		}
	}
	cout<<ans<<endl;
}

