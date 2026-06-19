#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>> T;
	while(T){
		T--;
		int  n;
		int a[105];
		cin >> n;
		for(int i= 1;i<=n;i++) cin >> a[i];
		int ans = 0;
		for(int k = 0;k<=(1<<(n+1))-1;k++){//0-blue,1-red; 
			int num[105] ;
			memset(num,0,sizeof(num));
			int count = 1;
			int temp = k;
			while(temp){
				if((temp&1 )== 1) num[count] = 1;
				count++;
				temp = (temp>>1);
			}
			int sum = 0;
			for(int i = 1;i<=n;i++){
				for(int j = i-1;j>=0;j--){
					if(num[i] == num[j]){
						if(a[i] == a[j]) sum += a[i];
						break;
					}
				}
			}
			ans = max(ans,sum);
		}
		cout << ans<<endl; 
	}
	
	
	return 0;
}
