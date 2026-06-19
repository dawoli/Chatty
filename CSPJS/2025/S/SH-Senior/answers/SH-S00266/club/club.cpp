#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int aa,bb,cc,d,e;
}a[100010],b[100010];
bool cmp(node x,node y){
	return x.d>y.d;
}
bool cmp1(node x,node y){
	return x.e>y.e;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].aa>>a[i].bb>>a[i].cc;
			a[i].d=a[i].aa-max(a[i].bb,a[i].cc);
			a[i].e=a[i].bb-a[i].cc;
		}
		int maxans=0;
		sort(a+1,a+n+1,cmp);
		int i=1; 
		for(;i<=n/2;i++){
			if(a[i].d<0)break;
			ans+=a[i].aa;//cout<<'i'<<i;
		}
		int ans2=ans;
		for(i=i-1;i<=n/2;i++){
			for(int k=i;k<=n;k++)b[k]=a[k];//cout<<'i'<<i;
			sort(b+i+1,b+n+1,cmp1);
			int j;
			for(j=i+1;j<=i+n/2;j++){
				if(b[j].e<0)break;
				ans2+=b[j].bb;//cout<<'j'<<j;
			}
			for(int k=j;k<=n;k++){
				ans2+=b[k].cc;//cout<<'k'<<k;
			}
			if(ans2<maxans)break;
			maxans=max(maxans,ans2);ans2=ans+a[i+1].aa;ans+=a[i+1].aa;
		}
		cout <<maxans<<endl;
	}
	return 0;
}
