#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
int sum[500007];
int a[500007],mp[500007];
struct node{
	int l,h,e;
}b[500007];
int f(int a,int b){
	int c=0,m=1;
	for(int i=1;i<=23;i++){
		if(a%2!=b%2) c+=m;
		a/=2;
		b/=2;
		m*=2;
	}
	return c;
}
bool cmp(node A,node B){
	return A.l>B.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=f(sum[i-1],a[i]);
	}
	int x=0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f(sum[i],sum[j])==k){
				x++;
				b[x].l=j-1+1;
				b[x].h=i;
				b[x].e=j;
			}
		}
	}
	sort(b+1,b+x+1,cmp);
	for(int i=1;i<=x;i++){
		if(mp[b[i].h]!=0) continue;
		for(int j=b[i].h;j<=b[i].e;j++){
			mp[j]=1;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}
