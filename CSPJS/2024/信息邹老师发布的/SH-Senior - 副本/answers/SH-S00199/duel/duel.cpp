#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[100010],b[100010],cha[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	a[0]=0;
	long long j=0;
	for(long long i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			j+=1;
			b[j]+=1;
		}else{
			b[j]+=1;
		}
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,b[i]);
	}
	/*b[j+1]=0;
	cha[0]=0;
	cha[1]=0;
	for(int i=2;i<=j+1;i++){
		if(b[i]<b[i-1])cha[i]=abs(b[i]-b[i-1]);
		else cha[i]=0;
	}
	for(int i=1;i<=n;i++){
		ans+=cha[i];
	}*/
	cout<<ans;
	//cout<<endl;
	//for(int k=1;k<=j;k++)cout<<b[k]<<" ";
	return 0;
}
//RP++++£¡£¡£¡£¡ 
