#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y;
}arr[N][10];
bool cmp(node a,node b){
	return a.x>b.x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f=1;
		vector<int>a;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int k;
				cin>>k;
				arr[i][j].x=k;
				arr[i][j].y=j;
				if((j==2||j==3)&&arr[i][j].x!=0)f=0;
				if(j==1)a.push_back(arr[i][j].x);
			}
		}
		if(f==1){
			sort(a.begin(),a.end(),greater<int>());
			int ans=0;
			for(int i=0;i<n/2;i++)ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		int lim=n/2,ans=1;
		int d[3]={1,2,3};
		for(int i=1;i<=n;i++){
			ans+=int(arr[i][d[i]].x);
		}
		cout<<ans<<endl;
	}	
	
	fclose(stdin);
	fclose(stdout);
	exit(0);
}
