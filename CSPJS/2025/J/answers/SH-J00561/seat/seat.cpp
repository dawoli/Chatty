#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[12][12];
int score[101];
int scores[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)cin >> score[i];
	int aim = score[1];
	sort(score+1,score+n*m+1);
	for (int i=1;i<=n*m;i++){
		scores[i] = score[n*m-i+1];
	}
	int f_n_index = 1;
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				a[j][i] = scores[f_n_index];
				f_n_index += 1;
			}
		}else{
			for (int j=n;j>=1;j--){
				a[j][i] = scores[f_n_index];
				f_n_index += 1;
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++)cout << a[i][j]<<' ';
//		cout << endl;
//	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]==aim){
				cout << j << ' '<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
