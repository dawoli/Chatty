#include<iostream>
using namespace std;
int pk[1002][1002];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	string p;
	while(n--){
		cin>>p;
		if(pk[p[0]][p[1]]==0){
			pk[p[0]][p[1]]=1;
			ans-=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

