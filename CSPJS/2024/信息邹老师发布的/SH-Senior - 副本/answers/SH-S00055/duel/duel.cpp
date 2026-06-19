#include<bits/stdc++.h>
using namespace std;
int n,ans=0,r[100009];
bool tired[100009];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)tired[i]=false;
    for(int i=0;i<n;i++)cin>>r[i];
    if(*max_element(r,r+n)<=2){
    	for(int i=0;i<n;i++)if(r[i]==2)ans++;
    	cout<<ans;
	}
    else{
		sort(r,r+n);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(r[i]<r[j]&&tired[j]==false){
					tired[j]=true;
					ans++;
					break;
				}
			}
		}
		cout<<n-ans;    	
	}
    return 0;
}
