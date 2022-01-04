class Coche {
  
  float aX, paX;
  float x, y;
  float val;
  boolean accChange;
  
  PImage imagen;
  PImage luces;
  
  Coche(){
    x = width/2;
    y = height - height/4;
    accChange = false;
    imagen = loadImage("coche.png");
    imagen.resize(width/8, height/8);
    
    luces = loadImage("luces.png");
    luces.resize(width/8, height/8);
  }
  
  void changed()
  {
    accChange = true;
  }
  
  void actualizarX()
  {
    if(!choque)
    {
      if(accChange==true){
        val = map(-aX,-3,+3,0,width);    
        accChange=false;
      }
      
      if(val > width-width/6)
        val = width-width/6;
      else if(val < 0)
        val = 0;
        
      float targetX = val;
      float dx = targetX - x;
      x += dx * easing;
    }
   
    display();
    
  }
 
  void display()
  {
    //rect (x,height-50,100,10);
    
    pushMatrix();
      translate(x, height - height/4);
      image(imagen, 0, 0);
      if(noche)
      {
        translate(0, -height/7.8);
        image(luces, 0, 0);
      }
    popMatrix();
  } 
  
}
