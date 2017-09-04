from fractions import Fraction
import math
[startA,endA, startB,endB,efficacy]= input().split("\n")[0].split(" ")

[startA,endA, startB,endB]=map(int, [startA,endA, startB,endB])
res=Fraction(efficacy)
startA_constant=math.ceil(startA/res.numerator)
endA_constant=math.floor(endA/res.numerator)
startB_constant=math.ceil(startB/res.denominator)
endB_constant=math.floor(endB/res.denominator)

if(startA_constant<=endA_constant and startB_constant<=endB_constant and
	((endA_constant >= startB_constant and endB_constant >= endA_constant) or
	 (endB_constant >= startA_constant and endA_constant >= endB_constant))):
	print("YES")
else:
	print("NO")