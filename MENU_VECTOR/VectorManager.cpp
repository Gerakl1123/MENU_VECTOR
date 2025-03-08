#include "VectorManager.h"

VectorManager::VectorManager(int size)
{
	vec.resize(size);
}

void VectorManager::displayMenu() const
{
    std::cout << "1 -> Изменить размер вектора\n"
        << "2 -> Добавить элемент в конец\n"
        << "3 -> Удалить элемент в конце\n"
        << "4 -> Отсортировать массив от меньшего к большему\n"
        << "5 -> Отсортировать массив от большего к меньшему\n"
        << "6 -> Вывести вектор\n"
        << "7 -> Очистить вектор\n"
        << "8 -> Записать вектор в файл\n"
        << "9 -> Загрузить данные из файла\n"
        << "10 -> Оставить только четные числа\n"
        << "11 -> Оставить только нечетные числа\n"
        << "12 -> Удалить элемент\n"
        << "13 -> Вставить элемент по индексу\n"
        << "14 -> Удалить дубликаты чисел\n"
        << "15 -> Добавить элеменеты\n"
        << "17 -> Найти число\n"
        << "18 -> Вывести числа с файла\n"
        << "19 -> Открыть файл\n"
        << "20 -> Очистить файл\n"
        << "0 -> Для выхода\n";
}

void VectorManager::resize(int newSize) {
    if (newSize <= 0) {
        std::cerr << "Размер слишком мал\n";
    }
    else {
        vec.resize(newSize);
        std::cout << "Размер изменен успешно!\n";
    }
}

void VectorManager::addElement(int num) {
    vec.push_back(num);
    std::cout << "Элемент добавлен!\n";
}

void VectorManager::removeElement() {
    if (!vec.empty()) {
        vec.pop_back();
        std::cout << "Элемент удален успешно!\n";
    }
    else {
        std::cout << "Вектор пуст!\n";
    }
}

void VectorManager::sortAscending() {
    if (vec.empty()) {
        std::cerr << "Вектор пуст\n";
        return;
    }
    std::sort(vec.begin(), vec.end());
    std::cout << "Отсортирован успешно!\n";
}

void VectorManager::sortDescending() {
    if (vec.empty()) {
        std::cerr << "Вектор пуст\n";
        return;
    }
    std::sort(vec.rbegin(), vec.rend());
    std::cout << "Отсортирован успешно!\n";
}

void VectorManager::displayVector() const {
    for (const auto& num : vec) {
        std::cout << "[" << num << "] ";
    }
    std::cout << std::endl;
}

void VectorManager::clear() {
    vec.clear();
    std::cout << "Вектор очищен!\n";
}

void VectorManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ofstream::trunc);
    for (int num : vec) {
        file << num << " ";
    }
    std::cout << "Записано в файл успешно!\n";
}

void VectorManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int num;
    vec.clear();
    while (file >> num) {
        vec.push_back(num);
    }
    std::cout << "Данные загружены из файла успешно!\n";
}

void VectorManager::filterEven() const {
    for (int num : vec) {
        if (num % 2 == 0) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

void VectorManager::filterOdd() const {
    for (int num : vec) {
        if (num % 2 != 0) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

void VectorManager::eraseElement(int num) {
    auto it = std::remove(vec.begin(), vec.end(), num);
    if (it != vec.end()) {
        vec.erase(it, vec.end());
        std::cout << "Число " << num << " удалено.\n";
    }
    else {
        std::cerr << "Число не найдено\n";
    }
}

void VectorManager::insertElement(int num, int index) {
    if (index >= 0 && index <= vec.size()) {
        vec.insert(vec.begin() + index, num);
    }
    else
    {
        cerr << "Такого индека не существует\n";
    }
}

void VectorManager::deleteDuplicates()
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        auto it2 = it + 1;

        while (it2 != vec.end())
        {
            if (*it == *it2)
            {
                it2 = vec.erase(it2);
            }
            else
            {
                ++it2;
            }

        }
    }

}

void VectorManager::insertRange(const vector<int>& orgvec)
{

    auto* p = &vec;
    auto* p2 = &orgvec;
    //fix
   // vector<int>::iterator it = vec.begin();

    p->insert(p->begin(), p2->begin(), p2->end());
}

int VectorManager::binarySearch(const int& target) const
{
    auto* ptrVec = &vec;
    int low = 0;
    int high = ptrVec->size();

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int temp = vec[mid];

        if (temp == target)
        {
            return mid;
        }
        if (temp > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        return false;
    }

}

void VectorManager::AddElementVec() 
{
    cout << "Вводите элементы, нажимая Enter после каждого:\n";
    for (int& num : vec) {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Не цифра\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           
        }
        
    }
}

void VectorManager::clearFile(ofstream& file)
{
    file.close();
    file.open("Vector.txt", ofstream::trunc);
    cout << "Файл очищен!\n";
}

void VectorManager::DisplayFile(ifstream& ifile,string& save) const
{
    while (getline(ifile, save)) {
        cout << save << " ";
    }
    cout << endl;
}

void VectorManager::OpenFileData() const
{
    system("start Vector.txt");

}


