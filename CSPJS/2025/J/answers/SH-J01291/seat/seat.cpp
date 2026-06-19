#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[101],c[101],l[101],rn,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]<0||a[i]>100){
			return 0;
		}
	}
	int r=a[0];
	sort(a,a+m*n);
	for(int i=0;i<m*n/2;i++){
		swap(a[i],a[m*n-i-1]);
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[f]=i;
				l[f]=j;
				f++;
			}
		}else{
			for(int j=n;j>=1;j--){
				c[f]=i;
				l[f]=j;
				f++;
			}
		}
	}
	for(int i=0;i<m*n;i++){
		if(a[i]==r){
			rn=i;
		}
	}
	cout<<c[rn]<<" "<<l[rn];
	return 0;
}

