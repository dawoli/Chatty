#include<bits/stdc++.h>

using namespace std;
int n;
int a[5010],q[5010];

bool cmp(int a,int b){
	return a>b;
}
 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//system("fc number4.txt number4ans.txt");
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	q[0]=0;
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	int l,ans=0;
	for(int r=3;r<=n;r++){
		l=0;
		while(l<=r-2){
			l++;
			if(q[r]-q[l]<=a[l]*2)break;
			ans++;
		}
	}
	cout<<ans;
	 
	return 0;
} //#Shang4Shan3Ruo6Shui4
