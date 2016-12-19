#include <iostream>
#include <string.h>

using namespace std;

class Object
{
public:
    virtual void print();
    virtual int Equals(Object&);
private:
};

void Object::print()
{
    std::cout<<this<<std::endl;
}

int Object::Equals(Object& obj1)
{
    if(this == (&obj1))
        return 1;
    return 0;
}



class Vector : virtual public Object
{
public:
    Vector(int);
    void add(Object&);
    void print();
    int check(Object&);
    virtual ~Vector();
    Object* operator[](int);
private:
    Object** vect;
    int dimensiune;
    int last;
};

Vector::Vector(int dimensiune)
{
    this->dimensiune = dimensiune;
    this->vect = new Object*[dimensiune];
    this->last =-1;
}

void Vector::add(Object& x)
{
    if(this->last + 1 < this->dimensiune)
    {
        this->last++;
        this->vect[last] = &x;
    }
}

int Vector::check(Object& x)
{
    for(int i=0; i<=this->last; i++)
    {
        if(this->vect[i]->Equals(x))
            return 1;
    }
    return 0;
}

void Vector::print()
{
    for(int i=0; i<=this->last; i++)
    {

        this->vect[i]->print();
    }
}

Object* Vector::operator[](int i)
{
    if(i<last);
    return this->vect[i];
    return 0;
}

Vector::~Vector()
{
    delete this->vect;
}

class String:public Object
{
private:
    char *sir;
public:
    String()
    {
        sir = new char[250];
    }
    String(char *k)
    {
        sir = new char[250];
        strcpy(sir,k);
    }
    Equals(Object &obj)
    {
        String & strobj= *(String*) &obj;
        return strcmp (sir, strobj.sir)==0 ? 1:0;
    }

    void print()
    {
        cout<<sir<<endl;
    }
};

int main()
{
    Vector vect(4);
    String c("Extraustil");
    vect.add(c);
    vect.add(*(new String("Ionut")));
    vect.add(*(new String ("Mihai")));
    vect.add(*(new String("Stil")));
    vect.print();
    if (vect.check(*(new String("Ionut"))))
        cout<<"Cuvantul dat se afla in vectorul de stringuri.\n";
    else
        cout<<"Cuvantul dat nu a fost gasit\n";
    vect[2]->print();
}
