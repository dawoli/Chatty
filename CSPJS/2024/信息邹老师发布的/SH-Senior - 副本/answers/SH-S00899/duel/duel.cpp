#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],ans,sum[100005],flag,x,y;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
		sum[a[i]]=x+1;
		}
		x++;
	}
	ans=n;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			if(b[a[i]]>=sum[a[i]]-y){
				ans-=sum[a[i]]-y;
				y+=(sum[a[i]]-y);
			}
			else{
				ans-=b[a[i]];
				y+=b[a[i]];
			}
		}
	}
	cout<<ans;
	return 0;
}
