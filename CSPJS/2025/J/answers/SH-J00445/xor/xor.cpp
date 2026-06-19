#include<bits/stdc++.h> 
using namespace std;
int n,k;
//如过部分分 a开int否则开ll 
int a[100005];
long long sum[100005];
struct node{
	int l,r;
}ans[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int p=0;
	int i=1;
	while(i<=n){
		bool flag=0;
		int j=i;
		while(j<=n){
			long long x=sum[j]^sum[i-1];
			if(x==k){
				p++;
				ans[p].l=i;
				ans[p].r=j;
				flag=1;
				break;
			}
			j++;
		}
		if(flag)i=j+1;
	}
	cout<<p;
}
