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

std::string generateHeader(int width, int height) {
  std::string header = "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n";
  return header;
}

std::vector<std::string> generatePixels(int width, int height) {
  std::vector<std::string> pixels;
  pixels.reserve(width * height);
  std::string rgb;
  for (int j = height-1; j >= 0; j--) {
    for (int i = 0; i < width; i++) {
      float r = float(i) / float(width-1);
      float g = float(j) / float(height-1);
      float b = 0.25;
      int ir = int(255.999 * r);
      int ig = int(255.999 * g);
      int ib = int(255.999 * b);
      rgb = std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib) + "\n";
      pixels.emplace_back(rgb);
    }
  }
  return pixels;
}

int main() {
  int width = 256;
  int height = 256;
  auto header = generateHeader(width, height);
  auto pixels = generatePixels(width, height);
  outputFile("cppimage.ppm", header, pixels);
}
