class Student :  public Person{
    
	private:
		vector<int> testScores;  
        
	public:
  		Student(string firstName, string lastName, int id, vector<int>& testScores): Person(firstName,lastName,id), testScores(testScores)
  		{}
  		
  	    char calculate(){
  	    int total=0;
  	    for(vector<int>::iterator it=testScores.begin(); it!=testScores.end();it++)
  	         total+=*it;
  	   int ave=(total/testScores.size());
  	    string g="OEAPDT";
  	    
  	    if(ave>=90)return g[0];
  	    if(ave>=80)return g[1];
  	    if(ave>=70)return g[2];
  	    if(ave>=55)return g[3];
  	    if(ave>=40)return g[4];
  	    return g[5];
  	    }
};
