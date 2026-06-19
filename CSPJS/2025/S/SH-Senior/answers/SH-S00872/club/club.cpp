#include<bits/stdc++.h>
using namespace std;
int t,n,Ans;
const int N=10005;
struct{
	int ans[5];
}a[N];
struct{
	int cnt,q[10005];
}c[5];
int Maxn(int x){
	int p =-1,n=0;
	for(int i =1;i<=3;++i){
		if(a[x].ans[i]>p){
			p=a[x].ans[i];
			n=i;
		}
	}
	return n;
}
int Maxm(int x){
	int p =-1,n;
	for(int i =1;i<=3;++i){
		if(a[x].ans[i]>p&&i!=Maxn(x)){
			p=a[x].ans[i];
			n=i;
		}
	}
	return n;
}
bool cmp(int x,int y){
	return a[x].ans[Maxn(x)]-a[x].ans[Maxm(x)]<=a[y].ans[Maxn(y)]-a[y].ans[Maxm(y)];
}
int main(){
	cin>>t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i = 1;i<=t;++i){
		for(int j = 1;j<=3;++j){
			Ans=0;
			c[j].cnt=0;
			for(int k = 1;k<=n/2;k++){
				c[j].q[k]=0;
			}
		}
		cin>>n;
		for(int j = 1;j<=n;++j){
			cin>>a[j].ans[1]>>a[j].ans[2]>>a[j].ans[3];
			Ans+=a[j].ans[Maxn(j)];c[Maxn(j)].cnt++;c[Maxn(j)].q[c[Maxn(j)].cnt]=j;
		}
		for(int j=1;j<=3;++j){
			if(c[j].cnt>n/2){
				sort(c[j].q+1,c[j].q+c[j].cnt+1,cmp);
				for(int k = 1;k<=c[j].cnt-n/2;++k){
					Ans-=a[c[j].q[k]].ans[j];
					Ans+=a[c[j].q[k]].ans[Maxm(c[j].q[k])];
				}
			}
		}
		cout<<Ans<<endl;
	}
	return 0;
}
