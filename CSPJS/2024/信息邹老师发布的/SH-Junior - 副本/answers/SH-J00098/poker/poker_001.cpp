#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=52;
bool t[125][125];
char op,c,ops[5]={'D','C','H','S'},cs[15]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>c;
		t[op][c]=true;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			ans-=t[ops[i]][cs[j]];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
