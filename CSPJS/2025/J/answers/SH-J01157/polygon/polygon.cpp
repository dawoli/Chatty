#include<bits/stdc++.h>
using namespace std;
int a[20000],b,n,m,aa,c,d,e;
char s[2000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		c=d;
		d+=a[i];
		
		for(int j=i;j<n;j++){
			c+=a[j];
			if(c>2*a[j]){
				e++;
			}
			}
	}
	cout<<e;
	
}
