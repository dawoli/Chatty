#include<bits/stdc++.h> 
using namespace std;
int T,N;
long long n[4];
int num[4];
long long ans;
int f = 0;
struct x{
	int d[3];
	int n;
	int m;
}a[100001];
bool cmp(x a,x b){
	return a.n>=b.n;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
for(int t=1;t<=T;t++){
	ans=0;
	memset(a,0,sizeof(a));
	memset(n,0,sizeof(n));
	memset(num,0,sizeof(num));
	cin>>N;
	for(int i=1;i<=N;i++)	{
		for(int j=1;j<=3;j++){
			cin>>a[i].d[j];
		}
	}
	for(int i=1;i<=N;i++)	{
		a[i].m=1;
		int maxn=a[i].d[1],caxn=a[i].d[2];
		if(maxn<caxn){
			swap(maxn,caxn);
			a[i].m=2;
		}	
		if(maxn<a[i].d[3]){
			caxn=maxn,maxn=a[i].d[3];
			a[i].m=3;
		}	
		else if(caxn<a[i].d[3]) caxn=a[i].d[3];
		a[i].n=maxn-caxn;
	}
	sort(a+1,a+N+1,cmp);
	::f=0;
	for(int i=1;i<=N;i++){
		if(f==0){
			num[a[i].m]++;
			if(num[a[i].m]==N/2)f=a[i].m;
			n[a[i].m]+=a[i].d[a[i].m];
		}
		else{
			if(f==1) ans+=max(a[i].d[2],a[i].d[3]);
			else if(f==2) ans+=max(a[i].d[1],a[i].d[3]);
			else ans+=max(a[i].d[2],a[i].d[1]);
		}
	}
	for(int i=1;i<=3;i++)	ans+=n[i];
	cout<<ans<<endl;
}
return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
