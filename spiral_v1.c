/*
** Created by: Matt Jackels
** Created on: 6/24/17
** Description: Takes user int input and outputs a spiral
** of numbers in a clockwise direction of values that increase 
** from 1 to (input^2)
**
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int c;

	printf("Enter input value: ");
	scanf("%d", &c);

	int array[c][c];
	int min_x,min_y;
	int max_x, max_y;
	int count = 0;

	min_y = min_x = 0;
	max_y = max_x = (c-1);

	while(count < (c*c)){
		for(int i = min_x; i <= max_x; ++i){
			array[i][min_y] = ++count;
			//printf(" i = %d, min_y = %d, count = %d \n", i, min_y, count);
		}
		min_y++;

		for(int j = min_y; j <= max_y; ++j){
			array[max_x][j] = ++count;
			//printf(" j = %d, max_x = %d, count = %d \n", j, max_x, count);
		}
		max_x--;

		for(int k = max_x; k >= min_x; --k){
			array[k][max_y] = ++count;
			//printf(" k = %d, max_y = %d, count = %d \n", k, max_y, count);
		}
		max_y--;

		for(int m = max_y; m >= min_y; --m){
			array[min_x][m] = ++count;
			printf(" x = %d, y = %d, count = %d \n", min_x, m, count);
		}
		min_x++;
	}

	for(int i = 0; i < c; ++i){
		for(int j = 0; j < c; ++j){
			printf("%d \t", array[j][i]);

		}
		printf("\n");
	}

}
