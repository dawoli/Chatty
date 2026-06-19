#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5020];
int b[5020];
int find(int x,int sm){
	if(x<n-1){
		find(x+1,sm);
		find(x+1,sm+a[x]);
	}
	if(sm>a[x])ans++;
	return 0;
}
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i]=a[i];
		if(b>0)b[i]+=b[i-1];
	}
	sort(a,a+n);
	find(0,0);
	
	cout << ans;
	
}
