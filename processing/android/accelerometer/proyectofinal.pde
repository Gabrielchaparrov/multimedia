import ketai.sensors.*;
 
KetaiSensor sensor; 

Boolean noche = false;
Boolean choque;
Boolean inicio = true;

PImage fondo;
int cont = 0;
int velocidad = 90;
final float dt = 0.1;

float tiempo_ini;

/********************************/

float dThresh=0.05;
float dc;
float easing = 0.1;

ArrayList<Button> b;

Coche c;
Trafico t;

Button ini;
Button replay;
Button puntos_juego;

 
void settings() { 
  fullScreen();
}
 
void setup() { 
  sensor = new KetaiSensor(this);
  sensor.start();

  textAlign(CENTER, CENTER);
  textSize(32);
  frameRate(24);
  
  ini = new Button(width/2, height/5, new PVector(width/4, (height / 2 + (height/5))), "JUGAR", ceil(height/5 * 0.4), "JUGAR");
  replay = new Button(width, height/5, new PVector(0, (height / 2 + (height/5))), "VOLVER A JUGAR", ceil(height/5 * 0.15), "REPLAY");
  puntos_juego = new Button(width/3, height/12, new PVector((width/3) * 2, 0), "Puntos: ", ceil(height/5 * 0.1), "-");
  
  b = new ArrayList<Button>();
  
  b.add(ini);
  b.add(replay);
  
  fondo = loadImage("carretera.jpg");
  fondo.resize(width, height/3);
  
  c = new Coche();
  
  t = new Trafico(); 
  
  choque = false;
}
 
void draw() { 
  
  if(inicio)
  {
    ini.Draw();
    text("CRASH!", width/2, height/3);
  }
  else if(!inicio && !choque)
  {
  
    puntos_juego.texto = "Puntos: " + (int)abs(tiempo_ini - millis());
    
    background(0); 
    //text("Accelerometer: \nx: " + nfp(c.aX, 1, 3) + "\nCHANGE=" + nfc(dc,2), 0, 0, width, height);
  
    cont += dt * velocidad;
    
    if(cont >= +fondo.height || cont <= -fondo.height)
    {
      cont = 0;
    }
    
    image(fondo, 0, cont);
    image(fondo, 0, cont + fondo.height);
    image(fondo, 0, cont + 2*fondo.height);
    image(fondo, 0, cont - fondo.height);
   
    
    c.actualizarX();
   
    t.run();
    
    for (int i = 0; i < t.enemigos.size(); i++)
    {
      Enemigo e = t.enemigos.get(i);
    
      if (c.x+width/8 > e.x-width/8 && c.x < e.x && c.y+height/8 > e.y-height/8 && c.y < e.y) {
        choque = true;
      }
    }
    
    puntos_juego.Draw();
  }
  else
  {
    replay.Draw();
  }
   
}

void mousePressed(){

  for(Button aux: b){
    if(aux.isClicked(mouseX, mouseY)){
      accion_boton(aux);
    }
  }
}

public void accion_boton(Button b){
  String func = b.getfuncion();
  
  if(func == "JUGAR")
  {
    inicio = false;
    tiempo_ini = millis();
  }
  else if(func == "REPLAY")
  {
    setup();
    tiempo_ini = millis();
  }
}
 
void onAccelerometerEvent(float x, float y, float z) {
  c.paX=c.aX;
 
  c.aX = x;
 
  dc=abs(c.aX-c.paX);
 
  if(dc>dThresh){
    c.changed();
  }
}

void onLightEvent(float d)
{
  if(d < 1250)
    noche = true;
  else
    noche = false;
}
