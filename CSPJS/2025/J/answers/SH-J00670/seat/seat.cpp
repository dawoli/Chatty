# include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,stu,cnt;
	cin >> n >> m;
	int b[101];
	for(int i = 1;i <= n * m;i++){
		cin >> b[i];
		if(i == 1){
			stu = b[i];
		}
	}
	for(int i = 1;i <= m * n;i++){
		for(int j = i + 1;j <= m * n;j++){
			if(b[i] <= b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i = 1;i <= n * m;i++){
		if(stu == b[i]){
			cnt = i;
			break;
		}
	}
	int c = 0,r = 0;
	if(cnt % n != 0){
		c++;
	}
	c += cnt / n;
	if(c % 2 == 1){ //odds 
		while(cnt - n > 0){
			cnt -= n;
		}
		r = cnt;
		cout << c << " " << r; 
		return 0;
	}
	else{    //ÌÖÂÛÅ¼ÊıÁĞ
		while(cnt - n > 0){
			cnt -= n;
		}
		r = n - cnt + 1;
		cout << c << " " << r; 
		return 0;
	}
}
