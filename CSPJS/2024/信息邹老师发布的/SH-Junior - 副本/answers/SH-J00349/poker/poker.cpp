#include<bits/stdc++.h>
using namespace std;
struct c{
	string x;
	long long y=0;
}a[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","r",stdout);
	long long n,m=1;
	cin>>n;
	string s;
	for (int i=1;i<=n;i++){
		cin>>s;
		bool flag=0;
		for (int j=1;j<=m;j++){
			if (a[j].x==s){
				a[j].y++;
				flag=1;
			}
		}
		if (flag==0){
			a[m].x=s;
			m++;
		}
	}
	cout<<52-m+1;
	return 0;
}
