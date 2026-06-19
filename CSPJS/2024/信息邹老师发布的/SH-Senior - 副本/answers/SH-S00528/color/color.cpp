#include<bits/stdc++.h>
using namespace std;
int t,n,w[200009],ans=-109,nex[200009],ji[1000009];
int red[19],blue[19],sr,sd;
void solveDFS(int nk){
	if(nk==n){
		int f=0;
		for(int i=0;i<sr-1;i++){
			if(red[i]==red[i+1]){
				f+=red[i];
			}
		}
		for(int i=0;i<sd-1;i++){
			if(blue[i]==blue[i+1]){
				f+=blue[i];
			}
		}
		ans=max(ans,f);
		return;
	}
	red[sr]=w[nk];
	sr++;
	solveDFS(nk+1);
	sr--;
	blue[sd]=w[nk];
	sd++;
	solveDFS(nk+1);
	sd--;
	return;
}
/*void solverd(){
	for(int be=0;be<n;be++){
		int sum,k=be;
		while(nex[k]!=0){
			k=nex[k];
			sum+=w[k];
			if(nex[k-1]!=k)
				k--;
			else{
				k++;
			}
		}
		ans=max(sum,ans);
	}
}*/
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int ak=0;ak<t;ak++){
		//int nex[200009],ji[1000009];
		//for(int i=0;i<10009;i++){
		//	ji[i]=-1;
		//}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>w[i];
		}
		if(n<=15){
			ans=-109;
			solveDFS(0);
			cout<<max(ans,0)<<endl;
		}
		/*else if(n<=2000){
			for(int i=0;i<n;i++){
				if(ji[w[i]]>=0){
					nex[ji[w[i]]]=i;
					cout<<nex[ji[w[i]]];
				}
			ji[w[i]]=i;
		}
			ans=-109;
			solverd();
			cout<<max(ans,0)<<endl;
		}*/
	}
	return 0;
}
//HF#24THMC
