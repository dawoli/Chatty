#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(int a,int b){
	return a>b;
}
int n,m,a[105];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" "<<i<<" ";
//	}
	int cnt=0,c=0,r=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt++;
				//cout<<cnt<<" "<<a[cnt]<<endl;
			    if(a[cnt]==num){
				    c=j;
				    r=i;
				    cout<<c<<" "<<r;
				    return 0;
			    }
			    
			    //cout<<i<<" "<<j<<endl;
		    }
		}else{
			for(int i=n;i>=1;i--){
				cnt++;
				//cout<<cnt<<" "<<a[cnt]<<endl;
				if(a[cnt]==num){
				    c=j;
				    r=i;
				    cout<<c<<" "<<r;
				    return 0;
			    }
			    //cout<<i<<" "<<j<<endl;
			}
		}
		
		
		
	}

	
//	fclose(stdin);
//	fclose(stdout);
	
	return 0;
}
