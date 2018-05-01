#ifndef CLASSES
#define CLASSES
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;

//Класс человек
class Human{
protected:
    int id;
    string first_name;
    string name;
    string second_name;
    int birthday;
    int month_of_birthday;
    int year_of_birthday;
    string sex;
    int age;
    int64_t phone_number;
    string address;
public:
    Human(){}

    Human(int id1, string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1){
            id = id1;
            first_name = first_name1;
            name = name1;
            second_name = second_name1;
            birthday = birthday1;
            month_of_birthday = month_of_birthday1;
            year_of_birthday = year_of_birthday1;
            sex = sex1;
            age = age1;
            phone_number = phone_number1;
            address = address1;
          }

    ~Human(){}

    virtual void showInfo(){
        cout << "ID: " << id << endl;
        cout << "Фамилия: " << first_name << endl;
        cout << "Имя: " << name << endl;
        cout << "Отчество: " << second_name << endl;
        cout << "Дата рождения(ДД.ММ.ГГГГ): " << birthday << "." << month_of_birthday << "." << year_of_birthday << endl;
        cout << "Пол: " << sex << endl;
        cout << "Возраст: " << age << endl;
        cout << "Телефонный номер: " << phone_number << endl;
        cout << "Адрес: " << address << endl;
    }

    virtual string getType(){}

    virtual string getName(){return name;}

    virtual string getSecondName(){return second_name;}

    virtual int getBirthday(){return birthday;}

    virtual int getMonth(){return month_of_birthday;}

    virtual int getYear(){return year_of_birthday;}

    virtual string getSex(){return sex;}

    virtual int64_t getPhone(){return phone_number;}

    virtual string getAdr(){return address;}

    virtual int getId(){return id;}

    virtual void setAge(int age1){age = age1;}

    virtual void setPhoneNumber(int64_t phone_number1){phone_number = phone_number1;}

    virtual void setAddress(string address1){address = address1;}

    virtual void setSalary(int64_t){}

    virtual int64_t getSalary(){}

    virtual int getAge(){return age;}

    virtual string getFirstName(){return first_name;}
};

//Класс администратор
class Administrator : public Human{
private:
    int64_t salary;
    string type = "Administrator";
public:
    Administrator(int id1, string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1, int64_t salary1)
           : Human(id1, first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){
                salary = salary1;
           }

    void showInfo(){
        cout << "====================================" << endl;
        cout << "Должность: Администратор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
        cout << "====================================" << endl;
    }

    void setSalary(int64_t salary1){
        Human::setSalary(salary1);
        salary = salary1;
    }

    string getType(){return type;}

    int64_t getSalary(){return salary;}
};

//Класс Инструктор
class Instructor : public Human{
private:
    int64_t salary;
    string type = "Instructor";
public:
    Instructor(){}

    Instructor(int id1, string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1, int64_t salary1)
           : Human(id1, first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){
                salary = salary1;
           }

    void showInfo(){
        cout << "====================================" << endl;
        cout << "Должность: Инструктор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
        cout << "====================================" << endl;
    }

    string getType(){return type;}

    int64_t getSalary(){return salary;}
};

//Класс Посетитель
class Visitor : public Human{
private:
    string type = "Visitor";
public:
    Visitor(){}

    Visitor(int id1, string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1)
           : Human(id1, first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){}

    void showInfo(){
        cout << "====================================" << endl;
        cout << "Посетитель" << endl;
        Human::showInfo();
        cout << "====================================" << endl;
    }

    string getType(){return type;}
};


//Класс Тренажер
class Train{
private:
    int id_train;
    string type = "Train";
    string usefull;
public:
    Train(){}

    Train(int id_train1, string usefull1){
        id_train = id_train1;
        usefull = usefull1;
    }

    ~Train(){}

    virtual void showInfo(){
        cout << "====================================" << endl;
        cout << "Тип: Тренажёр" << endl;
        cout << "ID тренажёра: " << id_train << endl;
        cout << "Исправность: " << usefull << endl;
        cout << "====================================" << endl;
    }

    virtual string getType(){return type;}

    virtual int getId(){return id_train;}

    virtual string getUsefull(){return usefull;}

    virtual void setUsefull(string usefull1){usefull = usefull1;}
};

#endif