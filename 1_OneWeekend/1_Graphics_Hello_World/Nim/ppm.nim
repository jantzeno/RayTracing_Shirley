
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


let nx = 200
let ny = 100
var pixels = newSeq[string]()
var header: string = "P3\n" & $nx & " " & $ny & "\n255"
var rgb: string
for j in countdown(ny-1, 0):
    for i in 0..<nx:
        let r: float = toFloat(i) / toFloat(nx)
        let g: float = toFloat(j) / toFloat(ny)
        let b: float = 0.2
        let ir: int = toInt(255.99*r)
        let ig: int = toInt(255.99*g)
        let ib: int = toInt(255.99*b)
        rgb = $ir & " " & $ig & " " & $ib
        pixels.add(rgb)

var image: bool
image = outputFile("nimimage.ppm", header, pixels)
