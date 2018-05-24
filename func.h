#ifndef MY_FUNC
#define MY_FUNC
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "classes.h"
using namespace std;

//Функции добавления объекта в вектор объектов
void addInfoAboutAdmin(vector<Human*> &humans, int& all_count){
    int id = all_count;
    int64_t salary;
    string first_name;
    string name;
    string second_name;
    int birthday;
    int month_of_birthday;
    int year_of_birthday;
    string sex;
    int age;
    string phone_number;
    string address;
    cout << "Введите данные" << endl;
    cout << "ESC для отмены" << endl;
    cout << endl << "Фамилия Имя Отчество(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, first_name);
    if ((int)first_name[0] == 27){
        system("clear");
        return;
    }
    for (int i = 0; i < first_name.length(); i++){
        if (first_name[0] >= 97 && first_name[0] <= 122){
            first_name[0] -= 32;
            i++;
        }
        if (first_name[i] >= 65 && first_name[i] <= 90)
            first_name[i] += 32;
        if (first_name[i] < 65 || first_name[i] > 90 && first_name[i] < 97 || first_name[i] > 122){
            first_name[i] = 96;
        }
    }
    getline(cin, name);
    if ((int)name[0] == 27){
        system("clear");
        return;        
    }
    for (int i = 0; i < name.length(); i++){
        if (name[0] >= 97 && name[0] <= 122){
            name[0] -= 32;
            i++;
        }
        if (name[i] >= 65 && name[i] <= 90)
            name[i] += 32;
        if (name[i] < 65 || name[i] > 90 && name[i] < 97 || name[i] > 122){
            name[i] = 96;
        }
    }
    getline(cin, second_name);
    if ((int)second_name[0] == 27){
        system("clear");
        return;
    }
    for (int i = 0; i < second_name.length(); i++){
        if (second_name[0] >= 97 && second_name[0] <= 122){
            second_name[0] -= 32;
            i++;
        }
        if (second_name[i] >= 65 && second_name[i] <= 90)
            second_name[i] += 32;
        if (second_name[i] < 65 || second_name[i] > 90 && second_name[i] < 97 || second_name[i] > 122){
            second_name[i] = 96;
        }
    }
    cout << endl << "Дата рождения(ДД.ММ.ГГГГ): " << endl;
    cout << "День: ";
    cin >> birthday;
    if (birthday > 31 || birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> birthday;
    }
    cout << "Месяц: ";
    cin >> month_of_birthday;
    if (month_of_birthday > 12 || month_of_birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> month_of_birthday;
    }
    cout << "Год: ";
    cin >> year_of_birthday;
    if (year_of_birthday > 2018 || year_of_birthday < 1950){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> year_of_birthday;
    }
    cout << endl << "Пол(М(1)-Мужской, F-Женский): ";
    cin.get();
    getline(cin, sex);
    if (sex[0] == 27){
        system("clear");
        return;        
    }
    if (sex != "m" && sex != "M" && sex != "f" && sex != "F" && sex != "1"){
        sex = "f";
    }
    else if (sex == "1")
        sex = "m";
    cout << endl << "Возраст: ";
    cin >> age;
    cout << endl << "Телефонный номер: ";
    cin.get();
    cin >> phone_number;
    cout << endl << "Адрес(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, address);
    if (address[0] == 27){
        system("clear");
        return;        
    }
    for (int i = 0; i < address.length(); i++){
        if (address[0] >= 97 && address[0] <= 122){
            address[0] -= 32;
            i++;
        }
        if (address[i] < 65 || address[i] > 90 && address[i] < 97 || address[i] > 122){
            address[i] = 96;
        }
    }
    cout << endl;
    cout << "Зарплата: ";
    cin >> salary;
    humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    system("clear");
}

void addInfoAboutIns(vector<Human*> &humans, int& all_count){
    int id = all_count;
    int64_t salary;
    string first_name;
    string name;
    string second_name;
    int birthday;
    int month_of_birthday;
    int year_of_birthday;
    string sex;
    int age;
    string phone_number;
    string address;
    cout << "Введите данные" << endl;
    cout << "ESC для отмены" << endl;
    cout << endl << "Фамилия Имя Отчество(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, first_name);
    if ((int)first_name[0] == 27){
        system("clear");
        return;
    }
    for (int i = 0; i < first_name.length(); i++){
        if (first_name[0] >= 97 && first_name[0] <= 122){
            first_name[0] -= 32;
            i++;
        }
        if (first_name[i] >= 65 && first_name[i] <= 90)
            first_name[i] += 32;
        if (first_name[i] < 65 || first_name[i] > 90 && first_name[i] < 97 || first_name[i] > 122){
            first_name[i] = 96;
        }
    }
    getline(cin, name);
    if ((int)name[0] == 27){
        system("clear");
        return;        
    }
    for (int i = 0; i < name.length(); i++){
        if (name[0] >= 97 && name[0] <= 122){
            name[0] -= 32;
            i++;
        }
        if (name[i] >= 65 && name[i] <= 90)
            name[i] += 32;
        if (name[i] < 65 || name[i] > 90 && name[i] < 97 || name[i] > 122){
            name[i] = 96;
        }
    }
    getline(cin, second_name);
    if ((int)second_name[0] == 27){
        system("clear");
        return;
    }
    for (int i = 0; i < second_name.length(); i++){
        if (second_name[0] >= 97 && second_name[0] <= 122){
            second_name[0] -= 32;
            i++;
        }
        if (second_name[i] >= 65 && second_name[i] <= 90)
            second_name[i] += 32;
        if (second_name[i] < 65 || second_name[i] > 90 && second_name[i] < 97 || second_name[i] > 122){
            second_name[i] = 96;
        }
    }
    cout << endl << "Дата рождения(ДД.ММ.ГГГГ): " << endl;
    cout << "День: ";
    cin >> birthday;
    if (birthday > 31 || birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> birthday;
    }
    cout << "Месяц: ";
    cin >> month_of_birthday;
    if (month_of_birthday > 12 || month_of_birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> month_of_birthday;
    }
    cout << "Год: ";
    cin >> year_of_birthday;
    if (year_of_birthday > 2018 || year_of_birthday < 1950){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> year_of_birthday;
    }
    cout << endl << "Пол(М(1)-Мужской, F-Женский): ";
    cin.get();
    getline(cin, sex);
    if (sex[0] == 27){
        system("clear");
        return;        
    }
    if (sex != "m" && sex != "M" && sex != "f" && sex != "F" && sex != "1"){
        sex = "f";
    }
    else if (sex == "1")
        sex = "m";
    cout << endl << "Возраст: ";
    cin >> age;
    cout << endl << "Телефонный номер: ";
    cin.get();
    cin >> phone_number;
    cout << endl << "Адрес(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, address);
    if (address[0] == 27){
        system("clear");
        return;        
    }
    for (int i = 0; i < address.length(); i++){
        if (address[0] >= 97 && address[0] <= 122){
            address[0] -= 32;
            i++;
        }
        if (address[i] < 65 || address[i] > 90 && address[i] < 97 || address[i] > 122){
            address[i] = 96;
        }
    }
    cout << endl;
    cout << "Зарплата: ";
    cin >> salary;
    humans.push_back(new Instructor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    system("clear");
}

void addInfoAboutVis(vector<Human*> &humans, int& all_count){
    int id = all_count;
    string first_name;
    string name;
    string second_name;
    int birthday;
    int month_of_birthday;
    int year_of_birthday;
    string sex;
    int age;
    string phone_number;
    string address;
    cout << "Введите данные" << endl;
    cout << "ESC для отмены" << endl;
    cout << endl << "Фамилия Имя Отчество(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, first_name);
    if (first_name[0] == 27){
        system("clear");
        return;
    }
    for (int i = 0; i < first_name.length(); i++){
        if (first_name[0] >= 97 && first_name[0] <= 122){
            first_name[0] -= 32;
            i++;
        }
        if (first_name[i] >= 65 && first_name[i] <= 90)
            first_name[i] += 32;
        if (first_name[i] < 65 || first_name[i] > 90 && first_name[i] < 97 || first_name[i] > 122){
            first_name[i] = 96;
        }
    }
    getline(cin, name);
    if (name[0] == 27){
        system("clear");
        return;
    }    
    for (int i = 0; i < name.length(); i++){
        if (name[0] >= 97 && name[0] <= 122){
            name[0] -= 32;
            i++;
        }
        if (name[i] >= 65 && name[i] <= 90)
            name[i] += 32;
        if (name[i] < 65 || name[i] > 90 && name[i] < 97 || name[i] > 122){
            name[i] = 96;
        }
    }
    getline(cin, second_name);
    if (second_name[0] == 27){
        system("clear");
        return;
    }    
    for (int i = 0; i < second_name.length(); i++){
        if (second_name[0] >= 97 && second_name[0] <= 122){
            second_name[0] -= 32;
            i++;
        }
        if (second_name[i] >= 65 && second_name[i] <= 90)
            second_name[i] += 32;
        if (second_name[i] < 65 || second_name[i] > 90 && second_name[i] < 97 || second_name[i] > 122){
            second_name[i] = 96;
        }
    }
    cout << endl << "Дата рождения(ДД.ММ.ГГГГ): " << endl;
    cout << "День: ";
    cin >> birthday;
    if (birthday > 31 || birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> birthday;
    }
    cout << "Месяц: ";
    cin >> month_of_birthday;
    if (month_of_birthday > 12 || month_of_birthday < 1){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> month_of_birthday;
    }
    cout << "Год: ";
    cin >> year_of_birthday;
    if (year_of_birthday > 2018 || year_of_birthday < 1950){
        cout << "Вы ввели неверные данные, повторите ввод: ";
        cin >> year_of_birthday;
    }
    cout << endl << "Пол(М(1)-Мужской, F-Женский): ";
    cin.get();
    getline(cin, sex);
    if (sex[0] == 27){
        system("clear");
        return;
    }    
    if (sex != "m" && sex != "M" && sex != "f" && sex != "F" && sex != "1"){
        sex = "f";
    }
    else if (sex == "1")
        sex = "m";
    cout << endl << "Возраст: ";
    cin >> age;
    cout << endl << "Телефонный номер: ";
    cin.get();
    cin >> phone_number;
    cout << endl << "Адрес(Все неверные символы будут заменены на символ '): ";
    cin.get();
    getline(cin, address);
    if (address[0] == 27){
        system("clear");
        return;
    }    
    for (int i = 0; i < address.length(); i++){
        if (address[0] >= 97 && address[0] <= 122){
            address[0] -= 32;
            i++;
        }
        if (address[i] < 65 || address[i] > 90 && address[i] < 97 || address[i] > 122){
            address[i] = 96;
        }
    }
    cout << endl;
    humans.push_back(new Visitor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address));
    system("clear");
}

void addInfoAboutTrain(vector<Train*> &trains, int& cnt_of_tr){
    int id_train = cnt_of_tr;
    string usefull = "Yes";
    trains.push_back(new Train(id_train, usefull));
    system("clear");
}

//Функции удаления объекта из вектора объектов
void delHumanObj(vector<Human*> &humans){
    int t = 0;
    if (humans.size() == 0){
        cout << "Нет ни одного ID, доступного для удаления." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "ID данных, доступных для удаления:" << endl;
        for (int i = 0; i < humans.size(); i++){
            cout << humans[i]->getId() << " - " << humans[i]->getType() << endl;
        }
        cout << "Введите ID для удаления данных: ";
        int id_for_del;
        cin >> id_for_del;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getId() == id_for_del){
                humans.erase(humans.begin() + i);
                t = 1;
                break;
            }
        }
        if (t)
            cout << "Данные с таким ID удалены." << endl << endl;
        else
            cout << "Данных с таким ID не существует." << endl << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void delTrainObj(vector<Train*> &trains){
    int t = 0;
    if (trains.size() == 0){
        cout << "Нет ни одного ID, доступного для удаления." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "ID данных, доступных для удаления:" << endl;
        for (int i = 0; i < trains.size(); i++){
            cout << trains[i]->getId() << endl;
        }
        cout << "Введите ID для удаления данных: ";
        int id_for_del;
        cin >> id_for_del;
        for (int i = 0; i < trains.size(); i++){
            if (trains[i]->getId() == id_for_del){
                trains.erase(trains.begin() + i);
                t = 1;
                break;
            }
        }
        if (t)
            cout << "Данные с таким ID удалены." << endl;
        else
            cout << "Данных с таким ID не существует." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

//Изменение информации об объекте
void changeInfoAboutHuman(vector<Human*> &humans){
    if (humans.size() == 0){
        cout << "Нет данных, доступных для изменения." << endl;
        getchar();
        cout << "Продолжить..." << endl;
        getchar();
        system("clear");
    }
    else{
        cout << "ID данных, доступных для изменения:" << endl;
        for (int i = 0; i < humans.size(); i++){
            cout << humans[i]->getId() << " - "<< humans[i]->getType() << endl;
        }
        cout << "Введите ID для изменения данных: ";
        int id_for_change;
        cin >> id_for_change;
        char ch;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getId() == id_for_change){
                cout << "Хотите изменить возраст?(y-да или n-нет): ";
                cin >> ch;
                if (ch == 'y'){
                    cout << "Введите новый возраст: ";
                    int age;
                    cin >> age;
                    humans[i]->setAge(age);
                }
                cout << "Хотите изменить телефонный номер?(y-да или n-нет): ";
                cin >> ch;
                if (ch == 'y'){
                    cout << "Введите новый телефонный номер: ";
                    string phone_number;
                    cin >> phone_number;
                    humans[i]->setPhoneNumber(phone_number);
                }
                cout << "Хотите изменить адрес?(y-да или n-нет): ";
                cin >> ch;
                if (ch == 'y'){
                    cout << "Введите новый Адрес(Все неверные символы будут заменены на символ '): ";
                    string address;
                    cin.get();
                    getline(cin, address);
                    for (int i = 0; i < address.length(); i++){
                        if (address[0] >= 97 && address[0] <= 122){
                            address[0] -= 32;
                            i++;
                        }
                        if (address[i] < 65 || address[i] > 90 && address[i] < 97 || address[i] > 122){
                            address[i] = 96;
                        }
                    }
                    humans[i]->setAddress(address);
                }
                if (humans[i]->getType() == "Administrator" || humans[i]->getType() == "Instructor"){
                    cout << "Хотите изменить зарплату?(y-да или n-нет): ";
                    cin >> ch;
                    if (ch == 'y'){
                        cout << "Введите новую зарплату: ";
                        int salary;
                        cin >> salary;
                        humans[i]->setSalary(salary);
                    }
                }
                break;
            }
        }
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void changeInfoAboutTrain(vector<Train*> &trains){
    if (trains.size() == 0){
        cout << "Нет данных, доступных для изменения." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "ID данных, доступных для изменения: " << endl;
        for (int i = 0; i < trains.size(); i++){
            cout << trains[i]->getId() << endl;
        }
        cout << "Введите ID для изменения данных: ";
        int id_for_change;
        cin >> id_for_change;
        char ch;
        for (int i = 0; i < trains.size(); i++){
            cout << "Хотите изменить данные об исправности?(y-да или n-нет): ";
            cin >> ch;
            if (ch == 'y'){
                cout << "Введите новые данные об исправности(Yes-работает, No-не работает): ";
                string usefull;
                cin.get();
                getline(cin, usefull);
                trains[i]->setUsefull(usefull);
                break;
            }
        }
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

//Поиск информации
void showAllInfo(vector<Human*> &humans, vector<Train*> &trains){
    if (humans.size() == 0)
        cout << "Нет информации о людях." << endl;
    else
        cout << "Информация о людях:" << endl;
    for (int i = 0; i < humans.size(); i++){
        humans[i]->showInfo();
        cout << endl;
    }
    if (trains.size() == 0)
        cout << "Нет информации о тренажерах." << endl;
    else
        cout << "Информация о тренажерах:" << endl;
    for (int i = 0; i < trains.size(); i++){
        trains[i]->showInfo();
        cout << endl;
    }
    getchar();
    cout << "Продолжить...";
    getchar();
    system("clear");
}

void searchInfoByFirstName(vector<Human*> &humans){
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Введите фамилию для поиска данных о человеке: ";
        string first_name;
        cin.get();
        getline(cin, first_name);
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getFirstName() == first_name){
                humans[i]->showInfo();
            }
        }
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchInfoByIdHuman(vector<Human*> &humans){
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Доступные ID для поиска информации: " << endl;
        for (int i = 0; i < humans.size(); i++){
            cout << humans[i]->getId() << endl;
        }
        cout << "Введите ID для поиска информации о человеке: ";
        int id_for_search;
        cin >> id_for_search;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getId() == id_for_search){
                humans[i]->showInfo();
                break;
            }
        }
        getchar();
        cout << "Продолжить..." << endl;
        getchar();
        system("clear");
    }
}

void searchInfoByIdTrain(vector<Train*> &trains){
    if (trains.size() == 0){
        cout << "Нет информации о тренажёрах." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Доступные ID для поиска информации: " << endl;
        for (int i = 0; i < trains.size(); i++){
            cout << trains[i]->getId() << endl;
        }
        cout << "Введите ID для поиска информации о тренажёре: ";
        int id_for_search;
        cin >> id_for_search;
        for (int i = 0; i < trains.size(); i++){
            if (trains[i]->getId() == id_for_search){
                trains[i]->showInfo();
                break;
            }
        }
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchInfoBySalaryMore(vector<Human*> &humans){
    int cnt = 0;
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Введите размер зарплаты: ";
        int64_t salary;
        cin >> salary;
        cout << "Информация о сотрудниках:" << endl;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getSalary() >= salary){
                humans[i]->showInfo();
                cnt++;
            }
        }
        if (cnt == 0)
            cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchInfoBySalaryLess(vector<Human*> &humans){
    int cnt = 0;
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Введите размер зарплаты: ";
        int64_t salary;
        cin >> salary;
        cout << "Информация о сотрудниках:" << endl;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getSalary() <= salary){
                humans[i]->showInfo();
                cnt++;
            }
        }
        if (cnt == 0)
            cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchInfoByAgeMore(vector<Human*> &humans){
    int cnt = 0;
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Введите возраст: ";
        int age;
        cin >> age;
        cout << "Информация о сотрудниках: " << endl;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getAge() >= age){
                humans[i]->showInfo();
                cnt++;
            }
        }
        if (cnt == 0)
            cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchInfoByAgeLess(vector<Human*> &humans){
    int cnt = 0;
    if (humans.size() == 0){
        cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Введите возраст: ";
        int age;
        cin >> age;
        cout << "Информация о сотрудниках: " << endl;
        for (int i = 0; i < humans.size(); i++){
            if (humans[i]->getAge() <= age){
                humans[i]->showInfo();
                cnt++;
            }
        }
        if (cnt == 0)
            cout << "Нет информации о людях." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchUsefullTrain(vector<Train*> &trains){
    if (trains.size() == 0){
        cout << "Нет информации о тренажёрах." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Исправные тренажёры:" << endl;
        for (int i = 0; i < trains.size(); i++){
            if (trains[i]->getUsefull() == "Yes"){
                trains[i]->showInfo();
            }
        }
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

void searchUselessTrain(vector<Train*> &trains){
    if (trains.size() == 0){
        cout << "Нет информации о тренажёрах." << endl;
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
    else{
        cout << "Исправные тренажёры:" << endl;
        for (int i = 0; i < trains.size(); i++){
            if (trains[i]->getUsefull() == "No"){
                trains[i]->showInfo();
            }
        }
        getchar();
        cout << "Продолжить...";
        getchar();
        system("clear");
    }
}

//Работа с файлами
void writeInfoInFile(vector<Human*> &humans){
    for (int i = humans.size() - 1; i < humans.size(); i++){
        if (humans[i]->getType() == "Administrator"){
            ofstream fout("admin.txt", ios_base::app);
            fout << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl << humans[i]->getSalary() << endl;
            fout.close();
        }
        else if (humans[i]->getType() == "Instructor"){
            ofstream fout("instruct.txt", ios_base::app);
            fout << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl << humans[i]->getSalary() << endl;
            fout.close();
        }
        else if (humans[i]->getType() == "Visitor"){
            ofstream fout("visit.txt", ios_base::app);
            fout << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl;
            fout.close();
        }
    }
}

void writeInf(vector<Train*> &trains){
    for (int i = trains.size() - 1; i < trains.size(); i++){
        ofstream fout("train.txt", ios_base::app);
        fout << trains[i]->getId() << endl << trains[i]->getUsefull() << endl;
        fout.close();
    }
}

void readInfoFromFileAboutHumans(vector<Human*> &humans, int &count_of_adm, int &count_of_ins, int &count_of_vis, int& all_count){
    int id = 0;
    int64_t salary = 0;
    string first_name;
    string name;
    string second_name;
    int birthday;
    int month_of_birthday;
    int year_of_birthday;
    string sex;
    int age;
    string phone_number;
    string address;
    fstream file("admin.txt");
    ifstream fin("admin.txt");
    while(!fin.eof()){
            fin >> id;
            fin >> first_name;
            fin >> name;
            fin >> second_name;
            fin >> birthday;
            fin >> month_of_birthday;
            fin >> year_of_birthday;
            fin >> sex;
            fin >> age;
            fin >> phone_number;
            fin >> address;
            fin >> salary;
            humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
            count_of_adm++;
            all_count++;
        }
    if (humans.size() != 0)
        humans.erase(humans.end() - 1);
    fin.close();
    file.close();
    ifstream fin1("instruct.txt");
    fstream file1("instruct.txt");
    while (!fin1.eof()){
        fin1 >> id;
        fin1 >> first_name;
        fin1 >> name;
        fin1 >> second_name;
        fin1 >> birthday;
        fin1 >> month_of_birthday;
        fin1 >> year_of_birthday;
        fin1 >> sex;
        fin1 >> age;
        fin1 >> phone_number;
        fin1 >> address;
        fin1 >> salary ;
        humans.push_back(new Instructor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
        count_of_ins++;
        all_count++;
    }
    if (humans.size() != 0)
        humans.erase(humans.end() - 1);
    fin1.close();
    file1.close();
    ifstream fin2("visit.txt");
    fstream file2("visit.txt");
    while (!fin2.eof()){
        fin2 >> id;
        fin2 >> first_name;
        fin2 >> name;
        fin2 >> second_name;
        fin2 >> birthday;
        fin2 >> month_of_birthday;
        fin2 >> year_of_birthday;
        fin2 >> sex;
        fin2 >> age;
        fin2 >> phone_number;
        fin2 >> address;
        humans.push_back(new Visitor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address));
        count_of_vis++;
        all_count++;
    }
    if (humans.size() != 0)
        humans.erase(humans.end() - 1);
    fin2.close();
    file2.close();
}

void readInfoFromFileAboutTrains(vector<Train*> &trains, int& count_of_train, int& cnt_of_tr){
    fstream file3("train.txt");
    ifstream fin3("train.txt");
    string usefull;
    int id_train = 0;
    if (file3.peek() != EOF)
        while (!fin3.eof()){
            fin3 >> id_train;
            fin3 >> usefull;
            trains.push_back(new Train(id_train, usefull));
            count_of_train++;
            cnt_of_tr++;
        }
    if (trains.size() != 0)
        trains.erase(trains.end() - 1);
    file3.close();
    fin3.close();
}

void reWriteInfoInFile(vector<Train*>& trains, vector<Human*>& humans){
    ofstream fout("admin.txt");
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getType() == "Administrator")
            fout << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl << humans[i]->getSalary() << endl;
    }
    fout.close();

    ofstream fout1("instruct.txt");
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getType() == "Instructor")
            fout1 << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl << humans[i]->getSalary() << endl;
    }
    fout1.close();

    ofstream fout2("visit.txt");
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getType() == "Visitor")
            fout2 << humans[i]->getId() << endl << humans[i]->getFirstName() << endl << humans[i]->getName() << endl
            << humans[i]->getSecondName() << endl << humans[i]->getBirthday() << endl << humans[i]->getMonth() << endl
            << humans[i]->getYear() << endl << humans[i]->getSex() << endl << humans[i]->getAge() << endl
            << humans[i]->getPhone() << endl << humans[i]->getAdr() << endl;
    }
    fout2.close();
    ofstream fout3("train.txt");
    for (int i = trains.size() - 1; i < trains.size(); i++){
         fout3 << trains[i]->getId() << endl << trains[i]->getUsefull() << endl;
    }
    fout3.close();
}

#endif