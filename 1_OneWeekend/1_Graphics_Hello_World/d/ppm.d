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

string generateHeader(int x, int y) {
  string header = "P3\n" ~ to!string(x) ~ " " ~ to!string(y) ~ "\n255\n";
  return header;
}

string[] generatePixels(int x, int y) {
  int nx = x;
  int ny = y;
  string[] pixels;
  string rgb;
  for (int j = ny-1; j >= 0; j--) {
    foreach (i; 0..nx) {
      float r = float(i) / float(nx);
      float g = float(j) / float(ny);
      float b = 0.2;
      int ir = to!int(255.99*r);
      int ig = to!int(255.99*g);
      int ib = to!int(255.99*b);
      rgb = to!string(ir) ~ " " ~ to!string(ig) ~ " " ~ to!string(ib);
      pixels ~= rgb;
    }
  }
  return pixels;
}

void main() {
  int x = 200;
  int y = 100;
  string header = generateHeader(x, y);
  string[] pixels = generatePixels(x, y);
  outputFile("dimage.ppm", header, pixels);
}
