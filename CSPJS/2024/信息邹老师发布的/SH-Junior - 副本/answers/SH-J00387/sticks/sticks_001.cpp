#include<bits/stdc++.h>
using namespace std;
int T,a[100005];
int res[100005]={-1,-1,1,7,4,2,6,8,10,18,23,26,28,68,88,268,288,229,208};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a[i];}
	for(int i=0;i<T;i++){
		if(a[i]%7==0&&a[i]>18){
			for(int i=0;i<a[i]/7;i++){cout<<8;}}
		else if(a[i]%7==1&&a[i]>18){
			cout<<10;
			for(int i=1;i<a[i]/7;i++){cout<<8;}}
		else cout<<res[a[i]];}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
