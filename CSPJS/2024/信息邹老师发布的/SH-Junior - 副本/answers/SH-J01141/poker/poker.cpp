#include<bits/stdc++.h>
using namespace std;
int n , ans;
char card[5][14];
int main(){
	scanf("%d" , &n);
	for(int i = 1; i <= n ; i ++){
		char a[3];
		scanf("%s" , a);
		if(a[0] == 'D'){
			if(a[1] == 'A'){
				card[1][1] = 1;
			}
			if(a[1] == '2'){
				card[1][2] = 1;
			}
			if(a[1] == '3'){
				card[1][3] = 1;
			}
			if(a[1] == '4'){
				card[1][4] = 1;
			}
			if(a[1] == '5'){
				card[1][5] = 1;
			}
			if(a[1] == '6'){
				card[1][6] = 1;
			}
			if(a[1] == '7'){
				card[1][7] = 1;
			}
			if(a[1] == '8'){
				card[1][8] = 1;
			}
			if(a[1] == '9'){
				card[1][9] = 1;
			}
			if(a[1] == 'T'){
				card[1][10] = 1;
			}
			if(a[1] == 'J'){
				card[1][11] = 1;
			}
			if(a[1] == 'Q'){
				card[1][12] = 1;
			}
			if(a[1] == 'K'){
				card[1][13] = 1;
			}
		}else if(a[0] == 'C'){
			if(a[1] == 'A'){
				card[2][1] = 1;
			}
			if(a[1] == '2'){
				card[2][2] = 1;
			}
			if(a[1] == '3'){
				card[2][3] = 1;
			}
			if(a[1] == '4'){
				card[2][4] = 1;
			}
			if(a[1] == '5'){
				card[2][5] = 1;
			}
			if(a[1] == '6'){
				card[2][6] = 1;
			}
			if(a[1] == '7'){
				card[2][7] = 1;
			}
			if(a[1] == '8'){
				card[2][8] = 1;
			}
			if(a[1] == '9'){
				card[2][9] = 1;
			}
			if(a[1] == 'T'){
				card[2][10] = 1;
			}
			if(a[1] == 'J'){
				card[2][11] = 1;
			}
			if(a[1] == 'Q'){
				card[2][12] = 1;
			}
			if(a[1] == 'K'){
				card[2][13] = 1;
			}
		}
		if(a[0] == 'S'){
			if(a[1] == 'A'){
				card[3][1] = 1;
			}
			if(a[1] == '2'){
				card[3][2] = 1;
			}
			if(a[1] == '3'){
				card[3][3] = 1;
			}
			if(a[1] == '4'){
				card[3][4] = 1;
			}
			if(a[1] == '5'){
				card[3][5] = 1;
			}
			if(a[1] == '6'){
				card[3][6] = 1;
			}
			if(a[1] == '7'){
				card[3][7] = 1;
			}
			if(a[1] == '8'){
				card[3][8] = 1;
			}
			if(a[1] == '9'){
				card[3][9] = 1;
			}
			if(a[1] == 'T'){
				card[3][10] = 1;
			}
			if(a[1] == 'J'){
				card[3][11] = 1;
			}
			if(a[1] == 'Q'){
				card[3][12] = 1;
			}
			if(a[1] == 'K'){
				card[3][13] = 1;
			}
		}
		if(a[0] == 'H'){
			if(a[1] == 'A'){
				card[4][1] = 1;
			}
			if(a[1] == '2'){
				card[4][2] = 1;
			}
			if(a[1] == '3'){
				card[4][3] = 1;
			}
			if(a[1] == '4'){
				card[4][4] = 1;
			}
			if(a[1] == '5'){
				card[4][5] = 1;
			}
			if(a[1] == '6'){
				card[4][6] = 1;
			}
			if(a[1] == '7'){
				card[4][7] = 1;
			}
			if(a[1] == '8'){
				card[4][8] = 1;
			}
			if(a[1] == '9'){
				card[4][9] = 1;
			}
			if(a[1] == 'T'){
				card[4][10] = 1;
			}
			if(a[1] == 'J'){
				card[4][11] = 1;
			}
			if(a[1] == 'Q'){
				card[4][12] = 1;
			}
			if(a[1] == 'K'){
				card[4][13] = 1;
			}
		}
	}
	for(int i = 1 ; i <= 4 ; i ++){
		for(int j = 1 ; j <= 13 ; j ++){
			if(card[i][j] == 0){
				ans ++;
			}
		}
	}
	printf("%d" , ans);
	return 0;
} 
/*
52
DA
CA
HA
SA
D2
C2
H2
S2
D3
C3
H3
S3
D4
C4
H4
S4
D5
C5
H5
S5
D6
C6
H6
S6
D7
C7
H7
S7
D8
C8
H8
S8
D9
C9
H9
S9
DT
CT
HT
ST
DJ
CJ
HJ
SJ
DQ
CQ
HQ
SQ
DK
CK
HK
SK

*/
