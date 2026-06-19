#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a,int b){
	return a>b;
}

long long mymap[1005][1005],s[1005];
long long n,m,f,k=1,ans1,ans2;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	f=s[1];
	sort(s,s+n*m+1,cmp);
	for(int i=1;i<=m/2+1;i++){
		for(int j=1;j<=n;j++){
			mymap[2*i-1][j]=s[k];
			if(mymap[2*i-1][j]==f){
				ans1=2*i-1;
				ans2=j;
				break;
			}
			k++;
		}
		for(int j=n;j>=1;j--){
			mymap[i*2][j]=s[k];
			if(mymap[2*i][j]==f){
				ans1=2*i;
				ans2=j;
				break;
			}
			k++;
		}
	}
	cout<<ans1/2<<" "<<ans2/2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
