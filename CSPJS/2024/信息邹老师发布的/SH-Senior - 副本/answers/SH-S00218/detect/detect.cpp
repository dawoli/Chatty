#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d,v,a,p[10010],s[10010],ans;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>l>>V;
		for(int j=0;j<n;j++){
			cin>>d>>v>>a;
			if(a==0){
			    if(v>V) ans++;
		    }
		    else {
			    s[j]=(V*V-v*v)/(2*a)+d;
			} 
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
			if(s[j]==p[k]){
				ans++;
			    }
	        }
		}
		int al=ans;
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
			if(s[j]==s[k]){
				al--;
			    }
	        }
		}
		
		cout<<ans<<" "<<al;
	}
}
