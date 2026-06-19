#include <bits/stdc++.h>
using namespace std;

int n;
int a[5][20],ans;
string s;
int search(char c){
	if (c=='A')  return 1;
	if (c>='2' && c<='9')  return c-48;
	if (c=='T')  return 10;
	if (c=='J')  return 11;
	if (c=='Q')  return 12;
	if (c=='K')  return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s[0]=='D')  a[0][search(s[1])]=1;
		if (s[0]=='C')  a[1][search(s[1])]=1;
		if (s[0]=='H')  a[2][search(s[1])]=1;
		if (s[0]=='S')  a[3][search(s[1])]=1;
	}
	for (int i=0;i<4;i++){
		for (int j=1;j<=13;j++){
			if (!a[i][j])  ans++;
			//cout<<ans<<" ";
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
} 
