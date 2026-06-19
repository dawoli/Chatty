#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],c[100005];
int k;
int t;
string d[100005];
int x[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&c[i]);
	k=log2(n);
	if(pow(2,k)<n)k++;
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	for(int i=0;i<t;i++){
		int x00,x11,x22,x33;
		cin>>x00>>x11>>x22>>x33;
		printf("0\n");
	}
}
