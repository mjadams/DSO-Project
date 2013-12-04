import controlP5.*;

/*****************************************************
 * USB DSO Interface Software
 * Original Author: David Jahshan 2011
 * Updated by: M J Adams
 * Revision Date: 04.12.2013
 * 
 * This code interfaces with the USB DSO and displays 
 * the information captured by the device.
 *****************************************************
 */


import processing.serial.*;
int screen_width = 1200, screen_height = 800, topgap = 50;
Serial USBDSOPort;
char KeyStroke = ' ';  
String ReceivedString = " ";
int x = 0, y = 0, mouse_x, mouse_y;

//folowing vaiables are for button positions
//x is start point on x. y is start point on y, w is width, h is height
int capture_x=50, capture_y=650, capture_w=100, capture_h=30; 
int send_x=200, send_y=650, send_w=100, send_h=30;
int abort_x=350, abort_y=650, abort_w=100, abort_h=30;
int force_x=500, force_y=650, force_w=100, force_h=30;
int rate_x=650, rate_y=650, rate_w=100, rate_h=30;
char rate=3;
int trigger_x=800, trigger_y=650, trigger_w=100, trigger_h=30;
char trigger=127;

//int _x=, _y=, _w=, _h=;

void redraw_scene()
{
    background(255);
    fill(255);
    rect(0,0,width,600);//screen
    rect(capture_x, capture_y, capture_w, capture_h);
    rect(send_x, send_y, send_w, send_h);
    rect(abort_x, abort_y, abort_w, abort_h);
    rect(force_x, force_y, force_w, force_h);
    rect(rate_x, rate_y, rate_w, rate_h);
    rect(trigger_x, trigger_y, trigger_w, trigger_h);
    line(10,300,screen_width-10,300);
    line((screen_width/2+topgap),(topgap+10),(screen_width/2+topgap),590);
    fill(0);
    text("DSO V0.1", 10,30);
    text("Capture", (capture_x+20), (capture_y+20));
    text("Send", (send_x+20), (send_y+20));
    text("Abort", (abort_x+20), (abort_y+20));
    text("Force", (force_x+20), (force_y+20));
    text("Rate", (rate_x+20), (rate_y+20));
    text("Trigger", (trigger_x+20), (trigger_y+20));
    text((int)trigger, (trigger_x+75), (trigger_y+20));
    text((int)rate, (rate_x+80), (rate_y+20));
}

void setup() 
{
  size(screen_width,screen_height);
  PFont DisplayFont = createFont("Arial", 14);
  textFont(DisplayFont);

  // Print a list all the available serial ports:
  println(Serial.list());

  // Open USBDSO port
  String portList = Serial.list()[1];
  USBDSOPort = new Serial(this, portList, 38400);
  background(255);
  USBDSOPort.write('v');
  USBDSOPort.write('r');
  USBDSOPort.write('3');
  
  redraw_scene();
//  rect(_x, _y, _w, _h);
//  text("", (_x+20), (_y+20));
  
  //USBDSOPort.write('v');
  //USBDSOPort.write('C');
  stroke(0);
}

void draw() 
{
}

void serialEvent(Serial USBDSOPort) 
{
  y = int(USBDSOPort.read());
  //ReceivedString += char(USBDSOPort.read());
  //rect(0,50,width,height/2);
  //text(ReceivedString, 10, 20);
  //text(KeyStroke, 10, 40);
  point(x,((y*2)+topgap));
  x++;  
  if (x == screen_width)
  {
    USBDSOPort.write('n');
    //x = 0;
    //background(0);
  }
}

void mousePressed() 
{
 mouse_x = mouseX;
 mouse_y = mouseY;
 if (mouse_x > (capture_x) && mouse_y > (capture_y) && mouse_x < (capture_x+capture_w) && mouse_y < (capture_y+capture_h))
 { 
    USBDSOPort.write('C');
 }
  if (mouse_x > (send_x) && mouse_y > (send_y) && mouse_x < (send_x+send_w) && mouse_y < (send_y+send_h))
 { 
    USBDSOPort.write('s');
    x=0;
    redraw_scene();

 }
  if (mouse_x > (abort_x) && mouse_y > (abort_y) && mouse_x < (abort_x+abort_w) && mouse_y < (abort_y+abort_h))
 { 
    USBDSOPort.write('n');
 }
  if (mouse_x > (force_x) && mouse_y > (force_y) && mouse_x < (force_x+force_w) && mouse_y < (force_y+force_h))
 { 
    USBDSOPort.write('f');
 }
  if (mouse_x > (rate_x) && mouse_y > (rate_y) && mouse_x < (rate_x+rate_w) && mouse_y < (rate_y+rate_h))
 { 
   if(rate < 3)
     rate++;
    else
      rate=1;
    USBDSOPort.write('r');
    USBDSOPort.write((rate+48));
    redraw_scene();
 }
  if (mouse_x > (trigger_x) && mouse_y > (trigger_y) && mouse_x < (trigger_x+trigger_w) && mouse_y < (trigger_y+trigger_h))
 { 
   if(trigger < 255)
     trigger+=8;
    else
      trigger=0;
    USBDSOPort.write('t');
    USBDSOPort.write(trigger);
    redraw_scene();
 }
/*  if (mouse_x > (_x) && mouse_y > (_y) && mouse_x < (_x+_w) && mouse_y < (_y+_h))
 { 
    USBDSOPort.write('C');
 }*/
}

void keyPressed() 
{
  // Send the keystroke out:
  ReceivedString = "";
  USBDSOPort.write(key);
  KeyStroke = char(key);
  x=0;
  rect(0,0,width,height/2);
}

