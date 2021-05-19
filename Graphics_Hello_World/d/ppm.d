import std.conv;
import std.stdio;

bool outputFile (string fileName, string header, string[] pixels) {
    try {
      auto output = File(fileName, "w");
      output.write(header);
      foreach (line; pixels) {
        output.writeln(line);
      }
      return true;
    } catch (Exception exc) {
        writeln("Any error occured writing image");
    }
    return false;
}

string generateHeader(int width, int height) {
  string header = "P3\n" ~ to!string(width) ~ " " ~ to!string(height) ~ "\n255\n";
  return header;
}

string[] generatePixels(int width, int height) {
  string[] pixels;
  string rgb;
  for (int j = height-1; j >= 0; j--) {
    foreach (i; 0..width) {
      float r = float(i) / float(width-1);
      float g = float(j) / float(height-1);
      float b = 0.25;
      int ir = to!int(255.999*r);
      int ig = to!int(255.999*g);
      int ib = to!int(255.999*b);
      rgb = to!string(ir) ~ " " ~ to!string(ig) ~ " " ~ to!string(ib);
      pixels ~= rgb;
    }
  }
  return pixels;
}

void main() {
  const int width = 256;
  const int height = 256;
  string header = generateHeader(width, height);
  string[] pixels = generatePixels(width, height);
  outputFile("dimage.ppm", header, pixels);
}
