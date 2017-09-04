
class Solution:

    def maximumSwap(self, num):
        num=list(str(num))
        num_sorted=num[:];
        num_sorted.sort();
        num_sorted=num_sorted[::-1]
        diff_value=-1;
        diff_index=-1;
        diff2_value=-1;
        for x in range(0, len(num)):
            if(num[x]!=num_sorted[x]):
                diff_value=num[x];
                diff2_value=num_sorted[x];
                diff_index=x;
                break;
        if(diff_index==-1):
            return int("".join(num));
        diff2_index=-1;
        for x in range(len(num)-1,-1,-1):
            if(num[x]==diff2_value):
                diff2_index=x;
                break;
        sol="";
        for x in range(0, len(num)):
            if(x==diff2_index):
                sol+=diff_value
            elif(x==diff_index):
                sol+=diff2_value
            else:
                sol+=num[x]
        return int("".join(sol));