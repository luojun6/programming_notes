#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <string>
#include "Widget.h"

#pragma once
using namespace std;

class TextBox : public Widget
{
public:
    TextBox() = default;
    explicit TextBox(const string& value);
    string getValue();
    void setValue(const string& value);
private:
    string value;
};

#endif