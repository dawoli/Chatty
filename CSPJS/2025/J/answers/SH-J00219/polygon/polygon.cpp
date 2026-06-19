#include<bits/stdc++.h>
using namespace std;
int a[5000],ans,maxn;
void check(int r,int suml){
	if(suml>maxn)ans++;
	for(int i=r;i>0;i--){
		check(i-1,suml+i);
	}
}
int main(){
	freopen("polygon.in","r");
	freopen("polygon.out","w");
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>0;i--)check(i,0);
	cout<<ans;
	return 0;
}
