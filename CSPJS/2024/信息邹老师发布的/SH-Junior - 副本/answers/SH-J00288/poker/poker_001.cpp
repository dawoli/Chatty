#include<bits/stdc++.h>
using namespace std;
int n,h[100],d[100];
string s[100];
int ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>s[i];
	    if(s[i][0]=='C')h[i]=1;
	    if(s[i][0]=='S')h[i]=2;
	    if(s[i][0]=='H')h[i]=3;
	    if(s[i][0]=='D')h[i]=4;
	    if(s[i][1]=='A')d[i]=1;
	    else if(s[i][1]=='T')d[i]=10;
	    else if(s[i][1]=='J')d[i]=11;
	    else if(s[i][1]=='Q')d[i]=12;
	    else if(s[i][1]=='K')d[i]=13;
	    else d[i]=s[i][1]-'0';
	}
	for(int i=1;i<=4;i++)
	    for(int j=1;j<=13;j++)
	        for(int k=1;k<=n;k++){
	        	bool ok=0;
	            for(int l=1;l<k;l++)
	                if(h[k]==h[l]&&d[k]==d[l]){ok=1;break;}
	            if(h[k]==i&&d[k]==j&&ok==0)ans--;
	        }
	cout<<ans<<endl;
	return 0; 
} 
