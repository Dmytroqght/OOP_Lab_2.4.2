#include "String.h"

String::String() : size(255) { str[0] = 0; }

String::String(int maxSize) {
    setSize(maxSize);
    str[0] = 0;
}

String::String(const char* s, int maxSize) {
    setSize(maxSize);
    int len = 0;
    while (s[len] != '\0' && len < size && len < 255) {
        str[len + 1] = s[len];
        len++;
    }
    str[0] = len;
}

String::String(const String& other) {
    size = other.size;
    for (int i = 0; i <= other.str[0]; i++) {
        str[i] = other.str[i];
    }
}

int String::length() const { return str[0]; }
int String::getSize() const { return size; }

void String::setSize(int maxSize) {
    if (maxSize > 0 && maxSize <= 255) size = maxSize;
    else size = 255;
}

int String::find(const String& sub) const {
    if (sub.str[0] == 0) return 1;
    if (sub.str[0] > str[0]) return -1;

    for (int i = 1; i <= str[0] - sub.str[0] + 1; i++) {
        bool match = true;
        for (int j = 1; j <= sub.str[0]; j++) {
            if (str[i + j - 1] != sub.str[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

void String::remove(int index, int count) {
    if (index < 1 || index > str[0] || count <= 0) return;
    if (index + count - 1 > str[0]) {
        count = str[0] - index + 1;
    }
    for (int i = index; i <= str[0] - count; i++) {
        str[i] = str[i + count];
    }
    str[0] -= count;
}

void String::insert(int index, const String& sub) {
    if (index < 1) index = 1;
    if (index > str[0] + 1) index = str[0] + 1;

    int insertCount = sub.str[0];
    if (str[0] + insertCount > size) {
        insertCount = size - str[0];
    }
    if (insertCount <= 0) return;

    for (int i = str[0]; i >= index; i--) {
        str[i + insertCount] = str[i];
    }
    for (int i = 1; i <= insertCount; i++) {
        str[index + i - 1] = sub.str[i];
    }
    str[0] += insertCount;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        size = other.size;
        for (int i = 0; i <= other.str[0]; i++) {
            str[i] = other.str[i];
        }
    }
    return *this;
}

unsigned char& String::operator[](int index) { return str[index]; }
const unsigned char& String::operator[](int index) const { return str[index]; }

String::operator std::string() const {
    std::string res;
    for (int i = 1; i <= str[0]; i++) res += static_cast<char>(str[i]);
    return res;
}

String String::operator+(const String& other) const {
    String res(this->size);
    res = *this;
    int addCount = other.str[0];
    if (res.str[0] + addCount > res.size) {
        addCount = res.size - res.str[0];
    }
    for (int i = 1; i <= addCount; i++) {
        res.str[res.str[0] + i] = other.str[i];
    }
    res.str[0] += addCount;
    return res;
}

std::ostream& operator<<(std::ostream& out, const String& s) {
    out << std::string(s);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    std::string temp;
    std::getline(in >> std::ws, temp); // Дозволяє зчитувати рядок з пробілами
    int len = temp.length();
    if (len > s.getSize()) len = s.getSize();
    for (int i = 0; i < len; i++) {
        s.str[i + 1] = temp[i];
    }
    s.str[0] = len;
    return in;
}