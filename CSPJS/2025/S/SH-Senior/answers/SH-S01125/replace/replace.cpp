#include<bits/stdc++.h>
using namespace std;
int n,q,i,j,k,qm,ql,qr,ans;
int mov[5000010];
string s1,s2;
struct func{
	int m,l,r;//move,left,right
};
bool bmp(func f1, func f2){
	return f1.m<f2.m;
}
func f[200005];
int main(){//solve B
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);	
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s1>>s2;
		for(j=0;j<s1.length();j++)if(s1[j]!='a')break;
		f[i].l=j;
		f[i].r=s1.length()-j-1;
		for(j=0;j<s2.length();j++)if(s2[j]!='a')break;
		f[i].m=f[i].l-j;
		mov[f[i].m+2500000]=1;
	}
	sort(f+1,f+n+1,bmp);
	for(i=1;i<=q;i++){
		cin>>s1>>s2;
		for(j=0;j<s1.length();j++)if(s1[j]!='a')break;
		ql=j;
		qr=s1.length()-j-1;
		for(j=0;j<s2.length();j++)if(s2[j]!='a')break;
		qm=ql-j;
		ans=0;
		if(mov[qm+2500000]==1){
			for(j=1;j<=n;j++)if(f[j].m==qm)break;
			for(;f[j].m==qm;j++)if(f[j].l<=ql&&f[j].r<=qr)ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
