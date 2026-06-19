#include<iostream>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N];
int n,k,cnt;
int check(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++)
	   ans=ans|a[i];
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=1;
	while(l<=r && r<=n){
		int t=check(l,r);
		cout<<l<<" "<<r<<":"<<t<<endl;
		if(t==k)cnt++,l=r+1,r++;
		else if(t<k)r++;
		else l++,r++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
