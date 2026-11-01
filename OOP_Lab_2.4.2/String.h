#pragma once
#include <iostream>
#include <string>

class String {
private:
    static const int MAX_SIZE = 256;
    int size;
    unsigned char str[MAX_SIZE];

public:
    String();
    String(int maxSize);
    String(const char* s, int maxSize = 255);
    String(const String& other);

    int length() const;
    int getSize() const;
    void setSize(int maxSize);

    int find(const String& sub) const;
    void remove(int index, int count);
    void insert(int index, const String& sub);

    String& operator=(const String& other);
    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    operator std::string() const;
    String operator+(const String& other) const;

    friend std::ostream& operator<<(std::ostream& out, const String& s);
    friend std::istream& operator>>(std::istream& in, String& s);
};