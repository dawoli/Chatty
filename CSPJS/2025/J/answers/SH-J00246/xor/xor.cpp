#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],p[500005];
bool all1(){
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			return false;
	return true;
}
bool under1(){
	for(int i=1;i<=n;i++)
		if(a[i]>1)
			return false;
	return true;
}
void solve0(){
	cout<<n/2;
}
void solve1(){
	int cnt=0;
	for(int i=1;i<n;i++){
		if(a[i]==k)
			cnt++;
		else if(a[i]^a[i+1]==k)
			cnt++,i++;
	}
	cout<<cnt;
}
bool check(int mid){
	int pos=0,j;
	for(int i=1;i<=mid;i++){
		for(j=pos+1;j<=n&&p[j]^p[pos]!=k;j++);
		if(p[j]^p[pos]==k)
			pos=j;
		else
			return false;
	} 
	return true;
}
void solveBF(){
	int l=0,r=n,ans=r;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1,ans=mid;
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	if(all1())
		solve0();
	else if(under1())
		solve1();
	else
		solveBF();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
