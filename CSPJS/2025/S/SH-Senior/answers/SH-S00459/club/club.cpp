#include<bits/stdc++.h>
using namespace std;
int T, R, N;


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (R = 0; R < T; R ++){
		cin >> N;
		int satisfy[70009][3];
		int sSort[70009][4];
		int clubCnt[3];
		memset(clubCnt, 0, sizeof(clubCnt));
		for(int i = 0; i < N; i ++){
			cin >> satisfy[i][0] >> satisfy[i][1] >> satisfy[i][2];
			if (satisfy[i][0] >= satisfy[i][1] && satisfy[i][1] >= satisfy[i][2]){
				sSort[i][0] = 0;
				sSort[i][1] = 1;
				sSort[i][2] = 2;
			}
			else if (satisfy[i][0] >= satisfy[i][2] && satisfy[i][2] >= satisfy[i][1]){
				sSort[i][0] = 0;
				sSort[i][1] = 2;
				sSort[i][2] = 1;
			}
			else if (satisfy[i][1] >= satisfy[i][0] && satisfy[i][0] >= satisfy[i][2]){
				sSort[i][0] = 1;
				sSort[i][1] = 0;
				sSort[i][2] = 2;
			}
			else if (satisfy[i][1] >= satisfy[i][2] && satisfy[i][2] >= satisfy[i][0]){
				sSort[i][0] = 1;
				sSort[i][1] = 2;
				sSort[i][2] = 0;
			}
			else if (satisfy[i][2] >= satisfy[i][0] && satisfy[i][0] >= satisfy[i][1]){
				sSort[i][0] = 2;
				sSort[i][1] = 0;
				sSort[i][2] = 1;
			}
			else if (satisfy[i][2] >= satisfy[i][1] && satisfy[i][1] >= satisfy[i][0]){
				sSort[i][0] = 2;
				sSort[i][1] = 1;
				sSort[i][2] = 0;
			}
			sSort[i][3] = sSort[i][0];
			clubCnt[sSort[i][3]] ++;
		}
		for (int r = 0; r < 3; r++){
			while (clubCnt[r] > N/2){
				int minLose = 9999999, minLoseMem, mimLoseMemClub;
				for(int i = 0; i < N; i ++){
					if (sSort[i][3] != r) continue;
					int kickLose = satisfy[i][sSort[i][0]] - satisfy[i][sSort[i][1]];
					if (sSort[i][0] == r && kickLose < minLose && clubCnt[sSort[i][1]] < N/2){
						minLose = kickLose;
						minLoseMem = i;
						mimLoseMemClub = 0;
					}
					if (sSort[i][0] == r && kickLose == minLose && mimLoseMemClub == 1 && clubCnt[sSort[i][1]] < N/2){
						if (satisfy[minLoseMem][sSort[minLoseMem][2]] < satisfy[i][sSort[i][2]]){
							minLoseMem = i;
							mimLoseMemClub = 0;
						}
					}
					kickLose = satisfy[i][sSort[i][1]] - satisfy[i][sSort[i][2]];
					if (sSort[i][1] == r && (kickLose < minLose || (mimLoseMemClub == 0 && kickLose == minLose)) && clubCnt[sSort[i][2]] < N/2){
						minLose = kickLose;
						minLoseMem = i;
						mimLoseMemClub = 1;
					}
				}
				sSort[minLoseMem][3] = sSort[minLoseMem][mimLoseMemClub + 1];
				clubCnt[r] --;
				clubCnt[sSort[minLoseMem][mimLoseMemClub + 1]] ++;
			}
			
		}
		int satSum = 0;
		for(int i = 0; i < N; i ++){
			satSum += satisfy[i][sSort[i][3]];
		}
		cout << satSum << endl;
	}
	return 0;
}

