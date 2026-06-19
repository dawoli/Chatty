#include<bits/stdc++.h>
using namespace std;
char csp[1000005];
int a[1000005],b[11],c[11],d[1000005],cnt=0,sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>csp;
	for(int i=0;i<strlen(csp);i++)
		if(csp[i]>='0'&&csp[i]<='9') a[cnt++]=csp[i]-'0';
	for(int i=0;i<cnt;i++) b[a[i]]++;
	for(int i=0;i<10;i++) sum+=b[i],c[i]=sum;
	for(int i=0;i<cnt;i++) d[c[a[i]]]=a[i],c[a[i]]--;
	for(int i=cnt-1;i>=0;i--) cout<<d[i];
	return 0;
}
