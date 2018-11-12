x = 0
y = 1
z = 1
s = 0
while x+y<=4000000:
	z = x+y
	x = y
	y = z
	if z%2==0:
		s+=z
print(s)
