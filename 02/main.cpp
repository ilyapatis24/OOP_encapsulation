#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Address
{
public:
    Address(string& city, string& street, int& house, int& apartment) : city(city), street(street), house(house), apartment(apartment)
    {
    }

    string make_address() {
        full_address = city + ", " + street + ", " + std::to_string(house)
            + ", " + std::to_string(apartment);
        return full_address;
    }

    string get_city() {
        return city;
    }

private:
    string city;
    string street;
    int house = 0;
    int apartment = 0;
    string full_address;
};

void write_data(Address** arrayForClassObjects, int address_quantity)
{
    ofstream file_output("out.txt");

    if (file_output.is_open())
    {
        cout << "Файл out.txt успешно открыт." << endl;
    }
    else
    {
        cout << "Ошибка открытия файла" << endl;
    }

    file_output << address_quantity << endl;

    for (int i = 0; i < address_quantity; i++)
    {
        file_output << arrayForClassObjects[i]->make_address() << endl;
    }
    file_output.close();

};

void sort(Address** address, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            char a = address[j]->get_city()[0];
            char b = address[j + 1]->get_city()[0];
            if (a > b) {
                Address* temp = address[j];
                address[j] = address[j + 1];
                address[j + 1] = temp;
            }
        }
    }
}

void clear_memory(Address** array_ptr, int size) {
    for (int i = 0; i < size; i++) {
        delete array_ptr[i];
    }
    delete[] array_ptr;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    int address_quantity = 0;
    string NameCity = "";
    string NameStreet = "";
    int NumberHouse = 0;
    int NumberApartment = 0;
    ifstream file_input("in.txt");
    if (file_input.is_open())
    {
        cout << "Файл in.txt. успешно открыт!" << endl;

    }
    else
    {
        cout << "Ошибка открытия файла in.txt." << endl;
    }
    file_input >> address_quantity;
    Address** arrayForClassObjects = new Address*[address_quantity];
    while (!file_input.eof()) {
        for (int i = 0; i < address_quantity; i++) {
            file_input >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
            arrayForClassObjects[i] = new Address(NameCity, NameStreet, NumberHouse, NumberApartment);
        }
    }
    file_input.close();
    sort(arrayForClassObjects, address_quantity);
    write_data(arrayForClassObjects, address_quantity);
    clear_memory(arrayForClassObjects, address_quantity);
    return 0;
}