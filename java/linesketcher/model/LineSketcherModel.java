package es.uv.eu.LineSketcher.model;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class LineSketcherModel {
    private BufferedImage imagen;
    private String imagenFileName = "";
    private boolean inicio = true;
    private int p1x, p1y, p2x, p2y;
    private int lineas = 0;
    private boolean gradiente = false;
    int color1 = 9, color2 = 9;

    /**
     * Constructor de LineSketcherModel
     */
    public LineSketcherModel() {
        try {
            imagenFileName = "imagenes/blanco.jpg";
            imagen = ImageIO.read(new File(imagenFileName));
        }
        catch (IOException e) {
            System.out.println("Problemas leyendo la imagen '" + this.imagenFileName + "'.");
            System.out.println("Motivo: " + e.getLocalizedMessage());
        }
    }

    /**
     * Devuelve la imagen almacenada en el modelo
     * @return La imagen actual
     */
    public BufferedImage getImagen() {
        return imagen;
    }

    /**
     * Devuelve el nombre de la imagen almacenada en el modelo
     * @return El nombre de la imagen
     */
    public String getImagenFileName() {
        return imagenFileName;
    }

    /**
     * Carga una imagen nueva en el modelo
     * @param imagenFile La imagen a cargar
     */
    public void loadImagen(File imagenFile) {
        if (imagenFile != null) {
            this.imagenFileName = imagenFile.getName();
            try {
                imagen = ImageIO.read(imagenFile);
            }
            catch (IOException e) {
                System.out.println("Problemas leyendo la imagen '" + this.imagenFileName + "'.");
                System.out.println("Motivo: " + e.getLocalizedMessage());
            }
        }
    }

    /**
     * Guarda la imagen del modelo en el dispositivo
     * @param imagenFile
     */
    public void saveImagen(File imagenFile) {
        if (imagenFile != null) {
            try {
                this.imagenFileName = imagenFile.getName();
                ImageIO.write(imagen,"jpg",imagenFile);
            } 
            catch (IOException e) {
                System.out.println("Problemas guardando la imagen '" + imagenFile.getName() + "'.");
                System.out.println("Motivo: " + e.getLocalizedMessage());
            }
        }
    }
    
    /**
     * Almacena la posición del primer click
     * @param x
     * @param y
     */
    public void SetP1(int x, int y)
    {
        p1x = x;
        p1y = y;
    }
    
    /**
     * Almacena la posición del segundo click
     * @param x
     * @param y
     */
    public void SetP2(int x, int y)
    {
        p2x = x;
        p2y = y;
    }
    
    /**
     * Devuelve la posición x del primer click
     * @return La posición x del primer click
     */
    public int GetP1x()
    {
        return p1x;
    }
    
    /**
     * Devuelve la posición y del primer click
     * @return La posición y del primer click
     */
    public int GetP1y()
    {
        return p1y;
    }
    
    /**
     * Guarda el color seleccionado para el color 1
     * @param c El color a guardar
     */
    public void SetColor1(int c)
    {
        color1 = c;
    }
    
    /**
     * Guarda el color seleccionado para el color 2
     * @param c El color a guardar
     */
    public void SetColor2(int c)
    {
        color2 = c;
    }
    
    /**
     * Devuelve el color seleccionado para el color 1
     * @return El color seleccionado para el color 1
     */
    public int GetColor1()
    {
        return color1;
    }
    
    /**
     * Devuelve el color seleccionado para el color 2
     * @return El color seleccionado para el color 2
     */
    public int GetColor2()
    {
        return color2;
    }
    
    /**
     * Devuelve la posición x del segundo click
     * @return La posición x del segundo click
     */
    public int GetP2x()
    {
        return p2x;
    }

    /**
     * Devuelve la posición xydel segundo click
     * @return La posición y del segundo click
     */
    public int GetP2y()
    {
        return p2y;
    }
    
    /**
     * Devuelve el numero de lineas
     * @return El numero de lineas
     */
    public int GetLineas()
    {
        return lineas;
    }
    
    /**
     * Iguala el numero de lineas a 0
     */
    public void ResetLineas()
    {
        lineas = 0;
    }
    
    /**
     * Devuelve el valor booleano que determina que ventana está activa
     * @return Valor booleano que determina que ventana está activa
     */
    public boolean GetInicio()
    {
        return inicio;
    }
    
    /**
     * Cambia el valor booleano que determina que ventana está activa
     * @param b El valor nuevo
     */
    public void SetInicio(boolean b)
    {
        inicio = b;
    }
    
    /**
     * Devuelve el valor booleano que determina que tipo de color se usa
     * @return Valor booleano que determina que tipo de color se usa
     */
    public boolean getModo()
    {
        return gradiente;
    }
    
    /**
     * Iguala el valor booleano que determina el modo de color a 0, color simple
     */
    public void Uncolor()
    {
        gradiente = false;
    }
    
    /**
     * Iguala el valor booleano que determina el modo de color a 1, color gradiente
     */
    public void Gradiente()
    {
        gradiente = true;
    }
    
    /**
     * Pinta una línea
     * 
     * @param x1 Posicion x inicial de la linea
     * @param y1 Posicion y inicial de la linea
     * @param x2 Posicion x final de la linea
     * @param y2 Posicion y final de la linea
     * @param grosor Grosor de la línea
     * @param color1 Color 1 de la línea
     * @param color2 Color 2 de la línea
     */
    public void pintaLinea (int x1, int y1, int x2, int y2, int grosor, Color color1, Color color2){
        Graphics2D gr = (Graphics2D)imagen.getGraphics();
        
        if(gradiente)
        {
            GradientPaint gradiente= new GradientPaint(0,0,color1, 175,175, color2, true);
            gr.setPaint(gradiente);
        }
        else
        {
            GradientPaint gradiente= new GradientPaint(0,0,color1, 175,175, color1, true);
            gr.setPaint(gradiente);
        }
        
        lineas++;
        gr.setStroke(new BasicStroke(grosor));
                
        gr.drawLine(x1, y1, x2, y2);
    }

    /**
     * Borra las líneas de la imagen y si hay error, pinta la escena de blanco
     */
    public void borraImagen() {
        try {
            String nom_imagen = this.imagenFileName;
            imagen = ImageIO.read(new File(nom_imagen));
        }
        catch (IOException e) {
            System.out.println("Problemas leyendo la imagen '" + this.imagenFileName + "'.");
            System.out.println("Motivo: " + e.getLocalizedMessage());
            this.pintaLinea(100, 100, 1000, 1000, 5000, Color.WHITE, Color.WHITE);
            lineas=0;
        }
    }
}
