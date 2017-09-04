#Project Euler #165: Intersections
from decimal import *

def BlumBlumShubPseudoGenerate(targetNumSegments):
	#create pseudorandom points
	randoms=[]
	pointsNeeded=4*targetNumSegments
	sPrev=290797;
	while(pointsNeeded>0):
		sPrev=(sPrev*sPrev)%50515093
		randoms.append(Decimal(sPrev%500))
		pointsNeeded-=1
	#convert points into segments
	pointIndex=0
	pointsNeeded=4*targetNumSegments
	segmentsArr=[]
	while (pointIndex<pointsNeeded):
		segmentsArr.append(randoms[pointIndex:pointIndex+4])
		pointIndex+=4;
	return segmentsArr

def getIntersectionPoint(segment1, segment2):
	x1=segment1[0]
	x2=segment1[2]
	y1=segment1[1]
	y2=segment1[3]
	x3=segment2[0]
	x4=segment2[2]
	y3=segment2[1]
	y4=segment2[3]

	if(x1==x3 or x1==x4 or x2==x3 or x2==x4
		or y1==y3 or y1==y4 or y2==y3 or y2==y4
		or x2==x1 or x4==x3):
		return None
	slope1=(y2-y1)/(x2-x1)
	inter1=y2-slope1*x2
	slope2=(y4-y3)/(x4-x3)
	inter2=y3-slope2*x3
	if(slope1==slope2):
		return None
		#not true intersection if infinite points
	intersectX=(inter2-inter1)/(slope1-slope2)
	intersectY=(intersectX)*slope1+inter1
	if((( intersectX>x1 and intersectX<x2) or
		( intersectX<x1 and intersectX>x2)) and
	   (( intersectX>x3 and intersectX<x4) or
		( intersectX<x3 and intersectX>x4)) and
	   (( intersectY>y1 and intersectY<y2) or
		( intersectY<y1 and intersectY>y2)) and
	   (( intersectY>y3 and intersectY<y4) or
		( intersectY<y3 and intersectY>y4))):
		return (intersectX,intersectY)
	return None


def collectIntersectionPoints(segmentsArr):
	uniquePoints=set()
	lenSegsArr=len(segmentsArr)
	for num in range(0,lenSegsArr-1):
		for num2 in range(num+1,lenSegsArr):
			seg1=segmentsArr[num]
			seg2=segmentsArr[num2]
			point=getIntersectionPoint(seg1, seg2)
			if (point!=None):
				uniquePoints.add(point)
	return uniquePoints

def main():
	numSegments=int(input())
	segsArr=BlumBlumShubPseudoGenerate(numSegments)
	uniquePointsArr=collectIntersectionPoints(segsArr)
	print(len(uniquePointsArr))
	checkWithMathPlot=True
	if checkWithMathPlot:
		import matplotlib.pyplot as plt

		for seg in segsArr:
			x1=seg[0]
			x2=seg[2]
			y1=seg[1]
			y2=seg[3]
			plt.plot([x1,x2],[y1,y2]);
		for point in uniquePointsArr:
			plt.plot(point[0], point[1], marker='o', markersize=2, color="red")
		plt.show()

main()