#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		for(int s=i+1;s<n-1;s++){
			for(int p=s+1;p<n;p++){
				if(a[i]+a[s]>a[p]){
					q++;
				}
			}
		}
	}
	cout<<q;
	return 0;
}
