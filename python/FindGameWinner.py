def minion_game(string):    
   vowPt=0
   conPt=0
   vowels="AEIOU"
   for start in range (0, len(string)):
       pts=len(string)-start
       if (vowels.find(string[start])!=-1):
           vowPt+=pts
       else:
           conPt+=pts
   if(vowPt>conPt):
       print("Kevin",vowPt)
   elif(vowPt==conPt):
       print("Draw")
   else:
       print("Stuart",conPt)
       
