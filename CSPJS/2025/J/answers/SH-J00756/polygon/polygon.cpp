#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,k,r=0;cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	m=0;k=0;
	for(int i=0;i<n-2;++i){
		for(int j=i+2;j<n;++j){
			for(int x=i;x<=j;++x){
			    if(a[x]>m)m=a[x];
			    k+=a[x];
			}
			if(2*m<k)r+=1;
		    m=0;k=0;
		}
	}
	cout<<r<<endl;
	delete[]a;
	fclose(stdin);fclose(stdout);
	return 0;
}
