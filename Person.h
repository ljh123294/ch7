#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include<iostream>

struct Person;

std::istream &read(std::istream &, Person &);
// std::ostream &print(std::ostream &, const Person &);

struct Person
{
    friend std::istream &read(std::istream &is, Person &item);
    friend std::ostream &print(std::ostream &os, const Person &item);

private:
    std::string name;
    std::string address;
public:
    Person() : name(""), address(""){}
	Person(const std::string &sname, const std::string &saddress = "") : name(sname), address(saddress){}
    Person(std::istream &is){read(is, *this);}
    std::string get_name() const{return name;}
    std::string get_address() const{return address;}
};

std::istream &read(std::istream &is, Person &item)
{
	return is >> item.name >> item.address;
}

std::ostream &print(std::ostream &os, const Person &item)
{
	return os << item.name << " " << item.address;
}

#endif
