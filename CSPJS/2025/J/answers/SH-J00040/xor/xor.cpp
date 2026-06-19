#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool isa=1,isb=1;
int sum[500005];
struct node{
	int b,e;
}f[500005];
int cur;
bool cmp(node x,node y){
	return x.b<y.b;
}
int num[500005];
int ans;
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)isa=0;
		if(a[i]!=1&&a[i]!=0) isb=0;
	}
	if(isa){
		if(k==1) cout<<n<<endl;
		else cout<<n/2<<endl;
		return 0;
	}
	if(isb&&n>100){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1) cnt++;
			cout<<cnt<<endl;
			return 0;
		}
		else{
			int cnt=0,num=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
					cnt+=num/2;
					num=0;
				}
				else num++;
			}
			cout<<cnt+num/2<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				f[++cur].b=i,f[cur].e=j;
			}
		}
	}
	sort(f+1,f+cur+1,cmp);
	for(int i=1;i<=cur;i++){
		for(int j=1;j<=i;j++){
			if(f[i].b>f[j].e){
				num[i]=max(num[i],num[j]);
			}
		}
		num[i]++;
		ans=max(ans,num[i]);
	}
	cout<<ans<<endl;
	return 0;
}
