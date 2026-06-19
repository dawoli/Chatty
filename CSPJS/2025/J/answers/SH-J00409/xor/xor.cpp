#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,a[500010],b[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	int i=1,j=1,cnt=0;
	while(i<=n){
		int x=b[j]^b[i-1];
		if(a[i]==k){
			j=i+1;
			i=j;
			cnt++;
			continue;
		}
		if(a[j]==k){
			i=j+1;
			j=i;
			cnt++;
			continue;
		}
		if(x==k){
			cnt++;
			i=j+1;
			j=i;
		}
		else{
			if(j<n){
				j++;
			}
			else{
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

