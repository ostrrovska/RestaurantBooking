#include "Apartment.h"
#include <iostream>
#include <fstream>

//void Apartment::getApartmentInfo() {
//    std::cout << "Hotel name: " << hotelName <<std::endl;
//    std::cout << "Type of apartment: " << typeOfApartment << std::endl;
//    std::cout << "Apartment number: " << apartmentNumber << std::endl;
//    std::cout << "Number of rooms: " << numberOfRooms << std::endl;
//    std:: cout << "Price: " << price << std::endl;
//}
void Apartment::displayInfo() const {
    std::cout << "Type of apartment: " << typeOfApartment << std::endl;
    std::cout << "Apartment number: " << apartmentNumber << std::endl;
    std::cout << "Number of rooms: " << numberOfRooms << std::endl;
    std::cout << "Price: " << price << " GRN" << std::endl;
}
void Apartment::writeApartmentToFile(std::string &path, int index) {
    std::ofstream writeToFile(path + "Apartment" + std::to_string(index) + ".txt", std::ostream::out);
    writeToFile <<  typeOfApartment << std::endl;
    writeToFile <<  apartmentNumber << std::endl;
    writeToFile <<  numberOfRooms << std::endl;
    writeToFile <<  price << std::endl;
    writeToFile << isTaken << std::endl;
    writeToFile.close();
}
Apartment Apartment::downloadApartmentInfo(const std::string &filename, const std::string &path) {
    std::ifstream fileToRead(path + filename, std::ifstream::out);
    std::string currentLine;
    Apartment apartment;
    getline(fileToRead, currentLine);
    apartment.typeOfApartment = currentLine;
    getline(fileToRead, currentLine);
    apartment.apartmentNumber = std::stoi(currentLine);
    getline(fileToRead, currentLine);
    apartment.numberOfRooms = std::stoi(currentLine);
    getline(fileToRead, currentLine);
    apartment.price = std::stoi(currentLine);
    getline(fileToRead, currentLine);
    apartment.isTaken = static_cast<bool>(std::stoi(currentLine));
    fileToRead.close();
    return apartment;
}

//void Apartment::showApartments(std::vector<Apartment> &apartments) {
//    for (const auto &apartment: apartments) {
//        std::cout << "Type of Apartment: " << apartment.typeOfApartment << std::endl;
//        std::cout << "Apartment Number: " << apartment.apartmentNumber << std::endl;
//        std::cout << "Number of Rooms: " << apartment.numberOfRooms << std::endl;
//        std::cout << "Price: " << apartment.price << std::endl;
//        std::cout << "                               " << std::endl;
//    }
//}

Apartment::Apartment()
        : Apartment{"None", "None", 0, 0, 0} {} //делегування
Apartment::Apartment(const std::string &hotelName)
        : Apartment{hotelName, "None", 0, 0, 0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment)
        : Apartment{hotelName, typeOfApartment, 0, 0, 0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber)
        : Apartment{hotelName, typeOfApartment, apartmentNumber, 0, 0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber,
                     int numberOfRooms)
        : Apartment{hotelName, typeOfApartment, apartmentNumber, numberOfRooms, 0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber,
                     int numberOfRooms, int price)
        : typeOfApartment{typeOfApartment}, apartmentNumber{apartmentNumber}, numberOfRooms{numberOfRooms},
          price{price} {}

//Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price)
//    : Hotel{hotelName},typeOfApartment{typeOfApartment},apartmentNumber{apartmentNumber},numberOfRooms{numberOfRooms},price{price}{}
//implemented move constructor
Apartment::Apartment(Apartment &&other) noexcept
        : typeOfApartment{other.typeOfApartment}, apartmentNumber{other.apartmentNumber},
          numberOfRooms{other.numberOfRooms}, price{other.price}, isTaken{other.isTaken} {}

Apartment::Apartment(const Apartment &apartment)
        : typeOfApartment{apartment.typeOfApartment}, apartmentNumber{apartment.apartmentNumber},
          numberOfRooms{apartment.numberOfRooms}, price{apartment.price}, isTaken{apartment.isTaken} {};

Apartment::~Apartment() {
}

