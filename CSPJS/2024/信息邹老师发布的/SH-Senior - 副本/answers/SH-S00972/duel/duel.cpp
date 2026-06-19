 #include<iostream>
 #include<algorithm>
 #include<cstdio>
 using namespace std;
 
 int n,a[100009],ans,b[100009][2];
 
 int main(){
 	freopen("duel.in","r",stdin);
 	freopen("duel.out","w",stdout);
 	cin >> n;
 	for(int i = 0; i < n; i++){
 		cin >> a[i];
	}
	sort(a,a+n);
	b[0][0]=a[0];
	int m = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != b[m][0]){
			b[++m][0]=a[i];
			b[m][1]++;
		}else{
		b[m][1]++;
		}
	}
	m++;
	for(int i = 0; i < m; i++){
		if(b[i][1] > ans){
			ans=b[i][1];
		}
	}
	cout  << ans;
	return 0;
 }
