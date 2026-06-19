#include<bits/stdc++.h>

using namespace std;
const int N = 100030;
int num;
int ans; 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>num;
	for(int i=1;i<=num;i++){
		int  n=0,m=0,len=0,su=0,ans=0;
		int st[N],sp[N],jia[N],pwei[N];
		cin>>n>>m>>len>>su;
		for(int j=0;j<n;j++){
			cin>>st[j]>>sp[j]>>jia[j];
		}
		for(int k=0;k<m;k++){
			cin>>pwei[k];
		}
		sort(pwei,pwei+m);
		for(int j=0;j<n;j++){
			if(st[j]<=pwei[m-1]){
				if(sp[j]>su){
					ans++;
				}
			}
		}
		cout<<ans;
		cout<<" ";
		cout<<m-1;
		cout<<"\n";
	}
	cout<<endl;
	return 0;
}
