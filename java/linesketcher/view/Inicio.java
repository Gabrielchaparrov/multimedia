/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import es.uv.eu.LineSketcher.model.LineSketcherModel;
import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import javax.swing.event.ChangeListener;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class Inicio extends JFrame{
    
    private SelectPanelInicio selectpanel = new SelectPanelInicio(false);
    private SelectPanelInicio selectpanel2 = new SelectPanelInicio(true);
    private Empezar empezar = new Empezar();
    private Opciones opciones;
    
    
    private StatusPanel statuspanel;
    private MenuInicio menu = new MenuInicio();
    private RadioPanel radio;
    private JPanel centro;
    private JPanel botones = new JPanel();
    private AñadirColor añadir;

    /**
     * Constructor de Inicio
     * @param model
     */
    public Inicio(LineSketcherModel model)
    {
        setLayout(new BorderLayout());
        
        statuspanel = new StatusPanel();
        
        opciones = new Opciones();
        añadir = new AñadirColor();
        centro = new JPanel();
        centro.setLayout(new GridLayout(2,1));
        
        botones.setLayout(new BorderLayout());
        botones.add(opciones, BorderLayout.CENTER);
        botones.add(añadir, BorderLayout.SOUTH);
        
        centro.add(botones);
        
        centro.add(selectpanel);
        
        
        add(centro, BorderLayout.CENTER);

        radio = new RadioPanel();
        
        this.setJMenuBar(menu);
        
        add(statuspanel, BorderLayout.NORTH);
        
        add(radio, BorderLayout.NORTH);
        add(empezar, BorderLayout.SOUTH);

        
        setVisible(true);
        setSize(1170,700);
    }
    
    /**
     * Cambia la estructura de la ventana inicial al añadir un color y usar gradiente
     * @param color El color secundario
     */
    public void cambiarGradiente(int color)
    {
        centro.remove(selectpanel);
        
        centro.add(selectpanel2, BorderLayout.WEST);
        
        opciones.setFondo2(color);
        
        centro.revalidate();
        centro.repaint();
        
        opciones.gradiente();
        
        añadir.gradiente();
    }

    /**
     * Cambia la estructura de la ventana inicial al quitar el color extra y usar un solo color
     */
    public void cambiarSimple()
    {
        centro.remove(selectpanel2);
        
        centro.add(selectpanel, BorderLayout.WEST);
        
        opciones.setFondo2(9);
        
        centro.revalidate();
        centro.repaint();
        
        opciones.simple();
        
        añadir.simple();
    }
    
    /**
     * Cambia el fondo de la etiqueta del color 1
     * @param color Color
     */
    public void setFondo1(int color)
    {
        opciones.setFondo1(color);
    }
    
    /**
     * Cambia el fondo de la etiqueta del color 2
     * @param color Color
     */
    public void setFondo2(int color)
    {
        opciones.setFondo2(color);
    }

    /**
     * Cambia el radio
     * @param r Radio nuevo
     */
    public void setRadio(int r)
    {
        statuspanel.setRadio(r);
        radio.setRadio(r);
    }
    
    /**
     * Devuelve el radio
     * @return rADIO
     */
    public int getRadio()
    {
        return statuspanel.getRadio();
    }

    /**
     * Se asignan los listeners necesarios a los componentes de Inicio
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ){
        selectpanel.setActionListener(actionListener);
        selectpanel2.setActionListener(actionListener);
        menu.setActionListener(actionListener);
        empezar.setActionListener(actionListener);
        añadir.setActionListener(actionListener);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de Inicio
     * @param e
     */
    public void setChangeListener(ChangeListener e){
        radio.setChangeListener(e);
    }
}