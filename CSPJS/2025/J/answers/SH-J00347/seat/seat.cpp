#include<bits/stdc++.h>
using namespace std;
int num[105];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>num[i];
	int nm=num[1],p;
	sort(num+1,num+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(num[i],num[n*m-i+1]);
		if(num[i]==nm) p=i;
		else if(num[n*m+1-i]==nm) p=n*m+1-i;
	} 
	int n1,m1;
	if(p%m==0) m1=p/m;
	else m1=p/m+1;
	n1=p-(m1-1)*m;
	if(m1%2==0) n1=n-n1+1;
	cout<<m1<<" "<<n1;
	return 0;
}
