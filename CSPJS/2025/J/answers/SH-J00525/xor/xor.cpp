#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int last_end=-1;
	for(int i=0;i<n;i++){
		int b=0;
		for(int j=i;j<n;j++){
			b^=a[j];
			if(b==k&&i>last_end){
				cnt++;
				last_end=j;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;//bushi第三题怎么比第四题还难骗分 ,已经是极限了哈，下一题见 
}
