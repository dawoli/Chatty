#include <bits/stdc++.h>
using namespace std;
int n,ans,f[55];
string p[55];
string a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<52;i++){
		if(i<13){
			a[i]=="D";
			if(i%13==0) a[i]+="A";
			else if(i%13==9) a[i]+="T";
			else if(i%13==10) a[i]+="J";
			else if(i%13==11) a[i]+="Q";
			else if(i%13==12) a[i]+="K";
			else a[i]+=i+1;
		}else if(i<26){
			a[i]=="C";
			if(i%13==0) a[i]+="A";
			else if(i%13==9) a[i]+="T";
			else if(i%13==10) a[i]+="J";
			else if(i%13==11) a[i]+="Q";
			else if(i%13==12) a[i]+="K";
			else a[i]+=i+1;
		}else if(i<39){
			a[i]=="H";
			if(i%13==0) a[i]+="A";
			else if(i%13==9) a[i]+="T";
			else if(i%13==10) a[i]+="J";
			else if(i%13==11) a[i]+="Q";
			else if(i%13==12) a[i]+="K";
			else a[i]+=i+1;
		}else{
			a[i]=="S";
			if(i%13==0) a[i]+="A";
			else if(i%13==9) a[i]+="T";
			else if(i%13==10) a[i]+="J";
			else if(i%13==11) a[i]+="Q";
			else if(i%13==12) a[i]+="K";
			else a[i]+=i+1;
		}	
	}
	for(int i=0;i<52;i++){
		f[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<52;j++){
			if(p[i]==a[j]&&f[j]==1){
				f[j]=0;
			}
			else if(p[i]==a[j]&&f[j]==0) ans++;
		}
	}
	cout<<52-n+ans;
	return 0;
}
