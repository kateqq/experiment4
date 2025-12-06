#include <stdio.h>
#include <stdlib.h>

void arrangeseats(char seats[][5], int numofseats[], int numoftickets); 
int main(){
	//seats:座位
	//numofseats:每排被占用座位数量
	//cnt:购票次数
	//numoftickets:每次购票张数 
	char seats[20][5];
	int numofseats[20];
	int cnt = 0;
	int *numoftickets = NULL; 
	
	//数组初始化 
	int i,j;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 5; j++){
			seats[i][0] = 'A';
			seats[i][1] = 'B';
			seats[i][2] = 'C';
			seats[i][3] = 'D';
			seats[i][4] = 'F';
		}
	}
	for(i = 0; i < 20; i++){
		numofseats[i] = 0;
	}
	
	//读入购票次数、每次购票张数 
	scanf("%d", &cnt);
	numoftickets = (int*)malloc(cnt*sizeof(int));
	for(i = 0; i < cnt; i++){
		scanf("%d", &numoftickets[i]);
	}
	
	//安排座位 
	for(i = 0; i < cnt; i++){
		arrangeseats(seats, numofseats, numoftickets[i]);
		if(i < cnt - 1){
			printf("\n");
		}
	}
	
	
	free(numoftickets);
	return 0;
}

void arrangeseats(char seats[][5], int numofseats[], int numoftickets){
	int flag = 0;
	int i,j;
	
//	printf("numoftickets = %d\n", numoftickets);
	
	//能安排在同一排相邻座位时 
	for(i = 0; i < 20; i++){
		if(5 - numofseats[i] >= numoftickets){
//			printf("here:i=%d\n", i);
			for(j = numofseats[i]; j < numofseats[i] + numoftickets; j++){
				printf("%d%c", i+1, seats[i][j]);
				if(j < numofseats[i] + numoftickets - 1){
					printf(" ");
				}
			}
//			printf("before:numofseats = %d\n", numofseats[i]);
			numofseats[i] += numoftickets;
//			printf("now:numofseats = %d\n", numofseats[i]); 
			flag = 1;
			return;
		}	
	}
	//不能安排在同一排相邻座位时，安排在编号最小的几个空座位 
	if(flag == 0){
		for(i = 0; i < 20 && numoftickets > 0; i++){
			if(numofseats[i] != 5){
				for(j = numofseats[i] - 1; j < numofseats[i] && numoftickets > 0; j++){
					printf("%d%c", i, seats[i][j]);
					numoftickets--;
					if(numoftickets > 0){
						printf(" ");
					}
//					printf("before:numofseats = %d\n", numofseats[i]); 
					numofseats[i] += numoftickets;
//					printf("now:numofseats = %d\n", numofseats[i]); 
					
				}
			}
		}
	}
	return;
}
