#include<bits/stdc++.h>
using namespace std;
const int maxN=100000+1;
int r[maxN]={};
bool flag[maxN]={};
int n=0;
int main(){
	//freopen("duel.in","r",stdin);
	//freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>r[i];
	}
	memset(flag,maxN,0);
	int min=INT_MAX;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j || r[i]==-1 || r[j]==-1 || flag[i]){
				continue;
			}
			flag[i]=1;
			//cout<<i+1<<'>'<<j+1<<endl;
			if (r[i]>r[j]){
				r[j]=-1;
				flag[j]=1;
			}
			int sum=0;
			for (int k=0;k<n;k++){
				sum+=flag[k];
			}
			if (sum==n){
				sum=0;
				for (int k=0;k<n;k++){
					sum+=(r[k]==-1)?0:1;
				}
				if (sum<min){
					min=sum;
				}
			}
		}
	}
	cout<<min<<endl;
	return 0;
}
