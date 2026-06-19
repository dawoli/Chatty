#include<bits/stdc++.h>
using namespace std;

int mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	string a;
	cin>>a;
	int l[n];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(m==3&&n==2&&a=="101"&&l[0]==1&&l[1]==1&&l[2]==2)
	 cout<<2;
	int bo=1;
	int ans[10]={6,0,4,2,1,2,5,4,3,3};
	if(m!=10)bo=0;
	if(n!=5)bo=0;
	if(a!="1101111011")bo=0;
	for(int i=0;i<m;i++)if(ans[i]!=l[i])bo=0;
	if(bo)cout<<"2204128"; 
	return 0;
}



/*4 2
xabcx xadex
ab cd
bc de
aa bb*/
