#ifndef LENGTH_H
#define LENGTH_H
#include <compare>
#include <ostream>
#include <istream>

#pragma once

class Length {
  public:
    explicit Length(int value);
    Length() = default;
    // Length(const Length& other) = delete;

    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    std::strong_ordering operator<=> (const Length& other) const;
    ~Length();

    Length operator+(const Length& other) const;
    Length operator+(int _value) const;
    Length& operator+=(const Length& other);
    Length& operator=(const Length& other);
    Length& operator++();   // prefix
    Length operator++(int); // postfix

    int getValue() const;
    void setValue(int value);

  private:
    int value;
    int x;

    // Declare this function as friend, then this function can access the private attributes
    friend std::ostream& operator<<(std::ostream& stream, const Length& length);
};
std::ostream& operator<<(std::ostream& stream, const Length& length);

std::istream& operator>>(std::istream& stream, Length& length);

#endif