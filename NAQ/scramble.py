tests=int(input())

def encrypt_str(mstr):
    converted=[]
    for num in range(len(mstr)):
        if(mstr[num]==' '):
            converted.append(0)
        else:
            converted.append(ord(mstr[num])-ord('a')+1)
    for i in range(1,len(mstr)):
        converted[i]+=converted[i-1]
    for i in range(0,len(mstr)):
        converted[i]%=27
    for i in range(0,len(mstr)):
        if(converted[i]==0):
            converted[i]=' '
        else:
            converted[i]=chr(converted[i]+ord('a')-1)
    return converted


def decrypt_str(mstr):
    converted=[]
    for num in range(len(mstr)):
        if(mstr[num]==' '):
            converted.append(0)
        else:
            converted.append(ord(mstr[num])-ord('a')+1)
    for i in range(1,len(mstr)):
        while(converted[i]<converted[i-1]):
            converted[i]+=27
    for i in range(len(mstr)-1,0,-1):
        converted[i]-=converted[i-1]
    for i in range(0,len(mstr)):
        if(converted[i]==0):
            converted[i]=' '
        else:
            converted[i]=chr(converted[i]+ord('a')-1)
    return converted



for test in range(tests):
    line=list(input())
    action=line[0]
    symbols=line[2:]
    if(action=='e'):
        print(''.join(map(str,encrypt_str(symbols))))
    else:
        print(''.join(map(str,decrypt_str(symbols))))

