class Solution:
    def judgePoint24(self, nums):
        for index1 in range (0,4):
            one=nums[index1]
            for index2 in range (0,4):
                if index1==index2:
                    continue
                two=nums[index2]
                for result1 in [one*two, one/two, one+two, one-two]:
                    for index3 in range (0,4):
                        if index1==index3 or index2==index3:
                            continue
                        three=nums[index3]
                        possible2=[result1*three,result1+three,result1-three,three-result1]
                        if(three!=0 and result1!=0):
                            possible2.append(result1/three)
                            possible2.append(three/result1)
                        for result2 in possible2:
                             for index4 in range (0,4):
                                if index1==index4 or index2==index4 or index3==index4:
                                    continue
                                four=nums[index4]
                                possible3=[result2*four,result2+four,result2-four,four-result2]
                                if(four!=0 and result2!=0):
                                    possible3.append(result2/four)
                                    possible3.append(four/result2)
                                for result3 in possible3:
                                    if(result3==24):
                                        return True
                    for index3 in range (0,4):
                        if index1==index3 or index2==index3:
                            continue
                        three=nums[index3]
                        for index4 in range (0,4):
                            if index1==index4 or index2==index4 or index3==index4:
                                continue
                            four=nums[index4]
                            possible4=[three*four,three+four,three-four]
                            if(four!=0):
                                possible4.append(three/four)
                            for result2 in possible4:
                                if(result1*result2==24):
                                    return True
        return False

s=Solution()
print(s.judgePoint24([1,2,9,1]))
