tests= int(input())
for test in range (tests):
    my_list=list(map(int, input().split()))
    num=my_list[0]
    gnomes=my_list[1:]
    starting=gnomes[0]
    for index in range(len(gnomes)):
        gnome_num=gnomes[index]
        if(starting+index!=gnome_num):
            print(index+1)
            break

