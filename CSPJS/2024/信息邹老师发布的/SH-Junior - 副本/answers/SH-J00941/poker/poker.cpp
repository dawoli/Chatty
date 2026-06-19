#include <bits/stdc++.h>
using namespace std;
string p[100];
int flag[100]={0};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
		int Plus=0,sm=0;
		if(p[i][0]=='S')Plus=13;
		if(p[i][0]=='H')Plus=26;
		if(p[i][0]=='D')Plus=39;
		if(p[i][1]=='A')sm=0;
		else if(p[i][1]=='T')sm=9;
		else if(p[i][1]=='J')sm=10;
		else if(p[i][1]=='Q')sm=11;
		else if(p[i][1]=='K')sm=12;
		else sm=(p[i][1]-'0')-1;
		flag[Plus+sm]=1;
	}
	int nd=0;
	for(int i=0;i<52;i++){
		if(flag[i]==0){
			nd++;
		}
	}
	cout<<nd;
	return 0;
}
