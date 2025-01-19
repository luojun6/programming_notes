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

bool Length::operator>(const Length &other) const {
    return value > other.value;
}

bool Length::operator<(const Length &other) const {
    return value < other.value;
}

bool Length::operator>=(const Length &other) const {
    return !(value < other.value);
}

bool Length::operator<=(const Length &other) const {
    return !(value > other.value);
}

Length::~Length() {
}