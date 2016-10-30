class Box{
public:
  int l,b,h;
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:

 Box(int l=0,int b=0,int h=0) : l(l),b(b),h(h){BoxesCreated++;}

// Destructor
 Box(const Box& B ):l(B.l), b(B.b),h(B.h){BoxesCreated++;}

 ~Box(){BoxesDestroyed++; }


 int getLength() {return l;} // Return box's length
 int getBreadth() {return b;}; // Return box's breadth
 int getHeight() {return h;};  //Return box's height
 long long CalculateVolume(){return (long long)l * b *h;}; // Return the volume of the box

//Overload operator < as specified
bool operator<(Box &b){
   
    if(this->l!=b.l)return this->l<b.l;
    if(this->b!=b.b)return this->b<b.b;
   return this->h<b.h;
 
}

//Overload operator << as specified

};
ostream& operator<<(ostream& out, Box& B){
     BoxesCreated++;BoxesDestroyed++;
  out<<B.l<<" "<<B.b<<" "<<B.h;
    return out;}