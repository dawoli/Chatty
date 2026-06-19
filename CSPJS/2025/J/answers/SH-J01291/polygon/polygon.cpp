#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5001],sumn,maxn,tp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3||n>5000){
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<1||a[i]>5000){
			return 0;
		}
	}
	sort(a,a+n);
	maxn=a[n];
	for(int i=2;i<n;i++){
		for(int j=0;j<i;j++){
			for(int k=j;k<=i;k++){
				sumn+=a[j];
			}
			if(sumn>2*maxn){
				tp+=1;
			}
		cout<<sumn<<" ";
		
		}
		sumn=0; 
	}
	cout<<tp%998244353;
	return 0;
}
