#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	long long st,en;
}x[1000005];
long long n,a[1000005],d,vis[1000005],ans,k;
bool cmp(node x,node y){
	if(x.en==y.en)return x.st<y.st;
	else return x.en<y.en;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x[++d].num=a[i];
		x[d].st=i;
		x[d].en=i;
		for(int j=i+1;j<=n;j++){
			int c=d;
			x[++d].num=x[c].num^a[j];
			x[d].st=i;
			x[d].en=j;
		}
	}
	sort(x+1,x+1+d,cmp);
	for(int i=1;i<=d;i++){
		if(x[i].num==k){
			bool pd=true;
			for(int j=x[i].st;j<=x[i].en;j++){
				if(vis[j]==1){
					pd=false;
					break;
				}
			}
			if(pd){
				for(int j=x[i].st;j<=x[i].en;j++){
					vis[j]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
