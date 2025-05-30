#include <iostream>
#include "color.h"

int main() {
    Color red(255, 0, 0);
    Color blue(0, 0, 255, 128);
    Color green("green");

    std::cout << "red r: " << (int)red.getR() << std::endl;
    std::cout << "green g: " << (int)green.getG() << std::endl;
    std::cout << "blue a: " << (int)blue.getA() << std::endl;

    Color c(100, 100, 100);
    c.setR(200);
    c.setA(128);
    std::cout << "new color: " << c << std::endl;

    auto [r, g, b] = green.rgb();
    std::cout << "green rgb: " << (int)r << "," << (int)g << "," << (int)b << std::endl;

    auto [r2, g2, b2, a2] = blue.rgba();
    std::cout << "blue rgba: " << (int)r2 << "," << (int)g2 << "," << (int)b2 << "," << (int)a2 << std::endl;

    std::cout << "red rgb: " << red.rgbStr() << std::endl;
    std::cout << "red rgba: " << red.rgbaStr() << std::endl;
    std::cout << "red hex: " << red.hex() << std::endl;

    Color mix = red / green;
    std::cout << "red+green: " << mix << std::endl;
    std::cout << "green: " << green << std::endl;

    return 0;
}