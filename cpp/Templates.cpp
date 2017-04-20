/*Write the class AddElements here*/
template <class T> class AddElements {
public:
    T element;
    AddElements(T a){
        element=a;
    }
    T add(T otherElement){
        return element+otherElement;
    }


};
template <> class
    AddElements <string>{
public:
       string element;
    AddElements(string a){
        element=a;
    }
    string concatenate(string otherElement){
        string ans=this->element+otherElement;
        return ans;
    }


};