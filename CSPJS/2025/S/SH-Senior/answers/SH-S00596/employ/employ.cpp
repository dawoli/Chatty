#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[509],zhuan[509],ans,zong,sum;
long long jie(long long a){
	long long ans=1;
	for(long long i=2;i<=a;i++){
		ans*=i;
		ans%=998,244,353;
	}
	return ans;
}
long long pailie(long long m,long long n){
	return jie(n)/jie(n-m);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int index=1,flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]-'0'==flag) zhuan[index]++;
		else{
			zhuan[++index]++;
			flag=flag^1;
		}		
	}
	sort(c+1,c+n+1);
	int tt=0,mx=0,duo=0;
	for(int i=2;i<index;i+=2){
		tt+=zhuan[i];
	}
	zong=jie(n);
	mx=n-m;
	duo=mx-tt;
	if(duo<0){
		cout<<0;
		return 0;
	}
	int now=0;
	for(int i=1;i<index;i++){
		if(i%2==0){
			now+=zhuan[i];
			continue;
		}
		int k=upper_bound(c+1,c+n+1,now)-c-1;
		if(k>duo){
			int min=k-duo+1;
			int dui=0;
			for(int j=i;j<index;j+=2){
				dui+=zhuan[j];
			}
			for(int j=min;j<=k;j++){
				sum+=pailie(j,dui);
			}
		}
		
	}
	ans=(zong-sum+998,244,353)%998,244,353;
	cout<<ans;
	return 0;
}
