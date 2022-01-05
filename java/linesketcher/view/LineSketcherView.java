/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import es.uv.eu.LineSketcher.model.LineSketcherModel;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import javax.swing.event.ChangeListener;
import javax.swing.JFrame;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class LineSketcherView extends JFrame{
    
    private SelectPanel selectpanel = new SelectPanel(false);
    private SelectPanel selectpanel2 = new SelectPanel(true);
    
    
    private StatusPanel statuspanel;
    private LineSketcherMenuBar menu = new LineSketcherMenuBar();
    private RadioPanel radio;
    private ImagePanel imagen;
    private Ayuda ayuda = new Ayuda();
    private Autores autores = new Autores();
    private Inicio inicio;
    
    /**
     * Constructor de LineSketecherView
     * @param model
     */
    public LineSketcherView(LineSketcherModel model)
    {
        setLayout(new BorderLayout());
        
        inicio = new Inicio(model);
        
        statuspanel = new StatusPanel();
        
        imagen  = new ImagePanel(model);
        radio = new RadioPanel();
        
        this.setJMenuBar(menu);
        add(selectpanel, BorderLayout.WEST);
        add(statuspanel, BorderLayout.NORTH);
        add(radio, BorderLayout.SOUTH);
        add(imagen, BorderLayout.CENTER);
        
        setVisible(true);
        setSize(1225,740);
    }
    
    /**
     * Cambia al modo de gradiente y cambia la estructura para adaptarse
     * @param c color
     */
    public void cambiarGradiente(int c)
    {
        this.remove(selectpanel);
        
        this.add(selectpanel2, BorderLayout.WEST);
        
        statuspanel.activarColor2();
        inicio.cambiarGradiente(c);
        
        this.revalidate();
        this.repaint();
    }
    
    /**
     * Cambia a modo simple y modifica la estructura
     */
    public void cambiarSimple()
    {
        this.remove(selectpanel2);
        
        this.add(selectpanel, BorderLayout.WEST);
        
        statuspanel.quitarColor2();
        inicio.cambiarSimple();
        
        this.revalidate();
        this.repaint();
    }
    
    /**
     * Vuelve al modo por defecto
     */
    public void inidefecto()
    {
        inicio.setRadio(5);
        inicio.setFondo1(9);
        inicio.setFondo2(9);
        inicio.cambiarSimple();
    }
    
    /**
     * Hace visible Ayuda
     */
    public void ayudavisible()
    {
        ayuda.setVisible(true);
    }
    
    /**
     * Hace invisible ayuda
     */
    public void ayudainvisible()
    {
        ayuda.setVisible(false);
    }
    
    /**
     * Hace visible Autores
     */
    public void autoresvisible()
    {
        autores.setVisible(true);
    }
    
    /**
     * Hace invisible Autores
     */
    public void autoresinvisible()
    {
        autores.setVisible(false);
    }
    
    /**
     * Cambia el color de fondo 1 del status panel y de inicio
     * @param color
     */
    public void setFondo1(int color)
    {
        statuspanel.setFondo1(color);
        inicio.setFondo1(color);
    }
    
    /**
     * Cambia el fondo del color 2 del status panel y de inicio
     * @param color
     */
    public void setFondo2(int color)
    {
        statuspanel.setFondo2(color);
        inicio.setFondo2(color);
    }
    
    /**
     * Cambia el radio
     * @param r radio
     */
    public void setRadio(int r)
    {
        statuspanel.setRadio(r);
        radio.setRadio(r);
        inicio.setRadio(r);
    }
    
    /**
     * Desactiva la ventana inicio y activa la ventana de pintar
     */
    public void pintar()
    {
        inicio.setVisible(false);
        this.setVisible(true);
    }
    
    /**
     * Actualiza el status panel
     * @param n
     */
    public void maslinea(int n)
    {
        statuspanel.maslinea(n);
    }
    
    /**
     * Vuelve a la ventana inicio y desactiva la de pintado
     */
    public void ajustes()
    {
        inicio.setVisible(true);
        this.setVisible(false);
    }
    
    /**
     * Devuelve el radio
     * @return
     */
    public int getRadio()
    {
        return statuspanel.getRadio();
    }
    
    /**
     * Devuelve la imagen
     * @return
     */
    public BufferedImage getImagen()
    {
        return imagen.getImagen();
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de LineSketcherView
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ){
        selectpanel.setActionListener(actionListener);
        selectpanel2.setActionListener(actionListener);
        menu.setActionListener(actionListener);
        autores.setActionListener(actionListener);
        ayuda.setActionListener(actionListener);
        inicio.setActionListener(actionListener);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de LineSketcherView
     * @param e
     */
    public void setChangeListener(ChangeListener e){
        radio.setChangeListener(e);
        inicio.setChangeListener(e);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de LineSketcherView
     * @param e
     */
    public void setMouseListener(MouseListener e){
        imagen.setMouseListener(e);
    }

}
