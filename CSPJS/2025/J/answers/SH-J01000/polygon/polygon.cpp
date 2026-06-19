//RP++
#include <bits/stdc++.h>
#define N 5033
#define mod 998244353
using namespace std;
int a[N];
bool b[N];
int main(){
	freopen("polygon1.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,k=1,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt1=0;
	for(int i=1;i<=2<<n;i++){
		int t=i;
		k=1;
		while(t){
			b[k]=t%2;
			k++;
			t>>=1;
			//cout<<b[k]<<' ';
		}
		//cout<<endl;
		
		//cout<<cnt1<<endl;
		//if(cnt1<3) continue;
		int maxn=INT_MIN,sum=0;
		for(int i=1;i<=n;i++){
			//cout<<b[i]<<' ';
			if(b[i]){
				if(a[i]>maxn) maxn=a[i];	
				//cout<<b[i]<<' ';
				sum++;
			}
		}
		//cout<<endl;
		sum-=maxn;
		if(sum>2*maxn) cnt=cnt+cnt%mod;
	}
	cout<<cnt;
	return 0;
}
