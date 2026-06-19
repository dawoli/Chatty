#include<bits/stdc++.h>
using namespace std;
struct q{
	int l,r,w=0;
} ans[100005];
int n,k,nums[500005];
int x(int l,int r){
	if(l==r) return nums[l];
	else return nums[l]^x(l+1,r);
}
bool cmp(q a,q b){
	return a.w<b.w; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x(i,j)==k){
				ans[cnt].l=i;
				ans[cnt].r=j;
				cnt++;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(ans[i].r>ans[j].l){
				ans[i].w++;
				ans[j].w++;
			}
		}
	}
	sort(ans,ans+cnt,cmp);
	int c=0,a=0,an[100005];
	for(int i=0;i<cnt;i++){
		bool flag=1;
		for(int j=0;j<a;j++){
			if(ans[i].l<=ans[an[j]].r&&ans[i].r>=ans[an[j]].l){
				flag=0;
				break;
			}
		}
		if(flag){
			an[a++]=i;
		}
	}
	cout<<a;
	return 0;
} 
