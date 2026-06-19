#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long aa[100010];
long long qian[100010];
long long ans[100010];
long long c[100010];
int _log2(long long num){
	if(num==1)return 1;
	
	int res=0;
	num--;
	while(num){
		num/=2;
		res++;
	}
	return res;
}
int _pow(int num1,int num2){
	int ans=1;
	for(int i=1;i<=num2;i++){
		ans*=num1;
	}
	return ans;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	for(int i=1;i<=m;i++){
		int c[i];
		cin >> c[i];
	}
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		long long x0,x1,x2,x3;
		cin >> x0 >> x1 >> x2 >> x3; 
		memset(ans,0,sizeof(ans));
		memset(aa,0,sizeof(aa));
		for(int i=1;i<=n;i++){
			if(i%4==0)aa[i]=a[i]^x0;
			if(i%4==1)aa[i]=a[i]^x1;
			if(i%4==2)aa[i]=a[i]^x2;
			if(i%4==3)aa[i]=a[i]^x3;
			
			if(a[i]>=_log2(i)){
				ans[i]=ans[i-1]+aa[i];
			}
			else{
				ans[i]=ans[i-1];
			}
		}
		for(int i=1;i<=n;i++){
			if(_pow(2,_log2(i))!=i){
				ans[i]+=(i+1+_pow(2,_log2(i)))*(_pow(2,_log2(i)-i))/2;
			}
		}
		long long res=0;
		for(int i=1;i<=m;i++){
			res^=(i*ans[c[i]]);
		}
		cout << res << endl; 
	}

	return 0;
}

