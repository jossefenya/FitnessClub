/*22. Разработка информационно-поисковой системы «Фитнес-клуб»
Для хранения информации использовать файл. Функционал программы:
1) добавление информации;
2) удаление информации;
3) редактирование информации;
4) поиск информации по заданным критериям.*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Класс человек
class Human{
protected:
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

    Human(string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1){
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
        cout << "Фамилия: " << first_name << endl;
        cout << "Имя: " << name << endl;
        cout << "Отчество: " << second_name << endl;
        cout << "Дата рождения(ДД.ММ.ГГГГ): " << birthday << "." << month_of_birthday << "." << year_of_birthday << endl;
        cout << "Пол: " << sex << endl;
        cout << "Возраст: " << age << endl;
        cout << "Телефонный номер: " << phone_number << endl;
        cout << "Адрес: " << address << endl;
    }
};

//Класс администратор
class Administrator : public Human{
private:
    int id_admin = 0;
    int64_t salary;
    string type = "Administrator";
public:
    Administrator(string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1, int64_t salary1, int id_admin1)
           : Human(first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){
                id_admin = id_admin1;
                salary = salary1;
           }

    void showInfo(){
        cout << "ID Администратора: " << id_admin << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
        cout << "Должность: Администратор" << endl;
    }
};

class Instructor : public Human{
private:
    int id_instructor = 0;
    int64_t salary;
    string type = "Instructor";
public:
    Instructor(){}

    Instructor(string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1, int64_t salary1, int id_instructor1)
           : Human(first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){
                id_instructor = id_instructor1;
                salary = salary1;
           }

    void showInfo(){
        cout << "ID Инструктора: " << id_instructor << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
        cout << "Должность: Инструктор" << endl;
    }
};

class Visitor : public Human{
private:
    int id_visitor = 0;
    string type = "Visitor";
public:
    Visitor(){}

    Visitor(string first_name1, string name1, string second_name1,
          int birthday1, int month_of_birthday1, int year_of_birthday1,
           string sex1, int age1, int64_t phone_number1, string address1, int id_visitor1)
           : Human(first_name1, name1, second_name1, birthday1, month_of_birthday1, year_of_birthday1, sex1, age1, phone_number1, address1){
                id_visitor = id_visitor1;

           }

    void showInfo(){
        cout << "ID Посетителя: " << id_visitor << endl;
        Human::showInfo();
    }
};

int main()
{
    int count_of_adm = 0;
    int count_of_ins = 0;
    int count_of_vis = 0;
    vector <Human*> humans;
    /*Administrator A("a", "a", "a", 1, 1, 1, "m", 1, 1, "adr", 10, 1);
    A.showInfo();
    cout << endl;
    Instructor B("a", "a", "a", 1, 1, 1, "m", 1, 1, "adr", 10, 2);
    B.showInfo();
    cout << endl;
    Visitor V("c", "c", "c", 5, 6, 7, "f", 7, 89, "adr2", 6);
    V.showInfo();*/
    while (1){
        cout << "1) Добавить данные о человеке в базу данных." << endl;
        cout << "2) Удалить данные о человеке из базы данных." << endl;
        cout << "3) Редактирование информации о человеке в базе данных." << endl;
        cout << "4) Поиск информации по заданным критериям" << endl;
    }
    humans.clear();
    return 0;
}
