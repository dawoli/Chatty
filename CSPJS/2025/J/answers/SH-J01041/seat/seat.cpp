#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj[105],si[105],sj[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int fs=cj[1],c;
	sort(cj+1,cj+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(fs==cj[i]){
		    c=i;
		    break;
		}
	}
	c=n*m-c+1;
	int cnt=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				si[cnt]=i;
				sj[cnt]=j;
			}
			else{
				si[cnt]=i;
				sj[cnt]=n-j+1;
			}
			cnt++;
		}
	}
	cout<<si[c]<<" "<<sj[c];
    fclose(stdin);
	fclose(stdout);
	return 0;
}
