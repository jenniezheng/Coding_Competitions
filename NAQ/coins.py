num_coins=int(input())
coins=list(map(int,input().split()))

for index in range(1,num_coins):
    if(coins[index]%coins[index-1]!=0):
        print('non-canonical')
        exit(0)
print('canonical')