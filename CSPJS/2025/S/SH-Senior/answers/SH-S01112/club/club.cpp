#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
int t,n,res,cnt1,cnt2,cnt3;
struct node{
	int x,y,z;
}a[100005];
int calc(node t){
	int p=max(t.x,max(t.y,t.z));
	int q=min(t.x,min(t.y,t.z));
	int r=t.x+t.y+t.z-p-q;
	return p-r;
}
bool cmp(node x,node y){
	return calc(x)>calc(y);
}
void init(){
	res=0;
	cnt1=cnt2=cnt3=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int p=max(a[i].x,max(a[i].y,a[i].z));
			int q=min(a[i].x,min(a[i].y,a[i].z));
			int r=a[i].x+a[i].y+a[i].z-p-q;
			if(p==a[i].x){
				if(cnt1==n/2)res+=r;
				else res+=p,cnt1++;
			}else if(p==a[i].y){
				if(cnt2==n/2)res+=r;
				else res+=p,cnt2++; 
			}else{
				if(cnt3==n/2)res+=r;
				else res+=p,cnt3++; 
			}
		}
		printf("%d\n",res);
		init();
	}
	return 0;
}
