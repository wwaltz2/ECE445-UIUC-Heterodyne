// text to byte serial importer for redboard and flash mem
// developed based on AudioXfer.pde from Adafruit Industries

import processing.serial.*;

Serial  port = null;
int     capacity;
boolean done = false;

// Wait for line from serial port, with timeout
String readLine() {
  String s;
  int    start = millis();
  do {
    s = port.readStringUntil('\n');
  } while((s == null) && ((millis() - start) < 3000));
  return s;
}

// Extract unsigned multibyte value from byte array
int uvalue(byte b[], int offset, int len) {
  int    i, x, result = 0;
  byte[] bytes = java.util.Arrays.copyOfRange(b, offset, offset + len);
  for(i=0; i<len; i++) {
    x = bytes[i];
    if(x < 0) x += 256;
    result += x << (i * 8);
  }
  return result;
}

void setup() {
  String s;

  size(200, 200); // Serial freaks out without a window :/

  // Locate Arduino running AudioLoader sketch.
  // Try each serial port, checking for ACK after opening.
  println("Scanning serial ports...");
  for(String portname : Serial.list()) {
    try {
      portname = "COM3"; // bypass scan
      port = new Serial(this, portname, 57600);
    } catch (Exception e) { // Port in use, etc.
      continue;
    }
    print("Trying port " + portname + "...");
    if(((s = readLine()) != null) && s.contains("HELLO")) {
      println("OK");
      break;
    } else {
      println();
      port.stop();
      port = null;
    }
  }

  if(port != null) { // Find one?
    if(((s        = readLine())                != null)) {
      println("Found Arduino");
      selectInput("Select a file to process:", "fileSelected");
    } else {
      println("Arduino failed to initialize flash memory.");
      done = true;
    }
  } else {
    println("Could not find connected Arduino running AudioLoader sketch.");
    done = true;
  }
}

void readFirstPage() {
  String line;
  while(true){
//    print("flag0");
    line = port.readStringUntil('\n');
//    print("flag1");
    if(line != null){
//      print("flag2");
      print(line); // print each line from Arduino
    }
//    print("flag3");
    if(line != null && line.contains("END_PAGE")){    
//      print("flag4");
      break; // done reading the page
    }
  }
}

//void fileSelected(File f) {
//  if(f == null) {
//    println("Cancel selected or window closed.");
//  } else {
//    port.write("ERASE"); // Issue erase command now, process audio while it works
//    println("Selected file: " + f.getAbsolutePath());
//    byte input[] = loadBytes(f.getAbsolutePath());
//    //println(input);
//    int c;
//    String s;
//    while(((s = readLine()) == null) || (s.contains("READY") == false));
//    for(int i=0;i<input.length;i++){
//      println(input[i]);
//      port.write(input[i]);
//      print(readLine());
//    }
//    readFirstPage();
//
//    println("done af");
//  }
//  done = true;
//}

void fileSelected(File f){
 if( f == null) {
   println("somethin happened");
 } else {
//   int i_fr = 0;
    
   port.write("ERASE"); // Issue erase command now, process audio while it works
   
   File[] files = {new File("D:/LAST SEMESTER/ECE445-UIUC-Heterodyne/Firmware/WAV Files/FinalFiles/Oskee.wav"),
                   new File("D:/LAST SEMESTER/ECE445-UIUC-Heterodyne/Firmware/WAV Files/FinalFiles/EasternRedBat.wav"),
                   new File("D:/LAST SEMESTER/ECE445-UIUC-Heterodyne/Firmware/WAV Files/FinalFiles/IndianaBat.wav"),
                   new File("D:/LAST SEMESTER/ECE445-UIUC-Heterodyne/Firmware/WAV Files/FinalFiles/BigBrownBat.wav")};

   int totalExpected = 0;
   
   byte[][] fileBytes = new byte[files.length][];
   for(int i = 0; i<files.length; i++){
     byte[] file = loadBytes(files[i]);
     fileBytes[i] = file;
     totalExpected += file.length;
   }
   
   byte[] output = new byte[totalExpected];
   int offset = 0;
   
   for (int i = 0; i < fileBytes.length; i++) {
    byte[] file = fileBytes[i];
    int samples = file.length;
    println("file number: ", i, "has mem location: ", offset);

//    output[offset + 0] = (byte)(samples >> 24);
//    output[offset + 1] = (byte)(samples >> 16);
//    output[offset + 2] = (byte)(samples >> 8);
//    output[offset + 3] = (byte)(samples);
//
//    offset += 4;

    arrayCopy(file, 0, output, offset, samples);
    offset += samples;
  }
  println("totalbytes...: ",output.length);
  
  int c;
  String s;
  while(((s = readLine()) == null) || (s.contains("READY") == false));
  println("we get here");
  for(int i=0;i<output.length;i++){
//    println(output[i]);
    port.write(output[i]);
    s = readLine();
    if(i % 1000 == 0) print(s);
    if(i % (totalExpected/100) == 0) print(100*i/totalExpected);
  }
  readFirstPage();

  println("done af");
 }
 done = true;
}


void draw() {
  if(done) exit();
}

