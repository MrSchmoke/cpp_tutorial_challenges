#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    //friend keyword gives access to private members
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &rhs, const Mystring &obj);
    friend bool operator==(const Mystring &rhs, const Mystring &obj);   
    friend bool operator!=(const Mystring &rhs, const Mystring &obj);           //not equals
    friend bool operator<(const Mystring &rhs, const Mystring &obj);            // smaller than
    friend bool operator>(const Mystring &rhs, const Mystring &obj);    // bigger than
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(Mystring &lhs, const int &n);
    friend Mystring &operator*=(Mystring &lhs, const int &n);
    friend Mystring &operator++(Mystring &obj);
    friend Mystring operator++(Mystring &obj, const int);

    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_