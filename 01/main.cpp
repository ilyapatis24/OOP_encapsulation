#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Address
{
private:
    string city;
    string street;
    int house = 0;
    int apartment = 0;
    string full_address;

public:
    Address(string city, string street, int house, int apartment): city(city), street(street), house(house), apartment(apartment)
    {
    }

    string make_address() {
       full_address = city + ", " + street + ", " + std::to_string(house)
            + ", " + std::to_string(apartment);
        return full_address;
    };
};

void write_data(string* arrayForClassObjects, int address_quantity)
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
        file_output << arrayForClassObjects[i] << endl;
    }
    file_output.close();

};

void clear_memory(string* array_ptr) {
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
    string* arrayForClassObjects = new string[address_quantity];
    while (!file_input.eof()) {
        for (int i = 0; i < address_quantity; i++) {
            file_input >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
            Address address(NameCity, NameStreet, NumberHouse, NumberApartment);
            arrayForClassObjects[i] = address.make_address();
        }
    }
    file_input.close();
    write_data(arrayForClassObjects, address_quantity);
    clear_memory(arrayForClassObjects);
    return 0;
}