//ÑÐ¾¿Ô± 
#include <bits/stdc++.h>
using namespace std;
int n,q;
string xy[200010][2]={};
int qz[200010]={};
int hz[200010]={};
int cj[200010]={};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<=n;i++){
		cin>>xy[i][0]>>xy[i][1];
		int js=0;
		int ws1,ws2;
		for(int j=0;j<xy[i][0].size();j++){
			if(js==0&&xy[i][0][j]=='a')qz[i]++;
			else if(js==1&&xy[i][0][j]=='a')hz[i]++;
			else if(xy[i][0][j]!='a'){
				js++;
				ws1=j;
			}
			if(xy[i][1][j]=='b'){
				ws2=j;
			}
		}
		cj[i]=ws1-ws2;
	}
	for(int i=0;i<q;i++){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int ws11,ws22;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')ws11=j;
			if(s2[j]=='b')ws22=j;
		}
		for(int j=0;j<n;j++){
			if(ws11-qz[j]>=0&&ws11+hz[j]<s1.size()&&(ws11-ws22)==cj[j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
