#include<bits/stdc++.h>
using namespace std;
int n,q,cnt,b1,b2;
string s[200009][2],t[2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<q;i++){
		cin>>t[0]>>t[1];
		for(int j=0;j<t[0].size();j++){
			if(t[0][j]=='b')b1=j;
			if(t[1][j]=='b')b2=j;
		}
		int b3,b4;
		for(int j=0;j<n;j++){
			for(int k=0;k<s[j][0].size();k++){
				if(s[i][0][k]=='b')b3=k;
				if(s[i][1][k]=='b')b4=k;
			}
			if(s[j][0].size()>abs(b2-b1)){
				if(b3<b1&&b4<b2)
					cnt++;
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
		
	
	return 0;
} 
