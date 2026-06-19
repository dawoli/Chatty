#include<bits/stdc++.h>
using namespace std;
int translater(char tra){
	if(tra=='A'){
		return 1;
	}else if(tra=='T'){
		return 10;
	}else if(tra=='J'){
		return 11;
	}else if(tra=='Q'){
		return 12;
	}else if(tra=='K'){
		return 13;
	}else{
		return int(tra) - 48;
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,a[55]={0};
	scanf("%d\n", &n);
	char col,num;
	for(int i=1;i<=n;i++){
		scanf("%c%c\n", &col, &num);
		if(col=='D'){
			a[translater(num)]=1;
		}else if(col=='C'){
			a[translater(num)+13]=1;
		}else if(col=='H'){
			a[translater(num)+26]=1;
		}else if(col=='S'){
			a[translater(num)+39]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=52;i++){
		if(a[i]==0){
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
