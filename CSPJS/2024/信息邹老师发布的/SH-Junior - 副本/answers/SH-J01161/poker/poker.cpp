#include<bits/stdc++.h>
using namespace std;
int n,a[60],ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		char s1,s2;
		cin>>s1>>s2;
		if(s1=='S'){
			if(s2>'1'&&s2<='9') a[s2-'0']=1;
			if(s2=='A') a[1]=1;
			if(s2=='K') a[13]=1;				
			if(s2=='Q') a[12]=1;				
			if(s2=='J') a[11]=1;				
			if(s2=='T') a[10]=1;	
		}if(s1=='H'){
			if(s2>'1'&&s2<='9') a[s2-'0']=1;
			if(s2=='A') a[1]=1;
			if(s2=='K') a[13]=1;				
			if(s2=='Q') a[12]=1;				
			if(s2=='J') a[11]=1;				
			if(s2=='T') a[10]=1;	
		}if(s1=='D'){
			if(s2>'1'&&s2<='9') a[s2-'0']=1;
			if(s2=='A') a[1]=1;
			if(s2=='K') a[13]=1;				
			if(s2=='Q') a[12]=1;				
			if(s2=='J') a[11]=1;				
			if(s2=='T') a[10]=1;	
		}if(s1=='C'){
			if(s2>'1'&&s2<='9') a[s2-'0']=1;
			if(s2=='A') a[1]=1;
			if(s2=='K') a[13]=1;				
			if(s2=='Q') a[12]=1;				
			if(s2=='J') a[11]=1;				
			if(s2=='T') a[10]=1;	
		}
	}
	for(int i=1;i<=52;i++){
		if(a[i]){
			ans++;
		}
	}
	cout<<52-ans;
	return 0;
}
