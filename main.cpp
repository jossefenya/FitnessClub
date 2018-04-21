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
        cout << "Должность: Администратор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
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
        cout << "Должность: Инструктор" << endl;
        Human::showInfo();
        cout << "Зарплата: " << salary << endl;
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
        cout << "Посетитель" << endl;
        Human::showInfo();
    }

    string getType(){return type;}
};


//Класс Тренажер
class Train{
private:
    int id_train;
    string type = "Train";
    string usefull = "Yes";
public:
    Train(){}

    Train(int id_train1){
        id_train = id_train1;
    }

    ~Train(){}

    virtual void showInfo(){
        cout << "Тип: Тренажёр" << endl;
        cout << "ID тренажёра: " << id_train << endl;
        cout << "Исправность: " << usefull << endl;
    }

    virtual string getType(){return type;}

    virtual int getId(){return id_train;}

    virtual string getUsefull(){return usefull;}

    virtual void setUsefull(string usefull1){usefull = usefull1;}
};

//Функции добавления объекта в вектор объектов
void addInfoAboutAdmin(vector<Human*> &humans){
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
    cout << endl;
    cout << "Зарплата: ";
    cin >> salary;
    humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    system("clear");
}

void addInfoAboutIns(vector<Human*> &humans){
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
    cout << "ID Инструктора: ";
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
    humans.push_back(new Instructor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
    system("clear");
}

void addInfoAboutVis(vector<Human*> &humans){
    int id = 0;
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
    cout << "ID Посетителя: ";
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
    cout << endl;
    humans.push_back(new Visitor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address));
    system("clear");
}

void addInfoAboutTrain(vector<Train*> &trains){
    int id_train = 0;
    string usefull;
    cout << "Введите данные" << endl;
    cout << "ID тренажёра: ";
    cin >> id_train;
    trains.push_back(new Train(id_train));
    system("clear");
}

//Функции удаления объекта из вектора объектов
void delHumanObj(vector<Human*> &humans){
    int t = 0;
    cout << "ID данных, доступных для удаления:" << endl;
    for (int i = 0; i < humans.size(); i++){
        cout << humans[i]->getId() << endl;
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
        cout << "Данные с таким ID удалены." << endl;
    else
        cout << "Данных с таким ID не существует." << endl;
}

void delTrainObj(vector<Train*> &trains){
    int t = 0;
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
}

//Изменение информации об объекте
void changeInfoAboutHuman(vector<Human*> &humans){
    cout << "ID данных, доступных для изменения:" << endl;
    for (int i = 0; i < humans.size(); i++){
        cout << humans[i]->getId() << endl;
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
                int64_t phone_number;
                cin >> phone_number;
                humans[i]->setPhoneNumber(phone_number);
            }
            cout << "Хотите изменить адрес?(y-да или n-нет): ";
            cin >> ch;
            if (ch == 'y'){
                cout << "Введите новый Адрес: ";
                string address;
                cin.get();
                getline(cin, address);
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
    system("clear");
}

void changeInfoAboutTrain(vector<Train*> &trains){
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
            cout << "Введите новые данные об исправности: ";
            string usefull;
            cin.get();
            getline(cin, usefull);
            trains[i]->setUsefull(usefull);
            break;
        }
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
}

void searchInfoByFirstName(vector<Human*> &humans){
    cout << "Введите фамилию для поиска данных о человеке: ";
    string first_name;
    cin.get();
    getline(cin, first_name);
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getFirstName() == first_name){
            humans[i]->showInfo();
        }
    }
}

void searchInfoByIdHuman(vector<Human*> &humans){
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
}

void searchInfoByIdTrain(vector<Train*> &trains){
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
}

void searchInfoBySalaryMore(vector<Human*> &humans){
    cout << "Введите размер зарплаты: ";
    int64_t salary;
    cin >> salary;
    cout << "Информация о сотрудниках:" << endl;
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getSalary() >= salary){
            humans[i]->showInfo();
        }
    }
}

void searchInfoBySalaryLess(vector<Human*> &humans){
    cout << "Введите размер зарплаты: ";
    int64_t salary;
    cin >> salary;
    cout << "Информация о сотрудниках: " << endl;
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getSalary() <= salary){
            humans[i]->showInfo();
        }
    }
}

void searchInfoByAgeMore(vector<Human*> &humans){
    cout << "Введите возраст: ";
    int age;
    cin >> age;
    cout << "Информация о сотрудниках: " << endl;
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getAge() >= age){
            humans[i]->showInfo();
        }
    }
}

void searchInfoByAgeLess(vector<Human*> &humans){
    cout << "Введите возраст: ";
    int age;
    cin >> age;
    cout << "Информация о сотрудниках: " << endl;
    for (int i = 0; i < humans.size(); i++){
        if (humans[i]->getAge() <= age){
            humans[i]->showInfo();
        }
    }
}

void searchUsefullTrain(vector<Train*> &trains){
    cout << "Исправные тренажёры:" << endl;
    for (int i = 0; i < trains.size(); i++){
        if (trains[i]->getUsefull() == "Yes"){
            trains[i]->showInfo();
        }
    }
}

void searchUselessTrain(vector<Train*> &trains){
    cout << "Неисправные тренажёры:" << endl;
    for (int i = 0; i < trains.size(); i++){
        if (trains[i]->getUsefull() == "No"){
            trains[i]->showInfo();
        }
    }
}

//Работа с файлами
void writeInfoInFile(vector<Train*> &trains, vector<Human*> &humans){
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
    ofstream fout("train.txt", ios_base::app);
    for (int i = trains.size() - 1; i < trains.size(); i++){
         fout << endl << trains[i]->getId() << endl << trains[i]->getUsefull() << endl;
    }
    fout.close();
}

void readInfoFromFile(vector<Train*> &trains, vector<Human*> &humans, int &count_of_adm, int &count_of_ins, int &count_of_vis, int &count_of_train){
    /*ifstream fin("admin.txt");
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
    while (!fin.eof()){
        fin.get();
        fin >> id;
        fin.get();
        getline(fin, first_name);
        getline(fin, name);
        getline(fin, second_name);
        fin >> birthday;
        fin >> month_of_birthday;
        fin >> year_of_birthday;
        fin.get();
        getline(fin, sex);
        fin >> age;
        fin >> phone_number;
        fin.get();
        getline(fin, address);
        fin.get();
        fin >> salary;
        humans.push_back(new Administrator(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
        count_of_adm++;
    }
    fin.close();*/
   /* ifstream fin1("instruct.txt");
    while (!fin1.eof()){
        fin1.get();
        fin1 >> id;
        fin1.get();
        getline(fin1, first_name);
        getline(fin1, name);
        getline(fin1, second_name);
        fin1 >> birthday;
        fin1 >> month_of_birthday;
        fin1 >> year_of_birthday;
        fin1.get();
        getline(fin1, sex);
        fin1 >> age;
        fin1 >> phone_number;
        fin1.get();
        getline(fin1, address);
        fin1.get();
        fin1 >> salary;
        humans.push_back(new Instructor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address, salary));
        count_of_ins++;
    }
    fin1.close();
    ifstream fin2("visit.txt");
    while (!fin2.eof()){
        fin2.get();
        fin2 >> id;
        fin2.get();
        getline(fin2, first_name);
        getline(fin2, name);
        getline(fin2, second_name);
        fin2 >> birthday;
        fin2 >> month_of_birthday;
        fin2 >> year_of_birthday;
        fin2.get();
        getline(fin2, sex);
        fin2 >> age;
        fin2 >> phone_number;
        fin2.get();
        getline(fin2, address);
        fin2 >> salary;
        humans.push_back(new Visitor(id, first_name, name, second_name, birthday, month_of_birthday, year_of_birthday, sex, age, phone_number, address));
        count_of_vis++;
    }
    fin2.close();*/
}

int main()
{
    //Кол-во объектов определенного класса
    int count_of_adm = 0;
    int count_of_ins = 0;
    int count_of_vis = 0;
    int count_of_train = 0;
    vector <Human*> humans;
    vector <Train*> trains;
    //readInfoFromFile(trains, humans, count_of_adm, count_of_ins, count_of_vis, count_of_train);
    //cout << humans.size() << endl;
    while (true){
        cout << "1) Добавление информации в базу данных." << endl;
        cout << "2) Удаление информации из базы данных." << endl;
        cout << "3) Редактирование информации в базе данных." << endl;
        cout << "4) Поиск информации по заданным критериям." << endl;
        cout << endl << "0) Выход." << endl;
        cout << endl << "Введите команду... ";
        char numb;
        cin >> numb;
        system("clear");
        switch (numb){
            case '1':{
                    while (true){
                        cout << "1) Добавить информацию об администраторе в базу данных." << endl;
                        cout << "2) Добавить информацию об инструкторе в базу данных." << endl;
                        cout << "3) Добавить информацию о посетителе в базу данных." << endl;
                        cout << "4) Добавить информацию о тренажере в базу данных." << endl;
                        cout << endl << "0) Вернуться назад." << endl;
                        cout << endl << "Введите команду... ";
                        char case1_numb;
                        cin >> case1_numb;
                        system("clear");
                        if (case1_numb == '0')
                            break;
                        switch (case1_numb){
                            case '1':
                                //Добавление объекта Администратор
                                for (int i = count_of_adm; i < count_of_adm + 1; i++){
                                    addInfoAboutAdmin(humans);
                                    writeInfoInFile(trains, humans);
                                }
                                count_of_adm++;
                                break;
                            case '2':
                                //Добавление объекта Инструктор
                                for (int i = count_of_ins; i < count_of_ins + 1; i++){
                                    addInfoAboutIns(humans);
                                    writeInfoInFile(trains, humans);
                                }
                                count_of_ins++;
                                break;
                            case '3':
                                //Добавление объекта
                                for (int i = count_of_vis; i < count_of_vis + 1; i++){
                                    addInfoAboutVis(humans);
                                    writeInfoInFile(trains, humans);
                                }
                                count_of_vis++;
                                break;
                            case '4':
                                for (int i = count_of_train; i < count_of_train + 1; i++){
                                    addInfoAboutTrain(trains);
                                    writeInfoInFile(trains, humans);
                                }
                                count_of_train++;
                                break;
                            default:
                                break;
                        }

                    }
                    break;
                }
            case '2':
                {
                    while (true){
                        cout << "1) Удаление информации о человеке." << endl;
                        cout << "2) Удаление информации о тренажёре." << endl;
                        cout << endl << "0) Вернуться назад." << endl;
                        cout << endl << "Введите команду... ";
                        char case2_numb;
                        cin >> case2_numb;
                        system("clear");
                        if (case2_numb == '0')
                            break;
                        switch (case2_numb){
                            case '1':
                                delHumanObj(humans);
                                break;
                            case '2':
                                delTrainObj(trains);
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case '3':
                {
                    while (true){
                        cout << "1) Изменить информацию о человеке." << endl;
                        cout << "2) Изменить информацию о тренажёре." << endl;
                        cout << endl << "0) Вернуться назад." << endl;
                        cout << endl << "Введите команду... ";
                        char case3_numb;
                        cin >> case3_numb;
                        system("clear");
                        if (case3_numb == '0')
                            break;
                        switch (case3_numb){
                            case '1':
                                changeInfoAboutHuman(humans);
                                break;
                            case '2':
                                changeInfoAboutTrain(trains);
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case '4':
                //Вывод информации
                while (true){
                    cout << "1) Вывести всю информацию о людях и тренажёрах." << endl;
                    cout << "2) Поиск информации о человеке по фамилии." << endl;
                    cout << "3) Поиск информации по ID." << endl;
                    cout << "4) Поиск информации о сотруднике по зарплате." << endl;
                    cout << "5) Поиск информации о человеке по возрасту." << endl;
                    cout << "6) Поиск информации о тренажёре." << endl;
                    cout << endl << "0) Вернуться назад." << endl;
                    cout << endl << "Введите команду... ";
                    char case4_numb;
                    cin >> case4_numb;
                    system("clear");
                    if (case4_numb == '0')
                        break;
                    switch (case4_numb){
                        case '1':
                            showAllInfo(humans, trains);
                            break;
                        case '2':
                            searchInfoByFirstName(humans);
                            break;
                        case '3':
                            while (true){
                                cout << "1) Поиск по ID информации о человеке." << endl;
                                cout << "2) Поиск по ID информации о тренжёре." << endl;
                                cout << endl << "0) Вернуться назад." << endl;
                                cout << endl << "Введите команду... ";
                                char case3_numb;
                                cin >> case3_numb;
                                system("clear");
                                if (case3_numb == '0')
                                    break;
                                switch (case3_numb){
                                    case '1':
                                        searchInfoByIdHuman(humans);
                                        break;
                                    case '2':
                                        searchInfoByIdTrain(trains);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;
                        case '4':
                            while (true){
                                cout << "1) Поиск по зарплате, которая больше введенной." << endl;
                                cout << "2) Поиск по зарплате, которая меньше введенной." << endl;
                                cout << endl << "0) Вернуться назад." << endl;
                                cout << endl << "Введите команду..." << endl;
                                char case_numb;
                                cin >> case_numb;
                                system("clear");
                                if (case_numb == '0')
                                    break;
                                switch (case_numb){
                                    case '1':
                                        searchInfoBySalaryMore(humans);
                                        break;
                                    case '2':
                                        searchInfoBySalaryLess(humans);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;
                        case '5':
                            while (true){
                                cout << "1) Поиск по возрасту, который больше введенного." << endl;
                                cout << "2) Поиск по возрасту, который меньше введенного." << endl;
                                cout << endl << "0) Вернуться назад." << endl;
                                cout << endl << "Введите команду..." << endl;
                                char case_numb;
                                cin >> case_numb;
                                if (case_numb == '0')
                                    break;
                                switch (case_numb){
                                    case '1':
                                        searchInfoByAgeMore(humans);
                                        break;
                                    case '2':
                                        searchInfoByAgeLess(humans);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;
                        case '6':
                            while (true){
                                cout << "1) Поиск информации о исправных тренажёрах." << endl;
                                cout << "2) Поиск информации о неисправных тренажёрах." << endl;
                                cout << endl << "0) Вернуться назад." << endl;
                                cout << endl << "Введите команду..." << endl;
                                char case_numb;
                                cin >> case_numb;
                                if (case_numb == '0')
                                    break;
                                switch (case_numb){
                                    case '1':
                                        searchUsefullTrain(trains);
                                        break;
                                    case '2':
                                        searchUselessTrain(trains);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
            case '0':
                humans.clear();
                trains.clear();
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
