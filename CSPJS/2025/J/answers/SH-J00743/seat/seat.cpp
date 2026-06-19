#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int l=n*m;
	for(int i=1;i<=l;i++) cin >> a[i];
	int s=a[1];
	sort(a+1,a+l+1,cmp);
	int r=1,c=1;
	for(int i=1;i<=l;i++){
		if(a[i]==s){
			cout << c << ' ' << r << endl;
			break;
		}
		if(c%2) r++;
		else r--; 
		if(r==n+1||r==0){
			c++;
			if(c%2)r=1; 
			else r=n; 
		} 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
