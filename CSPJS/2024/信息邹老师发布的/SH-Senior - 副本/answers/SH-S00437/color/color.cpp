#include<bits/stdc++.h>
using namespace std;
int a[100002];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		long long a1=0,a2=0;
		int n;
		cin>>n;
		while(n--){
			int p;
			cin>>p;
			a[p]++;
		}for(int i=1;i<=1000000;i++){
			long long o=(a[i]-1)*i;
			if(o>=a1){
				a2=a1;
				a1=o;
			}else if(o>a2) a2=o;
		}cout<<a1+a2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
