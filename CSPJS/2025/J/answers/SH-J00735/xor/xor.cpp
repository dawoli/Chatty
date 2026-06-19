#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,ans=0;
int a[maxn];
int sum[maxn];
struct node{
	int l,r;
};
vector<node> v;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	v.push_back(node{0,0});
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((sum[i]^sum[j-1])==k && v[v.size()-1].r<j){
				v.push_back(node{j,i}),ans++;
				break;
			}
	    }
	}
	  
//	int l,r,sum=a[1];l=r=1;
//	while(r<=n){
//		if(sum==k && v[v.size()-1].r<l)ans++,v.push_back(node{l,r});
//		r++;sum^=a[r];	
//		while(((sum^a[l])^k)<=(sum^k) && l<r){
//			sum^=a[l],l++;
//		}
//		printf("%d %d\n",l,r);
//	}
	printf("%d\n",ans);
	return 0;
}
