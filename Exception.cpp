class BadLengthException: public exception{
public:
    int n;
    BadLengthException(int n): n(n){}
    const int what() {
            return n;
    }
};
