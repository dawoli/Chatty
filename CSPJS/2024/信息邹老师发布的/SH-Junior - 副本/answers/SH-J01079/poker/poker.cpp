#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
bool po[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		int ansn=ans;
		if(s[0]=='S')  {
			if(s[1]=='A' && po[1][1]==0) ans--,po[1][1]=1;
			else if(s[1]=='T' && po[1][10]==0) ans--,po[1][10]=1;
			else if(s[1]=='J' && po[1][11]==0) ans--,po[1][11]=1;
			else if(s[1]=='Q' && po[1][12]==0) ans--,po[1][12]=1;
			else if(s[1]=='K' && po[1][13]==0) ans--,po[1][13]=1;
			else if(po[1][s[1]-'0']==0  && s[1]<='9' && s[1]>='2') ans--,po[1][s[1]-'0']=1;
			}
		if(s[0]=='H')  {
			if(s[1]=='A' && po[2][1]==0) ans--,po[2][1]=1;
			else if(s[1]=='T' && po[2][10]==0) ans--,po[2][10]=1;
			else if(s[1]=='J' && po[2][11]==0) ans--,po[2][11]=1;
			else if(s[1]=='Q' && po[2][12]==0) ans--,po[2][12]=1;
			else if(s[1]=='K' && po[2][13]==0) ans--,po[2][13]=1;
			else if(po[2][s[1]-'0']==0  && s[1]<='9' && s[1]>='2') ans--,po[2][s[1]-'0']=1; 
		}
		if(s[0]=='C')  {
			if(s[1]=='A' && po[3][1]==0) ans--,po[3][1]=1;
			else if(s[1]=='T' && po[3][10]==0) ans--,po[3][10]=1;
			else if(s[1]=='J' && po[3][11]==0) ans--,po[3][11]=1;
			else if(s[1]=='Q' && po[3][12]==0) ans--,po[3][12]=1;
			else if(s[1]=='K' && po[3][13]==0) ans--,po[3][13]=1;
			else if(po[3][s[1]-'0']==0 && s[1]<='9' && s[1]>='2') ans--,po[3][s[1]-'0']=1;
		}
		if(s[0]=='D')  {
			//cout<<3<<" ";
			if(s[1]=='A' && po[4][1]==0) ans--,po[4][1]=1;
			else if(s[1]=='T' && po[4][10]==0) ans--,po[4][10]=1;
			else if(s[1]=='J' && po[4][11]==0) ans--,po[4][11]=1;
			else if(s[1]=='Q' && po[4][12]==0) ans--,po[4][12]=1;
			else if(s[1]=='K' && po[4][13]==0) ans--,po[4][13]=1;
			else if(po[4][s[1]-'0']==0 && s[1]<='9' && s[1]>='2') ans--,po[4][s[1]-'0']=1;
		}
		
		//cout<<po[2][3];	
	}
	printf("%d",ans);
}
