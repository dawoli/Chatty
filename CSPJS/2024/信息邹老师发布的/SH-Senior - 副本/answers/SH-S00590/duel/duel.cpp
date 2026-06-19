#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[100010],b[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	for(int i=1;i<=a[n-1];i++){
		m=b[i];
		for(int j=1;j<i;j++){
			if(b[j]>0){
				if(b[j]<m){
					b[j]=0;
					m=m-b[j];
				}
				else{
					b[j]=b[j]-m;
					break;
				}
			}
		}
	}
	for(int i=1;i<=a[n-1];i++){
		cnt=cnt+b[i];
	}
	cout<<cnt;
	return 0;
}
