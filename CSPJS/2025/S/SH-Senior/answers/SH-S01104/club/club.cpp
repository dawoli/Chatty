#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100015],a2[100015],a3[100015],m[100015],s[100015],z[100015],m1,m2,m3,cnt,c[100015],sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		cnt=0,m[100015]={0},s[100015]={0},z[100015]={0},m1=0,m2=0,m3=0,c[100015]={0},sum=0;
		for (int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			m[j]=max(a1[j],max(a2[j],a3[j]));
			cnt+=m[j];
			s[j]=min(a1[j],min(a2[j],a3[j]));
			if (a1[j]==m[j]&&a2[j]==s[j]) z[j]=a3[j];
			if (a1[j]==m[j]&&a3[j]==s[j]) z[j]=a2[j];
			if (a2[j]==m[j]&&a3[j]==s[j]) z[j]=a1[j];
			if (a2[j]==m[j]&&a1[j]==s[j]) z[j]=a3[j];
			if (a3[j]==m[j]&&a1[j]==s[j]) z[j]=a2[j];
			if (a3[j]==m[j]&&a2[j]==s[j]) z[j]=a1[j];
			if (a1[j]==m[j]) m1++;
			if (a2[j]==m[j]) m2++;
			if (a3[j]==m[j]) m3++;
			c[j]=m[j]-z[j];
		}
		sort (c,c+n);
		for (int j=1;j<=n;j++){
//			cout<<c[j]<<' ';
			if (m1>n/2) sum+=m1-n/2,m1=0;
			else if (m2>n/2) sum+=m2-n/2,m2=0;
			else if (m3>n/2) sum+=m3-n/2,m3=0;
		}
//		cout<<cnt<<' '<<sum<<endl;
		for (int j=1;j<=sum;j++){
			cnt-=c[j];
		}
		cout<<cnt<<endl;
	}
//		for (int j=1;j<=n;j++){
//			cout<<m[j];
//		}
//		cout<<endl;
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
