#include <bits/stdc++.h>
using namespace std;
char a[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b[]={'D','C','H','S'};
bool state[256][256];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	string x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		//cout<<x[0]<<x[1]<<endl;
		state[x[0]][x[1]]=1;
	}
	for(int i=0;i<sizeof(a);i++)
		for(int j=0;j<sizeof(b);j++){
			//cout<<a[i]<<b[j]<<endl;
			if(!state[b[j]][a[i]])ans++;
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
