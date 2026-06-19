#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int a[N],c[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,num=0,flag=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n;i++) {
		for(int j=i,w=a[i]; j<=n; flag=0,w = a[i]) {
			for(int b=i+1; b<=j; b++) {
				w^=a[b];
			}
			if(w==m) {
				num++;
				i = j+1;
				j = i;
				flag=1;
			}
			if(flag==0) {
				j++;
			}
		}
	}
	cout<<num;
	return 0;
} 
