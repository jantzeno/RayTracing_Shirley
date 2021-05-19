import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.io.FileWriter;
import java.io.PrintWriter;

class ppm {

    public static void main(String[] args) {
        int width = 256;
        int height = 256;
        ppm image = new ppm();
        image.generateHeader(width, height);
        image.generatePixels(width, height);
        try {
            image.writeImage("javaimage.ppm");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    String header;
    List<String> pixels;

    public void writeImage(String fileName) throws IOException {
        FileWriter fileWriter = new FileWriter(fileName);
        try(PrintWriter printWriter = new PrintWriter(fileWriter)) {

            printWriter.print(header);
            for (String rgb : pixels) {
                printWriter.print(rgb);
            }
        }
    }

    public void generateHeader(int width, int height) {
      header = new StringBuilder()
          .append("P3\n")
          .append(String.valueOf(width))
          .append(" ")
          .append(String.valueOf(height))
          .append("\n255\n")
          .toString();
    }

    public void generatePixels(int width, int height) {
        pixels = new ArrayList<>(width*height);

        for (int j = height-1; j >= 0; j--) {
            for (int i = 0; i < width; i++) {
                float r = (float) i / (float) width-1;
                float g = (float) j / (float) height-1;
                float b = 0.25f;
                int ir = (int)(255.999f*r);
                int ig = (int)(255.999f*g);
                int ib = (int)(255.999f*b);

                String rgb = new StringBuilder()
                    .append(String.valueOf(ir))
                    .append(" ")
                    .append(String.valueOf(ig))
                    .append(" ")
                    .append(String.valueOf(ib))
                    .append("\n")
                    .toString();

                pixels.add(rgb);
            }
        }
    }
}
