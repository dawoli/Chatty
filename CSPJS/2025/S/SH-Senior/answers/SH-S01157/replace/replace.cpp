#include<bits/stdc++.h>
using namespace std;
string t1[200009],t2[200009],s1[200009],s2[200009];
int d[200009],f[200009],abc[35];
int w1[200009][100],w2[200009][100],w3[200009][100],w4[200009][100];
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	srand(time(0));
	for(int i=1;i<=30;i++)abc[i]=rand();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		t1[i]=' '+t1[i];
		t2[i]=' '+t2[i];
		for(int j=1;j<=t1[i].size()-1;j++){
			if(t1[i][j]!=t2[i][j]){
				f[i]=j;
				break;
			}
		}
		for(int j=1;j<=t1[i].size()-1;j++){
			w1[i][j]=w1[i][j-1]+abc[t1[i][j]-'a'+1];
		}
		for(int j=1;j<=t1[i].size()-1;j++){
			w2[i][j]=w2[i][j-1]+abc[t2[i][j]-'a'+1];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
		for(int j=1;j<=s1[i].size()-1;j++){
			if(s1[i][j]!=s2[i][j]){
				d[i]=j;
				break;
			}
		}
		for(int j=1;j<=s1[i].size()-1;j++){
			w3[i][j]=w3[i][j-1]+abc[s1[i][j]-'a'+1];
		}
		for(int j=1;j<=s1[i].size()-1;j++){
			w4[i][j]=w4[i][j-1]+abc[s2[i][j]-'a'+1];
		}
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			int X=f[i]-d[j]+1,Y=f[i]+s1[j].size()-d[j]-1;
			if(X<=0)continue;
			if(t1[i].size()-1<Y)continue;
			if(w1[i][Y]-w1[i][X]==w3[j][s1[j].size()-1]-w3[j][1]&&w2[i][Y]-w2[i][X]==w4[j][s1[j].size()-1]-w4[j][1])cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
