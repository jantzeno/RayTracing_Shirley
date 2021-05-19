
proc outputFile(fileName: string, header: string, pixels: seq[string]): bool =
  var output = open(fileName, fmWrite)
  try:
    output.writeLine(header)
    for p in pixels:
      output.writeLine(p)
    return true
  except:
    echo "Any error occured writing image"
  return false

proc generateHeader(width: int, height: int): string =
  var header: string = "P3\n" & $width & " " & $height & "\n255"
  return header

proc generatePixels(width: int, height: int): seq[string] =
  var pixels = newSeq[string]()
  var rgb: string

  for j in countdown(height-1, 0):
    for i in 0..<width:
      let r: float = float(i) / float(width-1)
      let g: float = float(j) / float(height-1)
      let b: float = 0.25
      let ir: int = int(255.999 * r)
      let ig: int = int(255.999 * g)
      let ib: int = int(255.999 * b)
      rgb = $ir & " " & $ig & " " & $ib
      pixels.add(rgb)

  return pixels

# main
let x = 256
let y = 256
let header = generateHeader(x, y)
let pixels = generatePixels(x, y)
let image = outputFile("nimimage.ppm", header, pixels)
if image == false:
  echo "Error writing image file"
