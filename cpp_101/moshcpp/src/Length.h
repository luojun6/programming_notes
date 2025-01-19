#ifndef LENGTH_H
#define LENGTH_H

#pragma once

class Length {
  public:
    explicit Length(int value);
    bool operator==(const Length& other) const;
    bool operator==(int other) const;
    bool operator!=(int other) const;
    bool operator>(const Length& other) const;
    bool operator<(const Length& other) const;
    bool operator>=(const Length& other) const;
    bool operator<=(const Length& other) const;
    ~Length();

  private:
    int value;
};

#endif