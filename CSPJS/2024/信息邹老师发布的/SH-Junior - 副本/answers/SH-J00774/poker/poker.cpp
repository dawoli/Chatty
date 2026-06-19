#include <bits/stdc++.h>
using namespace std;
int ans=0;
string s;
bool a[4][15]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	//cout<<n<<endl;//
	for (int i=1;i<=n;i++){
		cin>>s;
		if (s[0]=='D'){
			if (s[1]>='2'&& s[1]<='9'){
				a[0][s[1]-'0']=1;
			}
			else if (s[1]=='A') a[0][1]=1;
			else if (s[1]=='T') a[0][10]=1;
			else if (s[1]=='J') a[0][11]=1;
			else if (s[1]=='Q') a[0][12]=1;
			else if (s[1]=='K') a[0][13]=1;
		}
		else if (s[0]=='C'){
			if (s[1]>='2'&& s[1]<='9'){
				a[1][s[1]-'0']=1;
			}
			else if (s[1]=='A') a[1][1]=1;
			else if (s[1]=='T') a[1][10]=1;
			else if (s[1]=='J') a[1][11]=1;
			else if (s[1]=='Q') a[1][12]=1;
			else if (s[1]=='K') a[1][13]=1;
		}
		else if (s[0]=='H'){
			if (s[1]-'0'>=2 && s[1]-'0'<=9){
				a[2][s[1]-'0']=1;
			}
			else if (s[1]=='A') a[2][1]=1;
			else if (s[1]=='T') a[2][10]=1;
			else if (s[1]=='J') a[2][11]=1;
			else if (s[1]=='Q') a[2][12]=1;
			else if (s[1]=='K') a[2][13]=1;
		}
		else if (s[0]=='S'){
			if (s[1]>='2'&& s[1]<='9'){
				a[3][s[1]-'0']=1;
			}
			else if (s[1]=='A') a[3][1]=1;
			else if (s[1]=='T') a[3][10]=1;
			else if (s[1]=='J') a[3][11]=1;
			else if (s[1]=='Q') a[3][12]=1;
			else if (s[1]=='K') a[3][13]=1;//cout<<"SK OK!"<<endl;//
		}
	}
	for(int i=0;i<=3;i++){
		for (int j=1;j<=13;j++){
			if (!a[i][j]) ans++;
			//cout<<i<<" "<<j<<" "<<a[i][j]<<endl;//
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
