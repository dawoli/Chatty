#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool v1[10005];
bool v2[10005];
int n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	memset(a,0,sizeof(a));
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]&&v1[i]==0&&v2[j]==0){
				v1[i]=1;
				v2[j]=1;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v2[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
