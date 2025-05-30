#ifndef COLOR_H_UNIQUE_20240615
#define COLOR_H_UNIQUE_20240615

#include <string>
#include <tuple>
#include <iostream>

class Color {
private:
    unsigned char r, g, b, a;
    unsigned char clamp(int x);
    std::string lower(std::string s);

public:
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
    explicit Color(std::string name);

    unsigned char getR() const { return r; }
    unsigned char getG() const { return g; }
    unsigned char getB() const { return b; }
    unsigned char getA() const { return a; }

    void setR(unsigned char x) { r = clamp(x); }
    void setG(unsigned char x) { g = clamp(x); }
    void setB(unsigned char x) { b = clamp(x); }
    void setA(unsigned char x) { a = clamp(x); }

    std::tuple<unsigned char, unsigned char, unsigned char> rgb() const;
    std::tuple<unsigned char, unsigned char, unsigned char, unsigned char> rgba() const;

    std::string rgbStr() const;
    std::string rgbaStr() const;
    std::string hex() const;

    Color operator/(const Color& c) const;
    friend std::ostream& operator<<(std::ostream& out, const Color& c);
};

#endif