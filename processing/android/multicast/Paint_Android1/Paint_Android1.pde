/*
**    Gabriel Chaparro Villaescusa y María Navarro Silvestre
*/

import hypermedia.net.*;

UDP udp;  // the UDP object
ArrayList<Integer> X = new ArrayList<Integer>();
ArrayList<Integer> Y = new ArrayList<Integer>();
ArrayList<Integer> X2 = new ArrayList<Integer>();
ArrayList<Integer> Y2 = new ArrayList<Integer>();
ArrayList<PVector> c = new ArrayList<PVector>();
ArrayList<Float> gr = new ArrayList<Float>();
int grosor = 3;
int r = 255;
int g = 255;
int b = 255;
PVector colorActual = new PVector(r, g, b);
ArrayList<Button> botones = new ArrayList<Button>();
Button mas, menos, limpiar;
int h_btn_color = (width/2)/3; 
boolean rectBorrar = false;

void setup() {

  fullScreen();
  udp = new UDP( this, 6000, "224.0.0.1" );
  udp.listen( true );
  println( "init as multicast socket ... "+udp.isMulticast() );
  println( "joins a multicast group  ... "+udp.isJoined() );
  
  push();
    fill(200);
    rect(0, 0, width, width);
  pop();
  
  int aux = 0;
  ArrayList<PVector> colores = new ArrayList<PVector>();
  colores.add(new PVector(255, 000, 000));
  colores.add(new PVector(000, 255, 000));
  colores.add(new PVector(000, 000, 255));
  colores.add(new PVector(255, 255, 000));
  colores.add(new PVector(000, 255, 255));
  colores.add(new PVector(255, 255, 255));
  colores.add(new PVector(255, 000, 255));
  colores.add(new PVector(000, 000, 255));
  colores.add(new PVector(100, 100, 100));
  colores.add(new PVector(155, 000, 255));
  colores.add(new PVector(150, 60, 30));
  colores.add(new PVector(0,0, 0));
  
  mas = new Button(width/3, (height-width)/4, new PVector(((width/3)), (width)), "+", ceil((height-width)/4 * 0.4), "Mas");
  botones.add(mas);
  
  menos = new Button(width/3, (height-width)/4, new PVector((0), (width)), "-", ceil((height-width)/4 * 0.4), "Menos");
  botones.add(menos);
  
  limpiar = new Button(width/3, (height-width)/4, new PVector((width/3)*2, (width)), "Limpiar", ceil((height-width)/4 * 0.4), "Limpiar");
  botones.add(limpiar);
  
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      Button boton = new Button((width/4), (height-width)/4, new PVector((i) * ((width/2) /2), (width) + (height-width)/4*(j+1)), "", ceil(h_btn_color * 0.4), "Color", colores.get(aux));
      boton.setcolor(colores.get(aux));
      botones.add(boton);
      aux++;
    }
  }
  
}

void draw() {
  
  if(rectBorrar){
    push();
    fill(200);
    rect(0, 0, width, width);
    pop();
    
    rectBorrar = false;

    X.clear();
    Y.clear();
    X2.clear();
    Y2.clear();
    c.clear();
    gr.clear();
  }
  
  for(int i = 0; i < X.size(); i++)
  {
    stroke(c.get(i).x, c.get(i).y, c.get(i).z);
    strokeWeight(gr.get(i));
    pintar(X.get(i), Y.get(i), X2.get(i), Y2.get(i));
    
    X.remove(i);
    Y.remove(i);
    X2.remove(i);
    Y2.remove(i);
    gr.remove(i);
    c.remove(i);
  }
  
  for(Button b : botones)
  {
    b.Draw();
  }
  
  stroke(0);
  line(0, width, width, width);
  
  if(mouseY < width && pmouseY < width && mouseY >= 0 && pmouseY >= 0 &&
  mouseX < width && pmouseX < width && mouseX >= 0 && pmouseX >= 0 &&
  mousePressed)
  {
    stroke(colorActual.x, colorActual.y, colorActual.z);
    strokeWeight(grosor);
    pintar(mouseX, mouseY, pmouseX, pmouseY);

    byte[] data = new byte[9];
    
    data[0] = byte(0);
    data[1] = byte(map(mouseX, 0, width, -128, 127));
    data[2] = byte(map(mouseY, 0, width, -128, 127));
    data[3] = byte(map(pmouseX, 0, width, -128, 127));
    data[4] = byte(map(pmouseY, 0, width, -128, 127));
    data[5] = byte(colorActual.x);
    data[6] = byte(colorActual.y);
    data[7] = byte(colorActual.z);
    data[8] = byte(grosor);
    
    udp.send( data ); 
  }
}
void pintar(int x, int y, int x2, int y2)
{
  line( x, y, x2, y2 );
  
}
void mousePressed(){
  for(Button b: botones){
    if(b.isClicked(mouseX, mouseY)){
      accion_boton(b);
    }
  }
}
public void accion_boton(Button b){
  String func = b.getfuncion();
  
  if(func == "Color")
  {
    colorActual = b.getcolor_funcion();
  }
  else if(func == "Menos")
  {
    if(grosor > 1)
      grosor--;
  }
  else if(func == "Mas")
  {
    grosor++;
  }
  else if(func == "Limpiar")
  {
    push();
    fill(155);
    rect(0, 0, width, width);
    pop();
    
    byte[] data = new byte[1];
    
    data[0] = byte(3);
    
    udp.send( data ); 
  }
}
 
 
void receive( byte[] data ) {
  int opcion = int(data[0]);
  
  if(opcion == 1)
  {
    int x  = int(map(data[1], -128, 127, 0, width));
    int y  = int(map(data[2], -128, 127, 0, width));
    int px = int(map(data[3], -128, 127, 0, width));
    int py = int(map(data[4], -128, 127, 0, width));
    int r2 = int( data[5] );
    int g2 = int( data[6] );
    int b2 = int( data[7] );
    int grosor = int( data[8] );
    
    X.add(x);
    Y.add(y);
    X2.add(px);
    Y2.add(py);
    c.add(new PVector(r2, g2, b2));
    gr.add((float)grosor);
  }
  else if(opcion == 3)
    rectBorrar = true;
}
