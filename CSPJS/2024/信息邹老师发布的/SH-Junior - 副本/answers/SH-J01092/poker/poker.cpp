#include<bits/stdc++.h>
using namespace std;
int l[52]={};
int ctoi(string a){
	int ans=0;
//	cout<<" SDJF"<<" ";
	if(a[0]=='D') ans=0;
	else if(a[0]=='C') ans=13;
	else if(a[0]=='H') ans=26;
	else if(a[0]=='S') ans=39;
//	cout<<ans<<" ";
	if(a[1]=='T') ans+=10;
	else if(a[1]=='K') ans+=13;
	else if(a[1]=='Q') ans+=12;
	else if(a[1]=='J') ans+=11;
	else if(a[1]=='A') ans+=1;
	else ans+=int(a[1]-48);
//	cout<<ans-1;
	return ans-1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		l[ctoi(s)]++;
	}
	int ans=0;
	for(int i=0;i<52;i++){
		if(l[i]==0){
			ans++;
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
