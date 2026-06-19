#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N],n,num=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(int k=j+1; k<=n; k++) {
				if(a[i]+a[j]+a[k]>=2*a[k] && i!=j && j!=i && i!=k) {
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
} 
