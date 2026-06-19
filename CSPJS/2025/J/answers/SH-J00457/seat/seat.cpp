#include<bits/stdc++.h>
using namespace std;
int n,m,a[125];
int j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int zw=n*m;
	for(int i=1;i<=zw;i++){
		cin>>a[i];
	}
	int R=a[1];
	
	sort(a+1,a+zw,cmp);
	
	for(int i=1;i<=zw;i++){
		if(a[i]==R){
			j=i;
		}
	}
	
	if(j%2==0){
		cout<<j/m<<' ';
		cout<<n-(j%m);
	}if(j%2!=0){
		cout<<j/m+1<<' ';
		cout<<n-((j%m)+1);
	}
	fclose(stdin);
	fclose(stdout);
}
