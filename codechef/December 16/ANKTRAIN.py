D = {}
D[3] = D[6] = "UB"
D[2] = D[5] = "MB"
D[1] = D[4]= "LB"
D[7] = "SU"
D[8]= "SL"

t=input()
for x in xrange(0,t):
	num = input()
	if num<=3:
		print "%d%s"%(num+3,D[num])
		continue
	elif num<7:
		print "%d%s"%(num-3,D[num])
		continue

	if num%8==0:
		print "%d%s"%(num-1,D[8])
		continue
	elif (num+1)%8==0:
		print "%d%s"%(num+1,D[7])
		continue

	for i in range(1,8):
		if ((num-i)%8==0):
			if i<=3:
				print "%d%s"%(num+3,D[i]) 
			else :
				print "%d%s"%(num-3,D[i])
			break