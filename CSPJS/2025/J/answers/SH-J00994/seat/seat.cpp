#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[114],i,j,k;
bool cmp(int akioi,int bkioi){
	return akioi>bkioi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	i=0;
	j=1;
	k=1;
	while(a[k-1]!=x){
		if(j%2==1)i++;
		else i--;
		if(i>n){
			i--;
			j++;
		}
		if(i<1){
			i++;
			j++;
		}
		k++;
	}
	cout<<j<<' '<<i<<endl;
	return 0;
}
