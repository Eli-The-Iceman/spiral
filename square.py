import sys

#Recursive function for building spiral, 
#builds outer layer of square as a step case
#and use a center single squre or a center 2 x 2 square
#as the base cases ending the recursive loop

#size of outer square, number to start with in top left corner of square,
#array to pass into, index to build square on
def buildsquare(size, startval, square, startindex):
	vals = [[0 for i in range(size)]for j in range(size)]
	if size==1:
		vals[0][0]=startval;
		set(1, startindex,square,vals)
		return
	elif size == 2:
		vals[0][0]=startval
		vals[1][0]=1+startval
		vals[1][1]=2+startval
		vals[0][1]=3+startval
		set(2,startindex,square,vals)
		return
	else:
		for i in range(size):
			vals[0][i] = (4*size) - (3+i) + startval-1
			vals[i][0] = i + startval
			vals[size - 1][i] = size + i + startval-1
			vals[i][size- 1] = (3*size)-(2+i) + startval-1
		buildsquare(size-2, vals[0][1]+1, vals, 1)
		set(size,startindex,square,vals)
		return

#function for settingvalues from one 2d array to another
#outer values to the values of new from index to size
def set(size, index, outer, new):
	for i in range(index,index + size):
		for j in range(index, index + size):
			outer[i][j] = new[i - index][j - index]

val = input('Number: ')
array = [[0 for i in range(val)]for j in range(val)]
buildsquare(val, 1, array, 0)
size = len(str((val*val)))
for i in range(val):
		for j in range(val):
			#for i in range(size - len(str(array[i][j]))):
				#sys.stdout.write(' ')
			if(len(str(array[i][j]))<size):
				sys.stdout.write(" ")
			sys.stdout.write(str(array[i][j]))
			sys.stdout.write(" ")
		sys.stdout.write('\n')