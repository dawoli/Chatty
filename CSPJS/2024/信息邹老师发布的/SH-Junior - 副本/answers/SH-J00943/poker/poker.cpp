#include<bits/stdc++.h>
using namespace std;
int n;
char a[5]={'D','C','H','S'};
char b[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char v[4][13];
char p[100],q[100];
int ans=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i]>>q[i];
		for(int l=0;l<4;l++){
			for(int j=0;j<13;j++){
				if(p[i]==a[l]&&q[i]==b[j]){
					v[l][j]=1;
				}
			}
		}
		
	}
	if(n==1){
		cout<<"51";
	}
	else{
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				if(v[i][j]==0){
					ans++;
				}
			}
		}
		if(ans==0){
			cout<<"0";
		}
		else
			cout<<ans<<endl;
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
