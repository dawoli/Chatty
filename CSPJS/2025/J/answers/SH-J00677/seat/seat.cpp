#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	int num=a[1],id;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
	    if(a[i]==num){
	    	id=i;
	    	break;
		}
	}
	int lie=(id-1)/n+1;
	if(lie%2==1)
	    cout<<lie<<" "<<id-n*(lie-1);
	else
	    cout<<lie<<" "<<n*lie-id+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
