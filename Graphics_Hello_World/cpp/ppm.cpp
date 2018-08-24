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

std::string generateHeader(int x, int y) {
  std::string header = "P3\n" + std::to_string(x) + " " + std::to_string(y) + "\n255\n";
  return header;
}

std::vector<std::string> generatePixels(int x, int y) {
  int nx = x;
  int ny = y;
  std::vector<std::string> pixels;
  pixels.reserve(nx * ny);
  std::string rgb;
  for (int j = ny-1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      float r = float(i) / float(nx);
      float g = float(j) / float(ny);
      float b = 0.2;
      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);
      rgb = std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib) + "\n";
      pixels.emplace_back(rgb);
    }
  }
  return pixels;
}

int main() {
  int x = 200;
  int y = 100;
  auto header = generateHeader(x, y);
  auto pixels = generatePixels(x, y);
  outputFile("cppimage.ppm", header, pixels);
}
