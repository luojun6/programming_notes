
#include <iostream>
#include "Length.h"

Length::Length(int value) {
    this->value = value;
}

bool Length::operator==(const Length& other) const {
    return value == other.value;
}

bool Length::operator==(int other) const {
    return value == other;
}

bool Length::operator!=(int other) const {

    // return value != other;
    return !(value == other);
}

// bool Length::operator>(const Length &other) const {
//     return value > other.value;
// }

// bool Length::operator<(const Length &other) const {
//     return value < other.value;
// }

// bool Length::operator>=(const Length &other) const {
//     return !(value < other.value);
// }

// bool Length::operator<=(const Length &other) const {
//     return !(value > other.value);
// }

std::strong_ordering Length::operator<=>(const Length &other) const
{
    return value <=> other.value;
}

Length::~Length()
{
}

Length Length::operator+(const Length &other) const
{
    return Length(value + other.value);
}

Length Length::operator+(int _value) const
{
    return Length(this->value + _value);
}

Length& Length::operator+=(const Length &other)
{
    value += other.value;
    return *this;
}

Length& Length::operator=(const Length &other)
{
    std::cout << "Object assigned" << std::endl;
    value = other.value;
    return *this;
}

Length &Length::operator++()
{
    value++;
    return *this;
}

Length Length::operator++(int)
{
    Length copy = *this;
    operator++();
    return copy;
}

inline int Length::getValue() const
{
    return this->value;
}

Length::operator int() const
{
    return value;
}

void Length::setValue(int value)
{
    this->value = value;
}

std::ostream &operator<<(std::ostream &stream, const Length &length)
{
    
    stream << length.getValue();
    return stream; 
}

std::istream &operator>>(std::istream &stream, Length &length)
{
    int value;
    stream >> value;
    length.setValue(value);
    return stream;
}
