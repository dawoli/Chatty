#include<bits/stdc++.h> 
using namespace std;
bool gong[100005],si[100005];
int guai[100005];
int u;
void bi(int j,int x){
	if(guai[j]>guai[x] && si[j]==false && gong[j]==false && si[x]==false){
		u--;
		gong[j]=true;
		si[x]=true;
	}
	else if(guai[j]<guai[x] && si[j]==false && gong[x]==false && si[x]==false){
		u--;
		gong[x]=true;
		si[j]=true;
	}
}
int main(){
	//freopen("duel.in","r",stdin);
	//freopen("duel.out","w",stdin);
	int n;
	int s;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>guai[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(guai[j]>guai[j+1]){
				s=guai[j];
				guai[j]=guai[j+1];
				guai[j+1]=s;
			}
		}
	} 
	s=0;
	u=n;
	cout<<endl;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			for(int x=j-1;x>=1;x--){
				bi(j,x);
			}
			
		}

	}
	cout<<u;
	return 0;
}
