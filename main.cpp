#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "func.h"
#include "classes.h"

using namespace std;

int main()
{
    //Кол-во объектов определенного класса
    int count_of_adm = 0;
    int count_of_ins = 0;
    int count_of_vis = 0;
    int count_of_train = 0;
    int cnt_of_tr = 1;
    int all_count = 1;
    vector <Human*> humans;
    vector <Train*> trains;
    readInfoFromFileAboutHumans(humans, count_of_adm, count_of_ins, count_of_vis, all_count);
    readInfoFromFileAboutTrains(trains, count_of_train, cnt_of_tr);
    while (true){
        cout << "================================================" << endl;
        cout << "| 1) Добавление информации в базу данных.      |" << endl;
        cout << "| 2) Удаление информации из базы данных.       |" << endl;
        cout << "| 3) Редактирование информации в базе данных.  |" << endl;
        cout << "| 4) Поиск информации по заданным критериям.   |" << endl;
        cout << "------------------------------------------------";
        cout << endl << "| 0) Выход.                                    |" << endl;
        cout << "================================================";
        cout << endl << "Введите команду... ";
        char numb;
        cin >> numb;
        system("clear");
        switch (numb){
            case '1':{
                    while (true){
                        cout << "================================================================" << endl;
                        cout << "| 1) Добавить информацию об администраторе в базу данных.      |" << endl;
                        cout << "| 2) Добавить информацию об инструкторе в базу данных.         |" << endl;
                        cout << "| 3) Добавить информацию о посетителе в базу данных.           |" << endl;
                        cout << "| 4) Добавить информацию о тренажере в базу данных.            |" << endl;
                        cout << "----------------------------------------------------------------";
                        cout << endl << "| 0) Вернуться назад.                                          |" << endl;
                        cout << "================================================================";
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
                                    addInfoAboutAdmin(humans, all_count);
                                    writeInfoInFile(humans);
                                }
                                count_of_adm++;
                                all_count++;
                                break;
                            case '2':
                                //Добавление объекта Инструктор
                                for (int i = count_of_ins; i < count_of_ins + 1; i++){
                                    addInfoAboutIns(humans, all_count);
                                    writeInfoInFile(humans);
                                }
                                all_count++;
                                count_of_ins++;
                                break;
                            case '3':
                                //Добавление объекта
                                for (int i = count_of_vis; i < count_of_vis + 1; i++){
                                    addInfoAboutVis(humans, all_count);
                                    writeInfoInFile(humans);
                                }
                                all_count++;
                                count_of_vis++;
                                break;
                            case '4':
                                for (int i = count_of_train; i < count_of_train + 1; i++){
                                    addInfoAboutTrain(trains, cnt_of_tr);
                                    writeInf(trains);
                                }
                                cnt_of_tr++;
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
                        cout << "==========================================" << endl;
                        cout << "| 1) Удаление информации о человеке.     |" << endl;
                        cout << "| 2) Удаление информации о тренажёре.    |" << endl;
                        cout << "------------------------------------------";
                        cout << endl << "| 0) Вернуться назад.                    |" << endl;
                        cout << "==========================================";
                        cout << endl << "Введите команду... ";
                        char case2_numb;
                        cin >> case2_numb;
                        system("clear");
                        if (case2_numb == '0')
                            break;
                        switch (case2_numb){
                            case '1':
                                delHumanObj(humans);
                                reWriteInfoInFile(trains, humans);
                                break;
                            case '2':
                                delTrainObj(trains);
                                reWriteInfoInFile(trains, humans);
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
                        cout << "==========================================" << endl;
                        cout << "| 1) Изменить информацию о человеке.     |" << endl;
                        cout << "| 2) Изменить информацию о тренажёре.    |" << endl;
                        cout << "------------------------------------------";
                        cout << endl << "| 0) Вернуться назад.                    |" << endl;
                        cout << "==========================================";
                        cout << endl << "Введите команду... ";
                        char case3_numb;
                        cin >> case3_numb;
                        system("clear");
                        if (case3_numb == '0')
                            break;
                        switch (case3_numb){
                            case '1':
                                changeInfoAboutHuman(humans);
                                reWriteInfoInFile(trains, humans);
                                break;
                            case '2':
                                changeInfoAboutTrain(trains);
                                reWriteInfoInFile(trains, humans);
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
                    cout << "=======================================================" << endl;
                    cout << "| 1) Вывести всю информацию о людях и тренажёрах.     |" << endl;
                    cout << "| 2) Поиск информации о человеке по фамилии.          |" << endl;
                    cout << "| 3) Поиск информации по ID.                          |" << endl;
                    cout << "| 4) Поиск информации о сотруднике по зарплате.       |" << endl;
                    cout << "| 5) Поиск информации о человеке по возрасту.         |" << endl;
                    cout << "| 6) Поиск информации о тренажёре.                    |" << endl;
                    cout << "-------------------------------------------------------";
                    cout << endl << "| 0) Вернуться назад.                                 |" << endl;
                    cout << "=======================================================";
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
                                cout << "==========================================" << endl;
                                cout << "| 1) Поиск по ID информации о человеке.  |" << endl;
                                cout << "| 2) Поиск по ID информации о тренжёре.  |" << endl;
                                cout << "------------------------------------------";
                                cout << endl << "| 0) Вернуться назад.                    |" << endl;
                                cout << "==========================================";
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
                                cout << "======================================================" << endl;
                                cout << "| 1) Поиск по зарплате, которая больше введенной.    |" << endl;
                                cout << "| 2) Поиск по зарплате, которая меньше введенной.    |" << endl;
                                cout << "------------------------------------------------------";
                                cout << endl << "| 0) Вернуться назад.                                |" << endl;
                                cout << "======================================================";
                                cout << endl << "Введите команду...";
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
                                cout << "======================================================" << endl;
                                cout << "| 1) Поиск по возрасту, который больше введенного.   |" << endl;
                                cout << "| 2) Поиск по возрасту, который меньше введенного.   |" << endl;
                                cout << "------------------------------------------------------";
                                cout << endl << "| 0) Вернуться назад.                                |" << endl;
                                cout << "======================================================";
                                cout << endl << "Введите команду...";
                                char case_numb;
                                cin >> case_numb;
                                system("clear");
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
                                cout << "====================================================" << endl;
                                cout << "| 1) Поиск информации о исправных тренажёрах.      |" << endl;
                                cout << "| 2) Поиск информации о неисправных тренажёрах.    |" << endl;
                                cout << "----------------------------------------------------";
                                cout << endl << "| 0) Вернуться назад.                              |" << endl;
                                cout << "====================================================";
                                cout << endl << "Введите команду...";
                                char case_numb;
                                cin >> case_numb;
                                system("clear");
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
