#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool outputFile(std::string const &fileName, 
                std::string const &header,
                std::vector<std::string> const &pixels) {
    std::ofstream output;
    try {
        output.open(fileName);
        output << header.c_str();
        for (auto rgb : pixels) {
            output << rgb.c_str();
        }
        return true;
    } catch (...) {
        std::cout << "Any error occured writing image" << std::endl;
    }
    return false;
}

int main() {
    int nx = 200;
    int ny = 100;
    std::vector<std::string> pixels;
    pixels.reserve(nx*ny);
    std::string header = "P3\n" + std::to_string(nx) + " " + std::to_string(ny) + "\n255\n";
    std::string rgb;
    for (int j = ny-1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            rgb = std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib) + "\n";
            pixels.emplace_back(rgb);
        }
    }
    outputFile("cppimage.ppm", header, pixels);
}