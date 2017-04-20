def merge_the_tools(string, k):
    for start in range (0, len(string),k):
        substr=""
        for c in string[start:start+k]:
            if(substr.find(c)==-1):
               substr+=c
        print(substr)
        
   