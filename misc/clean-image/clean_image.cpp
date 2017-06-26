#include <iostream>
#include <fstream>

uint8_t grayscale(uint8_t r, uint8_t g, uint8_t b) {
    return (uint8_t)(0.21*r + 0.72*g + 0.07*b);
    //return r;
}

int main(void) {
    std::cout << (int)grayscale(0, 100, 200) << std::endl;

    std::fstream fin("signatures.ppm", std::fstream::in);
    std::string header;
    int width, height, ncolors;
    fin >> header >> width >> height >> ncolors;

    std::fstream fout("signatures_cleaned.pgm", std::fstream::out);
    fout << "P2\n";
    fout << width << " " << height << "\n";
    fout << "255\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r, g, b; fin >> r >> g >> b;
            int out = grayscale((uint8_t)r, (uint8_t)g, (uint8_t)b);
            // threshold
            if (out > 240) out = 255;
            fout << out << ' ';
            if (j % 20 == 19) fout << '\n';
        }
        fout << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}


