#ifndef LENGTH_H
#define LENGTH_H
#include <compare>
#include <ostream>

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    // bool operator>(const Length& other) const;
    // bool operator<(const Length& other) const;
    // bool operator>=(const Length& other) const;
    // bool operator<=(const Length& other) const;
    std::strong_ordering operator<=> (const Length& other) const;
    ~Length();

    int getValue() const;

  private:
    int value;
};

std::ostream& operator<<(std::ostream& stream, const Length& length);

#endif