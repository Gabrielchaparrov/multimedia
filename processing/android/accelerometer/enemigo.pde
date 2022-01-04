class Enemigo 
{
  int velocidad;
  int y;
  int x;
  int carril;
  
  PImage foto;
  PImage luces;
  
  Enemigo(int c, int v, int f)
  {
    carril = c;
    
    x = width/6 * c;
    y = -height/6;
    
    if(carril==5)
      x -= ((width/8)/6);
    
    velocidad = v;
    
    foto = loadImage(f+".png");
    foto.resize(width/8, height/8);
    
    luces = loadImage("luces.png");
    luces.resize(width/8, height/8);
      
  }
  
  void run()
  {
    if(!choque)
      update();
      
    display();
  }
  
  void update()
  {
    y += velocidad*dt;
  }
  
  void display()
  {
    pushMatrix();
      translate(x, y);
      rotate(PI);
      image(foto, 0, 0);
      if(noche)
      {
        translate(0, -height/7.8);
        image(luces, 0, 0);
      }
      //rect (0,0,100,10);
    popMatrix();
  }
}
