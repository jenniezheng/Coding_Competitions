target_x,target_y=map(int, input().split())
num_dirs=int(input())
dirs=[]
for test in range (num_dirs):
    dirs.append(input())


def dir_works():
    global dirs,target_x,target_y
    x=0
    y=0
    direction=0 #north
    for dir in dirs:
        if(dir=='Right'):
            direction=(direction+1)%4
        elif(dir=='Left'):
            direction=(direction-1)%4
        else:
            if(direction==0):
                y+=1
            elif(direction==1):
                x+=1
            elif(direction==2):
                y-=1
            elif(direction==3):
                x-=1
    if(x==target_x and y==target_y):
        return True
    return False





for change_index in range(num_dirs):
    original=dirs[change_index]
    dirs[change_index]='Right'
    if(dir_works()):
        print(str(change_index+1)+' Right')
        exit(0)
    dirs[change_index]='Left'
    if(dir_works()):
        print(str(change_index+1)+' Left')
        exit(0)
    dirs[change_index]='Forward'
    if(dir_works()):
        print(str(change_index+1)+' Forward')
        exit(0)
    dirs[change_index]=original
