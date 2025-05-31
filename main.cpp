#include <iostream>
#include "color.h"

void printHelp() {
    std::cout << "Usage:\n"
              << "  ./program --color <name|hex|rgb>\n"
              << "  ./program --gradient <from> <to> <steps>\n"
              << "  ./program --test\n\n"
              << "Examples:\n"
              << "  ./program --color green\n"
              << "  ./program --color \"rgb(255,0,0)\"\n"
              << "  ./program --color \"#ff0000\"\n"
              << "  ./program --gradient red blue 5\n"
              << "  ./program --test\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printHelp();
        return 0;
    }

    std::string mode = argv[1];

    if (mode == "--color" && argc > 2) {
        std::string colorArg = argv[2];
        Color c;
        
        if (colorArg.find("rgb(") == 0) {
            unsigned char r, g, b;
            sscanf(colorArg.c_str(), "rgb(%hhu,%hhu,%hhu)", &r, &g, &b);
            c = Color(r, g, b);
        }
        else if (colorArg[0] == '#') {
            unsigned int hex;
            sscanf(colorArg.c_str(), "#%x", &hex);
            c = Color((hex >> 16) & 0xFF, (hex >> 8) & 0xFF, hex & 0xFF);
        }
        else {
            c = Color(colorArg);
        }

        std::cout << "Color: " << c << "\n"
                  << "HEX: " << c.hex() << "\n"
                  << "RGB: " << c.rgbStr() << "\n"
                  << "RGBA: " << c.rgbaStr() << "\n";
    }
    else if (mode == "--gradient" && argc > 4) {
        Color from(argv[2]);
        Color to(argv[3]);
        int steps = std::stoi(argv[4]);
        
        auto gradient = Color::makeGradient(from, to, steps);
        for (const auto& c : gradient) {
            std::cout << c << " " << c.hex() << "\n";
        }
    }
    else if (mode == "--test") {
        Color red(255, 0, 0);
        Color blue(0, 0, 255, 128);
        Color green("green");

        std::cout << "red r: " << (int)red.getR() << "\n";
        std::cout << "green g: " << (int)green.getG() << "\n";
        std::cout << "blue a: " << (int)blue.getA() << "\n";

        Color c(100, 100, 100);
        c.setR(200);
        c.setA(128);
        std::cout << "new color: " << c << "\n";

        auto [r, g, b] = green.rgb();
        std::cout << "green rgb: " << (int)r << "," << (int)g << "," << (int)b << "\n";

        auto [r2, g2, b2, a2] = blue.rgba();
        std::cout << "blue rgba: " << (int)r2 << "," << (int)g2 << "," << (int)b2 << "," << (int)a2 << "\n";

        std::cout << "red rgb: " << red.rgbStr() << "\n";
        std::cout << "red rgba: " << red.rgbaStr() << "\n";
        std::cout << "red hex: " << red.hex() << "\n";

        Color mix = red / green;
        std::cout << "red+green: " << mix << "\n";
    }
    else {
        printHelp();
    }

    return 0;
}
