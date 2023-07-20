#include <iostream>
#include <fstream>
using namespace std;

class Person {
    private:
    //Atributes
        string name;
        int age;
        float height;
    public:
    //Constructors
    Person(){

    }
    Person(string name,int age, float height){
        this->name = name;
        this->age = age;
        this->height = height;
    }
    //Methods
        //SETTERS
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setHeight(int height){
            this->height = height;
        }
        //GETTERS
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        float getHeight(){
            return this->height;
        }

        void print(){
            cout << "O meu nome e " << this->name;
            cout << " tenho " << this->age << " anos.";
            cout << "Tenho " << this->height << " cm de altura.\n"; 
        }

};

class Aluno: public Person {
    private:
        int numAluno;

    public:
        void setNumAluno(int numAluno){
            this->numAluno = numAluno;
        }

        int getNumAluno(){
            return this->numAluno;
        }
};


int main(void){
    Person p1;
    Person p2("Antonio", 20, 182);

    p1.setName("Ruben");
    
    ofstream MyFile("pessoas.txt");

    MyFile << "Random ass shit";

    MyFile.close();


    return 0;
}