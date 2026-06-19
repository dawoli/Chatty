#include<bits/stdc++.h>
using namespace std;
struct poker{
	char hs,ds;
} puke[52];
bool cmp(poker a,poker b){
	if(a.hs!=b.hs) return a.hs<b.hs;
	return a.ds<b.ds; 
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		puke[i].hs=s[0],puke[i].ds=s[1];
	}
	int ans=n;
	sort(puke,puke+n,cmp);
	for(int i=0;i<n;i++){
		if(puke[i].hs==puke[i+1].hs&&puke[i].ds==puke[i+1].ds) ans--;
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
