#include<bits/stdc++.h>
using namespace std;
#define int long long
int tree[800010],maxx[1000010],tag[800010],temp,f[2010][2010],ans;
int t,n,a[200010],maxsum;
int ls(int x) {
	return x<<1;
}
int rs(int x) {
	return x<<1|1;
}
void build(int x,int l,int r) {
	tree[x]=tag[x]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
}
void add_tag(int x,int l,int r,int num) {
	tree[x]+=num;
	tag[x]+=num;
}
void push_down(int x,int l,int r) {
	if(tag[x]) {
		int mid=l+r>>1;
		add_tag(ls(x),l,mid,tag[x]);
		add_tag(rs(x),mid+1,r,tag[x]);
		tag[x]=0;
	}
}
void update(int L,int R,int x,int l,int r,int num) {
	if(L<=l&&r<=R) {
		add_tag(x,l,r,num);
		return;
	}
	push_down(x,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(L,R,ls(x),l,mid,num);
	if(mid<R) update(L,R,rs(x),mid+1,r,num);
	tree[x]=max(tree[ls(x)],tree[rs(x)]);
}
int query(int now,int x,int l,int r) {
	if(now==l&&l==r) {
		return tree[x];
	}
	push_down(x,l,r);
	int mid=l+r>>1;
	if(now<=mid) return query(now,ls(x),l,mid);
	else return query(now,rs(x),mid+1,r);
}
signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		maxsum=0;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
			maxsum=max(maxsum,a[i]);
		}
		if(n<=2000) {
			memset(f,0,sizeof(f));
			for(int i=1; i<=n; i++) {
				for(int j=0; j<i-1; j++) {
					f[i][j]=f[i-1][j]+(a[i]==a[i-1])*a[i];
					f[i][i-1]=max(f[i][i-1],f[i-1][j]+(a[i]==a[j])*a[i]);
				}
			}
			ans=0;
			for(int i=0; i<n; i++) {
				ans=max(ans,f[n][i]);
			}
			printf("%lld\n",ans);
			continue;
		}
		build(1,0,n);
		for(int i=0; i<=maxsum; i++) maxx[i]=-1;
		for(int i=2; i<=n; i++) {
			temp=tree[1];
			if(maxx[a[i]]!=-1) {
				if(temp<query(maxx[a[i]],1,0,n)+a[i]) {
					temp=query(maxx[a[i]],1,0,n)+a[i];
				}
			}
			update(i-1,i-1,1,0,n,temp);
			if(maxx[a[i-1]]==-1||query(maxx[a[i-1]],1,0,n)<temp) {
				maxx[a[i-1]]=i-1;
			}

			if(a[i]==a[i-1]) {
//				cout<<a[i]<<"AA"<<endl;
				update(0,i-2,1,0,n,a[i]);
			}

//			cout<<tree[1]<<endl;
//			for(int j=1;j<=13;j++){
//				cout<<maxx[j]<<" ";
//			}
//			cout<<endl;
		}
		printf("%lld\n",tree[1]);
	}
	return 0;
}
