//Write MyBook class
class MyBook:public Book{
  public:
    int price;
    MyBook(string t, string a, int p): Book(t,a){
        price=p;
    }
    
    void display(){
        cout<<"Title: "<<Book::title<<endl;
        cout<<"Author: "<<Book::author<<endl;
        cout<<"Price: "<<price<<endl;
    }
};