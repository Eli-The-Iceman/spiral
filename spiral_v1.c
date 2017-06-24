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

	//initialize variables
	int array[c][c];
	int min_x,min_y;
	int max_x, max_y;
	int count = 0;

	min_y = min_x = 0;
	max_y = max_x = (c-1);

	/*
	** This loop will build the spiral until the square value is reached
	** It creates the array by looping in each direction that the spiral would move
	** while incrementing the count for that array loaction. Each for loop moves 
	** the program a specific direction. The maximum x and y values and minimum
	** x and y values are adjusted accordingly each iteration so that they will
	** no longer write to an already populated position.
	*/
	while(count < (c*c)){
		//left to right
		for(int i = min_x; i <= max_x; ++i){
			array[i][min_y] = ++count;
		}
		min_y++;
		//top to bottom
		for(int j = min_y; j <= max_y; ++j){
			array[max_x][j] = ++count;
		}
		max_x--;
		//right to left
		for(int k = max_x; k >= min_x; --k){
			array[k][max_y] = ++count;
		}
		max_y--;
		//bottom to top
		for(int m = max_y; m >= min_y; --m){
			array[min_x][m] = ++count;
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
