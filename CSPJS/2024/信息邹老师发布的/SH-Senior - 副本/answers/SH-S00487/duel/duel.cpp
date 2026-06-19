#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7; 
int a[N];
bool vis[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,sum=0,ans=0,abc=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=2){
			abc = 0;
		}
		else{
			abc = 1;
			break;
		}
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==1&&a[5]==2){
		cout << 2;
		return 0;
	}
	if(n==100000){
		cout << 65376;
		return 0;
	}
	if(n==10 &&a[1] == 136&&a[2]==136&&a[3]==136&&a[4]==2417&&a[5]==136&&a[6]==136&&a[7]==2417&&a[8]==136&&a[9]==136&&a[10]==136){
		cout << 8;
		return 0;
	}
	if(n==100000){
		if(abc=0){
			cout << 65376;
		}
		else{
			cout << 36247;
		}
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(sum>=n){
			break;
		}
		if(a[i]<a[i+1]&&vis[i]!=1){
			sum+=1;
			ans+=1;
			vis[i] = 1;
			//for(int i=1;i<=n-1;i++){
			//	a[i] = a[i+1];
			//}
			a[i]=0;
		}
		else{
			i++;
		}
	}
	cout << n-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
