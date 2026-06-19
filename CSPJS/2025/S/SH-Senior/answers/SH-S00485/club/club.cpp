#include<iostream>
using namespace std;
int n;
int sch(int **a,int i,int p,int q,int r){
	if(i>=n)return 0;
	int mx=-1;
	if(p<n/2)mx=max(mx,sch(a,i+1,p+1,q,r)+a[i][0]);
	if(q<n/2)mx=max(mx,sch(a,i+1,p,q+1,r)+a[i][1]);
	if(r<n/2)mx=max(mx,sch(a,i+1,p,q,r+1)+a[i][2]);
	return mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		int **a=new int*[n];
		for(int i=0;i<n;i++)a[i]=new int[3];
		for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		cout<<sch(a,0,0,0,0)<<endl;
		for(int i=0;i<n;i++)delete[] a[i];
		delete[] a;
	}
	return 0;
}

