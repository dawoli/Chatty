#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string dp[N];
int n,q[N],maxn;
bool flag1=1,flag2=1;
string b[7]={"0","1","2","4","6","7","8"},s,s2;
int a[7]={6,2,5,4,6,3,7};
bool cmp(string a,string b){
    if(a.length()<=b.length()) return 1;
	return 0; 
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&q[i]);
    	if(q[i]%7) flag1=0;
    	if((q[i]-1)%7) flag2=0;
    	maxn=max(maxn,q[i]);
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=q[i]/7;j++) putchar('8');
			puts("");
		} 
	}else if(flag2){
		for(int i=1;i<=n;i++){
		    putchar('1');putchar('0');q[i]-=8;
		    for(int j=1;j<=q[i]/7;j++) putchar('8');
		    puts("");
		}
	}else{
		for(int i=0;i<=maxn;i++) dp[i]="-";
		dp[0]="";dp[6]="0";dp[2]="1";dp[5]="2";dp[4]="4";dp[3]="7";dp[7]="8";
	    for(int i=1;i<=maxn;i++){
	    	s="-";
            for(int j=0;j<7;j++){
            	if(j==4) continue;
            	if(i-a[j]>=0 && dp[i-a[j]]!="-"){
            		if(s[0]=='-') s=dp[i-a[j]],s2=b[j];
            		else if(!cmp(s,dp[i-a[j]])) s=dp[i-a[j]],s2=b[j]; 
				}
			}
			if(s[0]!='-') dp[i]=s2+s;
		}
		for(int k=1;k<=n;k++){
	    	s="-";
	    	int i=q[k];
            for(int j=1;j<7;j++){
            	if(i-a[j]>=0 && dp[i-a[j]]!="-"){
            		if(s[0]=='-') s=dp[i-a[j]],s2=b[j];
            		else if(!cmp(s,dp[i-a[j]])) s=dp[i-a[j]],s2=b[j]; 
				}
			}
			if(s[0]!='-') cout<<s2<<s,puts("");
			else puts("-1");
		}
	}
	return 0;
}
