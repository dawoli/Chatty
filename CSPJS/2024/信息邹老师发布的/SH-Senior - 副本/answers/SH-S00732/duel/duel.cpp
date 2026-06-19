#include<bits/stdc++.h>
using namespace std;
int n,l=0,r=0,a[100002],b[100002];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(l==r||a[i]==b[l]){
			b[r++]=a[i];
		}else{
			b[r++]=a[i];
			l++;
		}
	}
	cout<<r-l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
