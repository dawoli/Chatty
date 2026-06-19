#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
int srt(int m,int c[]){
	int cnt=0;
	for(int i=0;i<m;i++)cnt+=c[i];
	return cnt;
}
int polgon(int s,int b[]){
	if(s<3)return 0;
	for(int i=3;i<s;i++)
		for(int j=0;j<s-2;j++){
			if(srt(i,b)>2*b[j])ans++;
			break;
		}
	return polgon(s-1,b);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	polgon(n,a);
	cout<<ans*3;
	return 0;
}
