#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int flag=a[1];//记录小R的成绩 
	sort(a+1,a+n*m+1,cmp);//从大到小排序 
//	for(int i=1;i<=n*m;i++) cout << a[i] << " ";
//	cout <<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			flag=i;
			break;//记录名次 
		}
	}
//	cout << flag <<endl;
	int lie,hang,k=flag%n;
	if(k==0) k=n;//k表示他在第lie列中排名第k，如果正好整除，那么k排名最后
	 
	if(flag%n==0) lie=flag/n;//如果名次flag能整除行数，那么他就在flag/n这一列，最后一行 
	else lie=flag/n+1;//其余的，他在下一列 
	
	if(lie%2==0) hang=n-k+1;//如果他在偶数列，那么名次按从小到大排 
	else hang=k;//他在奇数列，名次按从大到小排 
	cout << lie << " " << hang;
	return 0; 
}
