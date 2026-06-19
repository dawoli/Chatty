#include <bits/stdc++.h>
using namespace std;
char s[100010],a[100010];
int c[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=100000,b=0,t=0;
	bool g=false;
	cin>>s;
	for(int i=0;i<n;++i){
		b++;
		if(s[i]==0)
		   break;
	}
	b--;
	for(int i=0;i<b;++i){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<b;++i){
		if(a[i]=='0')
		   c[i]=0;
		else
		    if(a[i]=='1')
		       c[i]=1;
		    else
		        if(a[i]=='2')
		           c[i]=2;
		        else
		            if(a[i]=='3')
		               c[i]=3;
		            else
		                if(a[i]=='4')
		                   c[i]=4;
		                else
		                    if(a[i]=='5')
		                       c[i]=5;
		                    else
		                        if(a[i]=='6')
		                           c[i]=6;
		                        else
		                            if(a[i]=='7')
		                               c[i]=7;
		                            else
		                                if(a[i]=='8')
		                                   c[i]=8;
		                                else
		                                    if(a[i]=='9')
		                                        c[i]=9;	
											else
											    c[i]=-1;	                      
	}
	for(int j=0;j<b;++j){
		for(int i=0;i<b;++i){
		    if(t<=c[i]){
		    	t=c[i];
		    	g=true;
			}
		    if(c[i]==-1)
		       continue;
	    }
	    if(g==true)
	       cout<<t;
	    for(int k=0;k<b;++k){
	    	if(t==c[k]){
	    		c[k]=-1;
	    		break;
			}
		}
		t=0;
		g=false;
	}
	return 0;
}
