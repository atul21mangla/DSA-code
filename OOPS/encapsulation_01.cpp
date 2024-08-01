#include<iostream>
using namespace std;

class Student{
    public:
    int id;
    int age;
    string name;

    private:
    string gf;
    float* gpa;

    public:
    Student(){
        cout<<"Student Default Constructor called."<<endl;
    }

    Student(int id,int age,string name,string gf,float gpa){
        cout<<"Student parametrized Ctor called."<<endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->gf = gf;
        this->gpa = new float(gpa);
    }
    
    void setGpa(float gpa){
        *this->gpa = gpa;
    }

    float getGpa()const{
        return *this->gpa;
    }

    void sleep(){
        cout<<this->name<<" is sleeping."<<endl;
    }
    void study(){
        cout<<this->name<<" is studying."<<endl;
    }

    private:
    void gfChatting(){
        cout<<this->name<<" is chatting with "<<this->gf<<endl;
    }

    // dtor
    public:
    ~Student(){
        cout<<"Student Default Destructor called."<<endl;
    }
};

int main(){
    Student s1(1,21,"Atul","Anushka",9.42);
    s1.study();
    cout<< s1.getGpa()<<endl;
    cout<<s1.name<<endl;
    s1.setGpa(9.04);
    cout<< s1.getGpa()<<endl;
    return 0;
}