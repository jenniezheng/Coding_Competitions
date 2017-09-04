import sys
#for recursion
sys.setrecursionlimit(10000)
#maps number stones in pile to # moves for pile
memo={}
#ways allowed to divide a pile
divide_arr=[]
#maps number of stones in pile to pile count


def main():
    testCases=int(input())
    while (testCases):
        testCases-=1;
        #clear map since new test case has new set
        memo.clear()
        global divide_arr
        divide_arr=[]
        size_of_initial_pile=int(input().split()[0])
        divide_arr=list(map(int, input().split()))
        divide_arr.sort()
        print("size_of_initial_pile:", size_of_initial_pile);
        print("divide_arr:", divide_arr);
        #pass in piles array with just one pile
        result=max_moves(size_of_initial_pile);
        print(result);


def max_moves(pile_size):
    print("pile_size:", pile_size);
    if(pile_size in memo):
        return memo[pile_size];
    count=0;
    print(divide_arr)
    for x in divide_arr:
        print("x:", x);
        if(pile_size <= x):
            break;
        elif(pile_size % x == 0):
            trial=1+max_moves(x)*(pile_size//x)
            print("trial:", trial);
            if(trial>count):
                count=trial;
    memo[pile_size]=count;
    return count;

main();