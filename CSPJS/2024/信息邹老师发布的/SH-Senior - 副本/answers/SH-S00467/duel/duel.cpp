#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	long long sm=0,sum=0;
	for(int i=0;i<=100005;i++){
		if(a[i]>=sm){
			sum+=sm;
			sm=a[i]+a[i]-sm;
		}
		else{
			sum+=a[i];
			sm-=a[i];
		}
	}
	cout<<n-sum;
	return 0;
} 
