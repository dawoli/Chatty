#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
int T,n; 
int s[N][5];
int total;
int ca;
int cb;
int cc;
int ch[N];

int sw=0;
ll sum;
ll ans[9];
int u;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		for(int i=1;i<=n;i++) 
		    for(int j=1;j<=3;j++)
		        cin>>s[i][j];
		fill(ch+1,ch+n+1,0);
	    for(int i=1;i<=n;i++){
	        if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3]){
			    sum+=s[i][1];
				ch[i]=1;
				ca++;
		    }
	        else if(s[i][2]>=s[i][1]&&s[i][2]>=s[i][3]){
	        	sum+=s[i][2];
	        	ch[i]=2;
	        	cb++;
			}
	        else if(s[i][3]>=s[i][2]&&s[i][3]>=s[i][1]){
	        	sum+=s[i][3];
	        	ch[i]=3;
	        	cc++;
			}
	    }
		int d[N];
	    if(ca>n/2){
	    	for(int i=1;i<=n;i++)
	    		if(ch[i]==1){
					d[i]=min(s[i][1]-s[i][2],s[i][1]-s[i][3]);
					u++;
				}
	    }
		else if(cb>n/2){
		    for(int i=1;i<=n;i++)
	    		if(ch[i]==2){
	    			d[i]=min(s[i][2]-s[i][1],s[i][2]-s[i][3]);
	    			u++;
				}
		    }
	    else if(cc>n/2){
		    for(int i=1;i<=n;i++)
	    		if(ch[i]==3){
	    			d[i]=min(s[i][3]-s[i][1],s[i][3]-s[i][2]);
	    			u++;
		        }
		} 		
		sort(d+1,d+u+1);          
		if(ca>n/2)
            sw=ca-n/2;
        if(cb>n/2)
            sw=cb-n/2;
        if(cc>n/2)
            sw=cc-n/2;
        for(int i=1;i<=sw;i++){
        	sum-=d[i];
	    }
	    ans[k]=sum;
		sum=ca=cb=cc=sw=u=0;
	}
	for(int i=1;i<=T;i++)
		cout<<ans[i]<<endl;
	return 0;
}
