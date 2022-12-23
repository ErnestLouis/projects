// mini_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using std::string;
using big_one = unsigned long long;

const std::string INPUT_ERROR_STRING = "Input error! Please try again.";
const std::string CONTACTS_FILE_NAME = "contacts.bin";


struct Contact
{
    string firstname;
    string lastname;
    big_one phone_number;

};

struct ContactsDB
{
    Contact* optr_contacts;
    int number_of_contacts;
    int capacity;
};

void create_contacts_file();
bool load_contacts(ContactsDB& contactsdb);
void save_contacts(const ContactsDB& contacts_db);
char get_option_from_user();
void execute_option(char option, ContactsDB& contactdb);
void add_option(ContactsDB& contactsdb);
void display_option(const ContactsDB& contactsdb);
void resize_contacts_db(ContactsDB& contactsdb, int new_capacity);



int main()
{
    ContactsDB contactsdb;
    contactsdb.optr_contacts = nullptr;
    contactsdb.number_of_contacts = 0;
    contactsdb.capacity = 0;

    create_contacts_file();

    if (!load_contacts(contactsdb))
    {
        std::cout << " Error reading file: " << CONTACTS_FILE_NAME << std::endl;
        return 0;
    }
    char option;

    do
    {
        option = get_option_from_user();

        execute_option(option, contactsdb);
    } while (option != 'q');


    save_contacts(contactsdb);

    if (contactsdb.optr_contacts != nullptr)
    {
        delete[] contactsdb.optr_contacts;
        contactsdb.optr_contacts = nullptr;
    }

}

void create_contacts_file()
{
    std::ifstream in_file;

    in_file.open(CONTACTS_FILE_NAME, std::fstream::binary);
    if (!in_file.is_open())
    {
        std::ofstream outfile;
        outfile.open(CONTACTS_FILE_NAME, std::fstream::binary);
        outfile << std::flush;//flush means please just create it.
        outfile.close();
    }
    else
    {
        in_file.close();
    }
}

bool load_contacts(ContactsDB& contactsdb)
{
    std::ifstream in_file;
    in_file.open(CONTACTS_FILE_NAME, std::fstream::binary);

    if (in_file.is_open())
    {
        in_file.seekg(0, in_file.end);
        int lenght_of_fib = in_file.tellg();

        in_file.seekg(0, in_file.beg);

        int number_of_contacts = lenght_of_fib / sizeof(Contact);
        int capacity = number_of_contacts * 2 + 10;

        //new the memory for pointer contacts

        contactsdb.optr_contacts = new Contact[capacity];
        contactsdb.number_of_contacts = number_of_contacts;
        contactsdb.capacity = capacity;

        in_file.read((char*)contactsdb.optr_contacts, contactsdb.number_of_contacts * sizeof(Contact));
        in_file.close();

        return true;

    }

    return false;
}

void save_contacts(const ContactsDB& contacts_db)
{
    std::ofstream out_file;

    out_file.open(CONTACTS_FILE_NAME, std::fstream::binary);

    if (out_file.is_open())
    {
        out_file.write((char*)contacts_db.optr_contacts, contacts_db.number_of_contacts * sizeof(Contact));

        out_file.close();
    }

}

char get_option_from_user()
{
    const char options[] = { 'd','a','q' };

    return get_character("Please choose an option:\n\n(D)isplay Contacts \n(A)dd Contact\n(Q)uit\n\nWhat is your choice: ", INPUT_ERROR_STRING, options, 3, CC_LOWER_CASE);
}

void execute_option(char option, ContactsDB& contactsdb)
{
    switch (option)
    {
    case 'a':
        add_option(contactsdb);
        break;
    case 'd':
        display_option(contactsdb);
        break;
    }
}

void add_option(ContactsDB& contactsdb)
{

    if (contactsdb.number_of_contacts == contactsdb.capacity)
    {
        resize_contacts_db(contactsdb, contactsdb.capacity * 2 + 10);
    }

    get_string("Please enter the first name: ", INPUT_ERROR_STRING, contactsdb.optr_contacts[contactsdb.number_of_contacts].firstname);
    get_string("Please enter the last name: ", INPUT_ERROR_STRING, contactsdb.optr_contacts[contactsdb.number_of_contacts].lastname);

    std::cout << "Please enter the phone number: ";
    std::cin >> contactsdb.optr_contacts[contactsdb.number_of_contacts].phone_number;

    contactsdb.number_of_contacts++;

    save_contacts(contactsdb);

    std::cout << "Saved!!" << std::endl;

}
void display_option(const ContactsDB& contactsdb)
{
    for (int i = 0; i < contactsdb.number_of_contacts; i++)
    {
        std::cout << " Name: " << contactsdb.optr_contacts[i].firstname << " " << contactsdb.optr_contacts[i].lastname << std::endl;
        std::cout << " Phone Number: " << contactsdb.optr_contacts[i].phone_number << std::endl << std::endl; //space between each entry
    }
}

void resize_contacts_db( ContactsDB& contactsdb, int new_capacity)
{
    // make new array of size new_capacity
    Contact* new_contacts_ptr = new Contact[new_capacity];

    //copy all existing contacts into new array
    for (int i = 0; i < contactsdb.number_of_contacts; i++)
    {
        new_contacts_ptr[i].firstname = contactsdb.optr_contacts[i].firstname;
        new_contacts_ptr[i].lastname = contactsdb.optr_contacts[i].lastname;
        new_contacts_ptr[i].phone_number = contactsdb.optr_contacts[i].phone_number;
    }

    //delete the old array
    if (contactsdb.optr_contacts != nullptr)
    {
        delete[] contactsdb.optr_contacts;
        contactsdb.optr_contacts = nullptr;
    }

    //set the contactsDB.optr_contact = new array
    contactsdb.optr_contacts = new_contacts_ptr;
    contactsdb.capacity = new_capacity;
}

