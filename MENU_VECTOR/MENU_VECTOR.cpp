#include <iostream>
#include "VectorManager.h"

// version 3.0 Много багов просьба не ломать прогу в добавлением элементов не добавляйте буквы и типы по типу double

int main() {
    std::system("color a");
    setlocale(LC_ALL, "RU");

    int size = 0, choice = 0, num = 0, index = 0, target = 0;
    string save = " ";
    ofstream file("Vector.txt", ofstream::app);
    ifstream ifile("Vector.txt");
    std::cout << "Введите размер вектора: ";
    std::cin >> size;

    if (size < 0) {
        std::cerr << "Неверный размер\n";
        return -1;
    }

    VectorManager vm(size);  
    vm.displayMenu();        

    while (std::cin >> choice && choice != 0) {
        switch (choice) {
        case 1:
            std::cout << "Введите новый размер вектора: ";
            std::cin >> size;
            vm.resize(size);
            break;
        case 2:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> num;
            vm.addElement(num);
            break;
        case 3:
            vm.removeElement();
            break;
        case 4:
            vm.sortAscending();
            break;
        case 5:
            vm.sortDescending();
            break;
        case 6:
            vm.displayVector();
            break;
        case 7:
            vm.clear();
            break;
        case 8:
            vm.saveToFile("Vector.txt");
            break;
        case 9:
            vm.loadFromFile("Vector.txt");
            break;
        case 10:
            vm.filterEven();
            break;
        case 11:
            vm.filterOdd();
            break;
        case 12:
            std::cout << "Введите число для удаления: ";
            std::cin >> num;
            vm.eraseElement(num);
            break;
        case 13:
            std::cout << "Введите число для вставки: ";
            std::cin >> num;
            std::cout << "Введите индекс: ";
            std::cin >> index;
            vm.insertElement(num, index);
            break;
        case 14:
            vm.deleteDuplicates();
            break;
        case 15:
            vm.AddElementVec();
            break;
        case 16:
            vm.clearFile(file);
            break;
        case 18:
            vm.DisplayFile(ifile, save);
            break;
        case 19:
            vm.OpenFileData();
            break;
        case 20:
            std::cout << "Введите число для поиска: ";
            std::cin >> target;
            int indexFound = vm.binarySearch(target);
            if (indexFound != -1) {
                std::cout << "Число найдено на индексе: " << indexFound << std::endl;
            }
            break;
        
        }
        vm.displayMenu();  
    }

    return 0;
}
