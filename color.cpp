#include "color.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

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
    if (name == "black") { r = 0; g = 0; b = 0; }
    else if (name == "silver") { r = 192; g = 192; b = 192; }
    else if (name == "gray") { r = 128; g = 128; b = 128; }
    else if (name == "white") { r = 255; g = 255; b = 255; }
    else if (name == "maroon") { r = 128; g = 0; b = 0; }
    else if (name == "red") { r = 255; g = 0; b = 0; }
    else if (name == "purple") { r = 128; g = 0; b = 128; }
    else if (name == "fuchsia") { r = 255; g = 0; b = 255; }
    else if (name == "green") { r = 0; g = 128; b = 0; }
    else if (name == "lime") { r = 0; g = 255; b = 0; }
    else if (name == "olive") { r = 128; g = 128; b = 0; }
    else if (name == "yellow") { r = 255; g = 255; b = 0; }
    else if (name == "navy") { r = 0; g = 0; b = 128; }
    else if (name == "blue") { r = 0; g = 0; b = 255; }
    else if (name == "teal") { r = 0; g = 128; b = 128; }
    else if (name == "aqua") { r = 0; g = 255; b = 255; }
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
    std::stringstream s;
    s << "#" << std::hex << std::setw(2) << std::setfill('0') << (int)r
      << std::setw(2) << std::setfill('0') << (int)g
      << std::setw(2) << std::setfill('0') << (int)b;
    return s.str();
}

Color Color::operator/(const Color& c) const {
    return Color((r + c.r) / 2, (g + c.g) / 2, (b + c.b) / 2, (a + c.a) / 2);
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
    out << c.rgbStr();
    return out;
}