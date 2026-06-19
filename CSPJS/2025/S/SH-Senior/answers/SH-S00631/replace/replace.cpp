#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,cnt,len,flag,cc;
string str1[200005],str2[200005],t1[200005],t2[200005];
int Judge(char s1[],string ss) {
	if(cc!=ss.size()) return 0;
	else {
		for(int i=0;i<cc;i++) {
			if(s1[i]!=ss[i]) return 0;
		}
	}
	return 1;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) {
		cin>>str1[i]>>str2[i];
	}	
	for(int i=1;i<=q;i++) {
		cnt=0;
		cin>>t1[i]>>t2[i];
		int len=t1[i].size();
		for(int ii=0;ii<len;ii++) {
			for(int j=ii;j<len;j++) {
				flag=0;
				char s1[200005],s2[200005];
				cc=0;
				for(int l=ii;l<=j;l++) {
					s1[cc++]=t2[i][l];
					s2[cc++]=t2[i][l];
				}
				for(int k=0;k<ii;k++) {
					if(t1[i][k]!=t2[i][k]) flag=1;
				}
				for(int k=len-1;k>j;k--) {
					if(t1[k]!=t2[k]) flag=1;
				}
				if(flag==1) continue;
				for(int k=1;k<=n;k++) {
					if(Judge(s1,str1[k])&&Judge(s2,str2[k])) {
						cnt++;
					}
				} 
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
} 
/*

*/
