#include "color.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdio>

unsigned char Color::clamp(int x) {
    if (x < 0) return 0;
    if (x > 255) return 255;
    return x;
}

std::string Color::lower(std::string s) {
    for (char& c : s) c = std::tolower(c);
    return s;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) 
    : r(clamp(r)), g(clamp(g)), b(clamp(b)), a(clamp(a)) {}

Color::Color(std::string name) : r(0), g(0), b(0), a(255) {
    name = lower(name);
    if (name == "black") r=g=b=0;
    else if (name == "silver") r=g=b=192;
    else if (name == "gray") r=g=b=128;
    else if (name == "white") r=g=b=255;
    else if (name == "maroon") r=128;
    else if (name == "red") r=255;
    else if (name == "purple") r=b=128;
    else if (name == "fuchsia") r=b=255;
    else if (name == "green") g=128;
    else if (name == "lime") g=255;
    else if (name == "olive") r=g=128;
    else if (name == "yellow") r=g=255;
    else if (name == "navy") b=128;
    else if (name == "blue") b=255;
    else if (name == "teal") g=b=128;
    else if (name == "aqua") g=b=255;
}

std::tuple<unsigned char, unsigned char, unsigned char> Color::rgb() const {
    return {r, g, b};
}

std::tuple<unsigned char, unsigned char, unsigned char, unsigned char> Color::rgba() const {
    return {r, g, b, a};
}

std::string Color::rgbStr() const {
    std::stringstream s;
    s << "rgb(" << (int)r << "," << (int)g << "," << (int)b << ")";
    return s.str();
}

std::string Color::rgbaStr() const {
    std::stringstream s;
    s << "rgba(" << (int)r << "," << (int)g << "," << (int)b << "," << (float)a/255 << ")";
    return s.str();
}

std::string Color::hex() const {
    char buffer[8];
    snprintf(buffer, sizeof(buffer), "#%02x%02x%02x", r, g, b);
    return buffer;
}

Color Color::operator/(const Color& c) const {
    return Color((r + c.r)/2, (g + c.g)/2, (b + c.b)/2, (a + c.a)/2);
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
    out << c.rgbStr();
    return out;
}

std::vector<Color> Color::makeGradient(Color from, Color to, int steps) {
    std::vector<Color> colors;
    for (int i = 0; i < steps; i++) {
        float t = (float)i/(steps-1);
        unsigned char r = from.r*(1-t) + to.r*t;
        unsigned char g = from.g*(1-t) + to.g*t;
        unsigned char b = from.b*(1-t) + to.b*t;
        colors.emplace_back(r, g, b);
    }
    return colors;
}
