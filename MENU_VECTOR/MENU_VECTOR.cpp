#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm>

using namespace std;

void displayMenu() {
    cout << "1 -> Изменить размер вектора\n"
        << "2 -> Добавить элемент в конец\n"
        << "3 -> Удалить элемент в конце\n"
        << "4 -> Отсортировать массив от меньшего к большему\n"
        << "5 -> Отсортировать массив от большего к меньшему\n"
        << "6 -> Вывести вектор\n"
        << "7 -> Добавить элементы в вектор\n"
        << "8 -> Очистить вектор\n"
        << "9 -> Записать вектор в файл\n"
        << "10 -> Очистить файл\n"
        << "11 -> Вывести данные файла\n"
        << "12 -> Открыть файл с данными\n"
        << "13 -> Вывести исходный вектор\n"
        << "14 -> Оставить только четные числа\n"
        << "15 -> Оставить только нечетные числа\n"
        << "0 -> Для выхода\n";
}

void resizeVector(int newSize, vector<int>& vec) {
    if (newSize <= 0) {
        cerr << "Размер слишком мал\n";
        return;
    }
    vec.resize(newSize);
    cout << "Размер изменен успешно!\n";
}

void sortAscending(vector<int>& vec) {
    if (vec.empty()) {
        cerr << "Массив пуст\n";
        return;
    }
    sort(vec.begin(), vec.end());
    cout << "Отсортирован успешно!\n";
}

void sortDescending(vector<int>& vec) {
    if (vec.empty()) {
        cerr << "Массив пуст\n";
        return;
    }
    sort(vec.rbegin(), vec.rend());
    cout << "Отсортирован успешно!\n";
}

void filterEvenNumbers(const vector<int>& vec) {
    for (int num : vec) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    }
    cout << endl;
}

void filterOddNumbers(const vector<int>& vec) {
    for (int num : vec) {
        if (num % 2 != 0) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    ofstream file("Vector.txt", ofstream::app);
    ifstream ifile("Vector.txt");
    string save;
    int size, choice, num;

    cout << "Введите размер вектора: ";
    cin >> size;
    if (size < 0 )
    {
        cerr << "Неверный размер\n";
        return -1;
    }
    vector<int> vec(size);
    vector<int> originalVec(vec);

    displayMenu();

    while (cin >> choice && choice != 0) {
        switch (choice) {
        case 1:
            cout << "Введите новый размер вектора: ";
            cin >> size;
            if (size < 0)
            {
                cerr << "Неверный размер\n";
                return -1;
            }
            resizeVector(size, vec);
            resizeVector(size, originalVec);
            break;
        case 2:
            cout << "Введите элемент для добавления: ";
            cin >> num;
            vec.push_back(num);
            originalVec.push_back(num);
            cout << "Элемент добавлен!\n";
            break;
        case 3:
            if (!vec.empty()) {
                vec.pop_back();
                originalVec.pop_back();
                cout << "Элемент удален успешно!\n";
            }
            else {
                cout << "Вектор пуст!\n";
            }
            break;
        case 4:
            sortAscending(vec);
            break;
        case 5:
            sortDescending(vec);
            break;
        case 6:
            for (int num : vec) {
                cout << "[" << num << "] ";
            }
            cout << endl;
            break;
        case 7:
            cout << "Вводите элементы, нажимая Enter после каждого:\n";
            for (int& num : vec) {
                cin >> num;
            }
            originalVec = vec;
            break;
        case 8:
            vec.clear();
            cout << "Вектор очищен!\n";
            break;
        case 9:
            for (int num : vec) {
                file << num << " ";
            }
            cout << "Записано в файл успешно!\n";
            break;
        case 10:
            file.close();
            file.open("Vector.txt", ofstream::trunc);
            cout << "Файл очищен!\n";
            break;
        case 11:
            while (getline(ifile, save)) {
                cout << save << " ";
            }
            cout << endl;
            break;
        case 12:
            system("start Vector.txt");
            break;
        case 13:
            for (int num : originalVec) {
                cout << num << " ";
            }
            cout << endl;
            break;
        case 14:
            filterEvenNumbers(vec);
            break;
        case 15:
            filterOddNumbers(vec);
            break;
        default:
            cout << "Неверный выбор!\n";
            break;
        }
        displayMenu();
    }

    file.close();
    return 0;
}
