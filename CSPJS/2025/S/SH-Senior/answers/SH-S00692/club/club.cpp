#include<bits/stdc++.h>
using namespace std;
struct node1 {
	int maxn,cha,bu;
} a[114514];
struct node2 {
	int v,tyx;
} b[5];
bool cmp1(node1 x,node1 y) {
	return x.cha<y.cha;
}
bool cmp2(node2 x,node2 y) {
	return x.v>y.v;
}
int sum[5];
void solve() {
	int n,ans=0;
	cin>>n;
	memset(sum,0,sizeof(sum));
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d",&b[1].v,&b[2].v,&b[3].v);
		b[1].tyx=1;
		b[2].tyx=2;
		b[3].tyx=3;
		sort(b+1,b+4,cmp2);
		a[i].maxn=b[1].v;
		a[i].cha=b[1].v-b[2].v;
		a[i].bu=b[1].tyx;
		sum[a[i].bu]++;
		ans+=a[i].maxn;
	}
	sort(a+1,a+n+1,cmp1);
	for(int eer=1; eer<=3; eer++) {
		if(sum[eer]>n/2) {
			int i=1;
			while(sum[eer]>n/2) {
				if(a[i].bu==eer) {
					sum[eer]--;
					ans-=a[i].cha;
				}
				i++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}
/*
拿到这个题目，她笑了。
笑着说：“啊！我会，我会，我会！
讨厌，题目都没看你就说你会，你是来搞笑的吧！
*/ 
