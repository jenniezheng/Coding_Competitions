class Solution(object):

    def calPoints(self, ops):
        rounds=[]
        for op in ops:
            if(op=='+'):
                rounds.append(rounds[-1]+rounds[-2])
            elif(op=='D'):
                rounds.append(rounds[-1] * 2)
            elif(op=='C'):
                del rounds[-1]
            else:
                num=int(op)
                rounds.append(num)
        sum=0
        for num in rounds:
            sum+=num
        return sum




s=Solution();
print(s.calPoints(["5","2","C","D","+"]))