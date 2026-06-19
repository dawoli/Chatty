#include<bits/stdc++.h>
using namespace std;

long long n,k,sum,aa,l;
long long a[100000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>a[i];
	
	for(int i = 0;i<=n;i++){
		
		if(aa^a[i]==k ) {
			if(l==0) {
				aa^=a[i];
				l++;
			}
			else{
				sum++;
				aa=0;
				l=0;
			}
		}
		else {
			aa^=a[i];
			l++;
		}
	}
	cout<<sum;
	return 0;
}
