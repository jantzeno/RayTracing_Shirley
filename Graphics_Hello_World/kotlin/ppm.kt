import java.io.File

fun generateHeader(x: Int, y: Int): String {
  val header: String = "P3\n" + x.toString() + " " + y.toString() + "\n255\n"
  return header
}

fun generatePixels(x: Int, y: Int): List<String> {
  val nx: Int = x
  val ny: Int = y
  val pixels = ArrayList<String>()
  for (j in (ny - 1) downTo 0) {
    for (i in 0 until nx) {
      val r: Float = i.toFloat() / nx.toFloat()
      val g: Float = j.toFloat() / ny.toFloat()
      val b: Float = 0.2f
      val ir: Int = (255.99*r).toInt()
      val ig: Int = (255.99*g).toInt()
      val ib: Int = (255.99*b).toInt()
      val rgb: String = ir.toString() + " " + ig.toString() + " " + ib.toString()
      pixels.add(rgb)
    }
  }
  return pixels
}

fun outputImage(fileName: String, header: String, pixels: List<String>){
  File(fileName).printWriter().use { out ->
      out.print(header)
      for (pixel in pixels) {
        out.println(pixel)
      }
  }
}

fun main(args: Array<String>) {
  val x = 200;
  val y = 100;
  val header: String = generateHeader(x, y)
  val pixels = generatePixels(x, y);
  outputImage("kotlinimage.ppm", header, pixels)
}
