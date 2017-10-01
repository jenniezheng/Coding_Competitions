from datetime import datetime, timedelta

class Solution(object):
    def subtract_times(self):
        FMT = '%H:%M'
        tdelta = datetime.strptime("01:11", FMT) - datetime.strptime("01:11", FMT)
        print(tdelta)
    def nextClosestTime(self, time):

        digits=list(time)
        digits.remove(":")
        digits=list(map(int,digits))
        FMT = '%H:%M'
        min_diff=-1
        current_time=datetime.strptime(time, '%H:%M')
        next_closest="59:59"
        for a in digits:
            for b in digits:
                if(a*10+b>=24):
                    continue
                for c in digits:
                    if(c>=6):
                        continue
                    for d in digits:
                        new_time=str(a)+str(b)+":"+str(c)+str(d)

                        tdelta = datetime.strptime(new_time, FMT) - current_time
                        if(new_time==time):
                            tdelta+=timedelta(days=1)
                        if(tdelta.days<0):
                            tdelta+=timedelta(days=1)
                        if(min_diff==-1 or min_diff>tdelta):
                            min_diff=tdelta
                            next_closest=new_time
                            #print(next_closest)
        return next_closest






s=Solution();
print(s.nextClosestTime("00:00"))