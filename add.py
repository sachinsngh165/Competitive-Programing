import random
from datetime import datetime

n = input("How many numbers you want to add: ")
n = int(n)

count = 0


ts = 0
while True:
	nums = []
	start=datetime.now()
	for i in range(n):
		num  = random.randint(10,100)
		print num,
		nums.append(num)


	s = sum(nums)
	ans = input("= ")
	ans = int(ans)

	if ans is not s:
		count += 1
		print "\nWrong\n"

	t  = datetime.now()-start

	b = raw_input('more(y/n): ')
	if b is 'n':
		break


print count
# print ts