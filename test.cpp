#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

    virtual int getId(){
        return id;
    }

    virtual void addInfoInFile(){
        ofstream fout("database.txt");
        fout << id << endl << first_name << endl << name << endl << second_name << endl;
        fout.close();
    }

    virtual void addInfoFromFile(){
        fstream fin("database.txt");
        int id = 0;
        int64_t salary;
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
        cout << "Введите данные" << endl;
        cout << "ID Администратора: ";
        fin >> id;
        cout << endl << "Фамилия Имя Отчество: ";
        fin.get();
        getline(cin, first_name);
        getline(cin, name);
        getline(cin, second_name);
        cout << endl << "Дата рождения(ДД.ММ.ГГГГ): ";
        fin >> birthday >> month_of_birthday >> year_of_birthday;
        cout << endl << "Пол(М-Мужской, F-Женский): ";
        fin.get();
        getline(cin, sex);
        cout << endl << "Возраст: ";
        fin >> age;
        cout << endl << "Телефонный номер: ";
        fin >> phone_number;
        cout << endl << "Адрес: ";
        fin.get();
        getline(cin, address);
        cout << "Зарплата: ";
        fin >> salary;
        humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    }
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
        cout << "Должность: Администратор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
    }
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
        cout << "Должность: Инструктор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
    }
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
        cout << "Посетитель" << endl;
        Human::showInfo();
    }
};

int main()
{
    vector<Human*> humans;
    int id = 0;
    int64_t salary;
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
    cout << "Введите данные" << endl;
    cout << "ID Администратора: ";
    cin >> id;
    cout << endl << "Фамилия Имя Отчество: ";
    cin.get();
    getline(cin, first_name);
    getline(cin, name);
    getline(cin, second_name);
    cout << endl << "Дата рождения(ДД.ММ.ГГГГ): ";
    cin >> birthday >> month_of_birthday >> year_of_birthday;
    cout << endl << "Пол(М-Мужской, F-Женский): ";
    cin.get();
    getline(cin, sex);
    cout << endl << "Возраст: ";
    cin >> age;
    cout << endl << "Телефонный номер: ";
    cin >> phone_number;
    cout << endl << "Адрес: ";
    cin.get();
    getline(cin, address);
    cout << "Зарплата: ";
    cin >> salary;
    humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    humans[0]->addInfoInFile();
    return 0;
}
