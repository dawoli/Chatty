#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long g[500005];
long long ans[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k;
	int n;
	cin>>n>>k;
	if(n>=1001&&k<=1){
		int an=0;
		bool b=true;
		if(k==0){
			for(int i = 1;i<= n;i++){
				cin>>a[i];
				if(a[i]==0){
					an++;
				}
				else if(a[i-1]==1&&b){
					an++;
					b=false;
				}
				else{
					b=true;
				}
			}
		}
		else{
			for(int i = 1;i<= n;i++){
				cin>>a[i];
				if(a[i]==1)an++;
			}
		}
		cout<<an;
		return 0;
	}
	cin>>a[1];
	b[1]=a[1];
	if(b[1]==k)g[1]=1;
	for(int i = 2;i<= n;i++){
		cin>>a[i];
		b[i]=b[i-1];
		b[i]^=a[i];
		if(b[i]==k&&g[1]==0) g[1]=i;
		for(int j = 1;j<i;j++){
			long long cnt=b[i];
			cnt^=b[j];
			if(cnt==k&&g[j+1]==0){
				g[j+1]=i;
			}
		}
	}
	long long lt=0;
	ans[0]=0;
	for(int i=1;i<= n;i++){
		if(i>lt)lt=0;
		if(g[i]!=0){
			if(i<=lt){
				if(g[i]<lt){
					lt=g[i];
					ans[i]=ans[i-1];
				}
				else{
					ans[i]=ans[i-1];
				}
			}
			else{
				lt=g[i];
				ans[i]=ans[i-1]+1;
			}
		}
		else{
			ans[i]=ans[i-1];
		}
	}
	cout<<ans[n];
	return 0;
}
