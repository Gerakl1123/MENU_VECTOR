#include "VectorManager.h"

VectorManager::VectorManager(int size)
{
	vec.resize(size);
}

void VectorManager::displayMenu() const
{
    std::cout << "1 -> �������� ������ �������\n"
        << "2 -> �������� ������� � �����\n"
        << "3 -> ������� ������� � �����\n"
        << "4 -> ������������� ������ �� �������� � ��������\n"
        << "5 -> ������������� ������ �� �������� � ��������\n"
        << "6 -> ������� ������\n"
        << "7 -> �������� ������\n"
        << "8 -> �������� ������ � ����\n"
        << "9 -> ��������� ������ �� �����\n"
        << "10 -> �������� ������ ������ �����\n"
        << "11 -> �������� ������ �������� �����\n"
        << "12 -> ������� �������\n"
        << "13 -> �������� ������� �� �������\n"
        << "14 -> ������� ��������� �����\n"
        << "15 -> �������� ���������\n"
        << "17 -> ����� �����\n"
        << "18 -> ������� ����� � �����\n"
        << "19 -> ������� ����\n"
        << "20 -> �������� ����\n"
        << "0 -> ��� ������\n";
}

void VectorManager::resize(int newSize) {
    if (newSize <= 0) {
        std::cerr << "������ ������� ���\n";
    }
    else {
        vec.resize(newSize);
        std::cout << "������ ������� �������!\n";
    }
}

void VectorManager::addElement(int num) {
    vec.push_back(num);
    std::cout << "������� ��������!\n";
}

void VectorManager::removeElement() {
    if (!vec.empty()) {
        vec.pop_back();
        std::cout << "������� ������ �������!\n";
    }
    else {
        std::cout << "������ ����!\n";
    }
}

void VectorManager::sortAscending() {
    if (vec.empty()) {
        std::cerr << "������ ����\n";
        return;
    }
    std::sort(vec.begin(), vec.end());
    std::cout << "������������ �������!\n";
}

void VectorManager::sortDescending() {
    if (vec.empty()) {
        std::cerr << "������ ����\n";
        return;
    }
    std::sort(vec.rbegin(), vec.rend());
    std::cout << "������������ �������!\n";
}

void VectorManager::displayVector() const {
    for (const auto& num : vec) {
        std::cout << "[" << num << "] ";
    }
    std::cout << std::endl;
}

void VectorManager::clear() {
    vec.clear();
    std::cout << "������ ������!\n";
}

void VectorManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ofstream::trunc);
    for (int num : vec) {
        file << num << " ";
    }
    std::cout << "�������� � ���� �������!\n";
}

void VectorManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int num;
    vec.clear();
    while (file >> num) {
        vec.push_back(num);
    }
    std::cout << "������ ��������� �� ����� �������!\n";
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
        std::cout << "����� " << num << " �������.\n";
    }
    else {
        std::cerr << "����� �� �������\n";
    }
}

void VectorManager::insertElement(int num, int index) {
    if (index >= 0 && index <= vec.size()) {
        vec.insert(vec.begin() + index, num);
    }
    else
    {
        cerr << "������ ������ �� ����������\n";
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
    cout << "������� ��������, ������� Enter ����� �������:\n";
    for (int& num : vec) {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "�� �����\n";
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
    cout << "���� ������!\n";
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


