import math
row,col=map(int,input())
arr=[]
for x in range(row):
    nums=list(map(int,input().split()))
    arr.append(nums)

ones={}
inset=[]
for x in range(row):

