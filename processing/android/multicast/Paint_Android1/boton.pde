
class Button{

  int btn_width, btn_height;
  PVector pos, color_, color_funcion;
  String texto, funcion;
  int tam;
  
  public Button(int btn_width, int btn_height, PVector pos, String texto, int tam, String funcion, PVector color_funcion){
    this.btn_width = btn_width;
    this.btn_height = btn_height;
    this.pos = pos;
    this.texto = texto;
    this.tam = tam;
    this.funcion = funcion;
    this.color_funcion = color_funcion;
    color_ = new PVector(-1, -1, -1);
  }
  
  public Button(int btn_width, int btn_height, PVector pos, String texto, int tam, String funcion){
    this.btn_width = btn_width;
    this.btn_height = btn_height;
    this.pos = pos;
    this.texto = texto;
    this.tam = tam;
    this.funcion = funcion;

    color_ = new PVector(-1, -1, -1);
    color_funcion = new PVector(-1, -1, -1);
    
  }

  public void setcolor(PVector color_){
    this.color_ = color_;
  }
  
  public String getfuncion(){
    return this.funcion;
  }
  
  public PVector getcolor_funcion(){
    return this.color_funcion;
  }
  
  public void Draw(){
    if(color_.x == -1){
      fill(200, 200, 200);
    }
    else{
      fill(color_.x, color_.y, color_.z);
    }
    
    pushMatrix();
      if(texto != "")
        textSize(tam);
      
      translate(pos.x, pos.y);
      stroke(0, 0, 0);
      strokeWeight(2);
      rectMode(CORNER);
      rect(0, 0, btn_width, btn_height);
      textAlign(CENTER);
      fill(0);
      text(texto, floor(btn_width/2), ceil(btn_height/2) + (tam/2));
    popMatrix();
  }
  
  public boolean isClicked(int x, int y){
    if(x >= pos.x && x <= pos.x + btn_width && y >= pos.y && y <= pos.y + btn_height)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  
}
