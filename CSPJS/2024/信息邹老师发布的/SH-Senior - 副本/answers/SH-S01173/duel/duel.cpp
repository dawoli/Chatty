#include<bits/stdc++.h>
using namespace std;
long long r[100500];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
//	freopen("duel4.in","r",stdin);
	long long n;
	long long l=0,c=0,d=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+n);
	long long ans=n;
	for(long long i=1;i<=n;i++){
//		printf("%d ",r[i]);
		if(r[i]!=r[i-1]){
			c+=d;
			d=0;
		}
		if(c>0){
			c--;
			ans--;
		}
		d++;
	}
	cout<<ans<<endl;
	return 0;
} 
