#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],cnt,vst[1000009];


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=0;
	for(int i=0;i<n+1;i++) vst[i]=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
	//		cout<<a[i]<<endl;
			for(int j=i+1;j<n;j++){
				if(a[j]>a[i]&&vst[j]==0){
					cnt++;
		//			cout<<a[i]<<" "<<a[j]<<endl;
					a[i]=-1;
					vst[j]=1;
					break;
				}
			}
		}
	}
	cout<<n-cnt<<endl;
	
	return 0;
}
