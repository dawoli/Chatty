#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define M 1000009
int n,x[N],sum[N],lst[M]; 
long long f[N];
int cal(int l,int r){
	if(l > r) return 0;
	else return sum[r] - sum[l] + f[l];
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f)); memset(lst,0,sizeof(lst)); memset(sum,0,sizeof(sum));
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) scanf("%d",&x[i]);
		for(int i = 1;i <= n;i++){
			if(x[i] == x[i - 1]) sum[i] = x[i];
			sum[i] += sum[i - 1];
		}
		for(int i = 1;i <= n;i++){
			f[i] = f[i - 1] + 1ll * x[i] * (x[i] == x[i - 1]);
			if(lst[x[i]]) f[i] = max(f[i],0ll + x[i] + cal(lst[x[i]] + 1,i - 1));
			lst[x[i]] = i;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
