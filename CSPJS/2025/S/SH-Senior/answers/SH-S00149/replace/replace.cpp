#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,len,l,r,ans;
bool fl;
string s1,s2,x[N],y1[N],y2[N],z[N];
string xx,yy1,yy2,zz;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		fl=0;
		len=s1.length();
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				if(fl){
					r=j;
				}
				else{
					l=j;
					fl=1;
				}
			}
		}
		for(int j=0;j<l;j++){
			x[i]=x[i]+s1[j];
		}
		for(int j=l;j<=r;j++){
			y1[i]=y1[i]+s1[j];
			y2[i]=y2[i]+s2[j];
		}
		for(int j=r+1;j<len;j++){
			z[i]=z[i]+s1[j];
		}
	}
	for(int i=0;i<q;i++){
		ans=0;
		fl=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<endl;
			continue;
		}
		len=s1.length(); 
		for(int j=0;j<len;j++){
			if(s1[j]!=s2[j]){
				if(fl){
					r=j;
				}
				else{
					l=j;
					fl=1;
				}
			}
		}
		xx=yy1=yy2=zz="";
		for(int j=0;j<l;j++){
			xx=xx+s1[j];
		}
		for(int j=l;j<=r;j++){
			yy1=yy1+s1[j];
			yy2=yy2+s2[j];
		}
		for(int j=r+1;j<len;j++){
			zz=zz+s1[j];
		}
		for(int j=0;j<n;j++){
			if(y1[j]==yy1 && y2[j]==yy2){
				fl=1;
				if(x[j].length()<=xx.length() && z[j].length()<=zz.length()){
					for(int k=1;k<=x[j].length();k++){
						if(x[j][x[j].length()-k]!=xx[xx.length()-k]){
							fl=0;
							break;
						}
					}
					if(fl){
						for(int k=0;k<z[j].length();k++){
							if(z[j][k]!=zz[k]){
								fl=0;
								break;
							}
						}
					}
				}
				else{
					fl=0;
				}
				if(fl){
//					cout<<j<<' '<<x[j].length()<<' '<<z[j].length()<<endl; 
					ans++;
				}
			}
		}
//		cout<<endl;
//		cout<<xx<<' '<<yy1<<' '<<zz<<endl;
//		cout<<xx<<' '<<yy2<<' '<<zz<<endl;
		cout<<ans<<endl;
	}
//	for(int i=0;i<n;i++){
//		cout<<i<<endl;
//		cout<<x[i]<<' '<<y1[i]<<' '<<z[i]<<endl;
//		cout<<x[i]<<' '<<y2[i]<<' '<<z[i]<<endl;
//		cout<<endl;
//	}
	return 0; 
}
