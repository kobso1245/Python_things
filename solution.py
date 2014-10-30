def int_a_row(arr, n):
	i=0
	cnt=0;
	while i<len(arr):
		if(arr[i]==7):
		 cnt=cnt+1
		 print (cnt)
		 if(cnt==n):
		 	return True
		else:
			cnt=0
		i=i+1
	return False
if __name__ == '__main__':
	print(int_a_row([7,7,7,1,1,1,7,7,7,7], 3))