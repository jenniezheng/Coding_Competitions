#!/bin/python3
import sys
import os

# Complete the function below.
def paginate(resPerPage, inputArr):
    data=[]
    for res in inputArr:
        host=res[:res.index(",")]
        other=res[res.index(","):]
        data.append((host,other))

    res=[]
    while len(data)!=0:
        skipped=[]
        index_in_page=0
        hosts=set()
        selected=set()
        for x in range(0,len(data)):
            dat=data[x]
            host=dat[0]
            other=dat[1]
            orig_data=str(host)+str(other)
            if host not in hosts:
                hosts.add(host)
                res.append(orig_data)
                selected.add(x)
                index_in_page+=1
                if index_in_page==resPerPage:
                    break
            else:
                if(len(skipped)<resPerPage):
                    skipped.append((orig_data,x))

        for skip in skipped:
            if(index_in_page%resPerPage==0):
                break
            orig_data,index=skip
            res.append(orig_data)
            selected.add(index)
            index_in_page+=1
        new_data=[]
        for x in range(0,len(data)):
            if x not in selected:
                new_data.append(data[x])

        data=new_data
        if len(data)!=0:
            res.append('')

    return res



if __name__ == "__main__":
    num = 2

    results=["1,2,300,a","1,2,300,a","1,2,300,a","1,2,300,a","2,2,300,a"]


    res = paginate(num, results);
    print("results")
    for res_cur in res:
        print( str(res_cur))

