#include<bits/stdc++.h> 
using namespace std;
typedef long long L;
struct area{
	L from=0;
	L to=0;
}a[500003];
L r[5000000],n,k,areidx;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(L i=0;i<n;i++){
		cin>>r[i];
	}
	for(L i=0;i<n;i++){
		L lst=r[i];
		L j=i+1;
		for(;j<n&&lst!=k;j++){
			lst^=r[j];
		}if(lst==k){
			area ls;
			ls.from=i;
			ls.to=j-1;
			a[areidx++]=ls;
		}
	}
	L yz=-10;
	L j=0;
	L ti=0;
	for(;ti>=0;j++){
		ti=-1;
		L tm=999999910;
		for(L i=0;i<areidx;i++){
			//cout<<a[i].from+1<<" "<<a[i].to+1<<endl;
			if(a[i].to<tm&&yz<a[i].from){
				ti=i;
				tm=a[i].to;
			}
		}
		yz=tm;
	}
	cout<<j-1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
