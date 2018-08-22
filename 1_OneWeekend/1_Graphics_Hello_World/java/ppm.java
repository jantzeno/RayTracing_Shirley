import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.io.FileWriter;
import java.io.PrintWriter;

class ppm {

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

    public void generatePixels(int x, int y) {
        int nx = x;
        int ny = y;
        pixels = new ArrayList<>(nx*ny);

        header = new StringBuilder()
            .append("P3\n")
            .append(String.valueOf(nx))
            .append(" ")
            .append(String.valueOf(ny))
            .append("\n255\n")
            .toString();

        for (int j = ny-1; j >= 0; j--) {
            for (int i = 0; i < nx; i++) {
                float r = (float) i / (float) nx;
                float g = (float) j / (float) ny;
                float b = 0.2f;
                int ir = (int)(255.99f*r);
                int ig = (int)(255.99f*g);
                int ib = (int)(255.99f*b);

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

    public static void main(String[] args) {
        ppm image = new ppm();
        image.generatePixels(200, 100);
        try {
            image.writeImage("javaimage.ppm");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}