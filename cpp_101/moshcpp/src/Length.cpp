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

int Length::getValue() const
{
    return this->value;
}

std::ostream &operator<<(std::ostream &stream, const Length &length)
{
    
    stream << length.getValue();
    return stream; 
}
