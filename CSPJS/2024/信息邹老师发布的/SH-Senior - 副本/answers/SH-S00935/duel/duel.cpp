#include<bits/stdc++.h>
using namespace std;
int q,w[100005],las=-1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>w[100004];
		w[w[100004]]++;
	}
	for(int i=0;i<100004;i++){
		if(w[i]!=0) {
			if(las>0){
				if(w[i]>w[las]){
					//cout<<"KO "<<las<<'*'<<w[las]<<endl;//战地记者?
					ans+=w[las];
					//w[i]-=w[las];
					w[las]=0;
					las=w[i];
				}
				else if(w[i]<w[las]){
					//cout<<"KO "<<las<<'*'<<w[i]<<endl;
					ans+=w[i];
					w[las]-=w[i];
					//w[i]=0;
				}
				else{
					//cout<<"KO "<<las<<'*'<<w[las]<<endl;
					ans+=w[i];
					//w[i]=0;
					w[las]=0;
					las=i;
				}
			}
			else las=i;
		}
	}
	cout<<q-ans;
	return 0;
}
