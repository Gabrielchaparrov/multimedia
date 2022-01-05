/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import static es.uv.eu.LineSketcher.view.ColorPanel.cod_color;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class Opciones extends JPanel{
    
    private JLabel Color1, Color2;
    
    /**
     * Constructor de Opciones
     */
    public Opciones()
    {
        Color1 = new JLabel("Color Principal");
        Color2 = new JLabel("Color Secundario");
        
        Color1.setOpaque(true);
        Color2.setOpaque(true);
        
        Color1.setBackground(cod_color[9]);
        Color2.setBackground(cod_color[9]);
        
        Color1.setHorizontalAlignment(JLabel.CENTER);
        Color1.setVerticalAlignment(JLabel.CENTER);
        
        Color2.setHorizontalAlignment(JLabel.CENTER);
        Color2.setVerticalAlignment(JLabel.CENTER);
    
        
        

        this.setLayout(new GridLayout(1,1, 10, 10));
        this.add(Color1);

        Color1.setFont(new Font("Cooper Black",Font.BOLD ,30));
        Color2.setFont(new Font("Cooper Black",Font.BOLD ,30));
        
        
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
    }
    
    /**
     * Cambia el color del fondo 1
     * @param color
     */
    public void setFondo1(int color)
    {
        Color1.setBackground(cod_color[color]);
        
        if(color == 0 || color == 2 || color == 11)
        {
            Color1.setForeground(Color.WHITE);
        }
        else
        {
            Color1.setForeground(Color.BLACK);
        }

    }
    
    /**
     * Cambia el color del fondo 2
     * @param color
     */
    public void setFondo2(int color)
    {
        Color2.setBackground(cod_color[color]);
        
        if(color == 0 || color == 2 || color == 11)
        {
            Color2.setForeground(Color.WHITE);
        }
        else
        {
            Color2.setForeground(Color.BLACK);
        }
    }
    
    /**
     * Reestructura el panel a modo color simple
     */
    public void simple()
    {
        this.remove(Color2);
        this.setLayout(new GridLayout(1,1, 10, 10));
    }
    
    /**
     * Reestructura el panel a modo color gradiente
     */
    public void gradiente()
    {
        this.setLayout(new GridLayout(1,2, 10, 10));
        this.add(Color2);
    }
   
}