/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import static es.uv.eu.LineSketcher.view.ColorPanel.cod_color;
import java.awt.Color;
import java.awt.Font;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class StatusPanel extends JPanel{
    
    JLabel radio, r, color1, c1, color2, c2, linea, l;
    int radio_num = 5;
    
    /**
     * Constructor de StatusPanel
     */
    public StatusPanel()
    {
        setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
        
        radio = new JLabel("    Grosor de la línea:");
        r = new JLabel(String.valueOf(radio_num));
        radio.setFont(new Font("Helvetica",Font.BOLD, 15));
        r.setFont(new Font("Helvetica",Font.BOLD, 15));
        
        linea = new JLabel("Número de líneas:");
        l = new JLabel("0");
        linea.setFont(new Font("Helvetica",Font.BOLD, 15));
        l.setFont(new Font("Helvetica",Font.BOLD, 15));
        
        color1 = new JLabel("       Color 1:");
        c1 = new JLabel();
        c1.setText("                 ");
        c1.setBackground(cod_color[9]);
        c1.setOpaque(true);
        color1.setFont(new Font("Helvetica",Font.BOLD, 15));
        
        color2 = new JLabel("       Color 2:");
        c2 = new JLabel();
        c2.setText("                 ");
        
        c2.setBackground(cod_color[9]);
        c2.setOpaque(true);
        color2.setFont(new Font("Helvetica", Font.BOLD, 15));
        
        add(linea);
        add(l);
        add(radio);
        add(r);
        add(color1);
        add(c1);
    }
    
    /**
     * Activa la opcion de elegir colores para el color 2
     */
    public void activarColor2()
    {
        add(color2);
        add(c2);
    }
    
    /**
     *  Quita el color 2
     */
    public void quitarColor2()
    {
        remove(color2);
        remove(c2);
    }
    
    /**
     * Actualiza las lineas
     * @param n
     */
    public void maslinea(int n)
    {
        this.l.setText(String.valueOf(n));
    }
    
    /**
     * Actualiza el radio
     * @param r
     */
    public void setRadio(int r)
    {
        radio_num = r;
        this.r.setText(String.valueOf(r));
    }
    
    /**
     * Devuelve el radio
     * @return
     */
    public int getRadio()
    {
        return radio_num;
    }
    
    /**
     * Actualiza el fondo1
     * @param fondo1
     */
    public void setFondo1(int fondo1)
    {
        c1.setBackground(cod_color[fondo1]);
    }
    
    /**
     * Actualiza el fondo2
     * @param fondo2
     */
    public void setFondo2(int fondo2)
    {
        c2.setBackground(cod_color[fondo2]);
    }
    
}
