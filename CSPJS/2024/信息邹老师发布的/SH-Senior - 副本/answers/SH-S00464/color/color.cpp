#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+2;
int T,n,a[MAXN],dd[5]={1,2},b[MAXN],maxx=-1,c[1000002];
int check(){
	int sum=0;
	for(int i=2;i<=n;i++){
		int num=b[i];
		for(int j=i-1;j>=1;j--){
			if(b[j]==num&&a[j]==a[i]){
				sum+=a[i];
				break;
			}
		}
	}
	return sum;
}
int f(int lv){
	for(int i=0;i<2;i++){
		b[lv]=dd[i];
		if(lv<n)
		    f(lv+1);
		else{
			maxx=max(maxx,check());
		}
	}
	return maxx;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int flag=1,cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			c[a[i]]++;
			if(c[a[i]]>=2) flag=0;
		}
		if(flag==1){
			cout<<0<<endl;
			continue;
		}
		cout<<flag<<endl;
		cout<<f(1)<<endl;
	}
	return 0;
}
