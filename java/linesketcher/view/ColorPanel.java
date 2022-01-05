/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JLabel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class ColorPanel extends JPanel{
    
    private JButton[] botones = new JButton[14];

    /**
     * Nombres de colores
     */
    public static final String[] colores = {"Negro", "Cyan", "Gris Oscuro", "Gris", "Gris Claro", "Magenta", "Naranja", "Rosa", "Amarillo", "Blanco", "Rojo", "Azul", "Verde"};

    /**
     * Color correspondiente a cada nombre
     */
    public static final Color[] cod_color = {Color.BLACK, Color.CYAN, Color.DARK_GRAY, Color.GRAY, Color.LIGHT_GRAY, Color.MAGENTA, Color.ORANGE, Color.PINK, Color.YELLOW, Color.WHITE, Color.RED, Color.BLUE, Color.GREEN};
    private JLabel nombre;
    
    /**
     * Constructor de ColorPanel
     * @param num
     */
    public ColorPanel(String num)
    {
        setLayout(new GridLayout(7,2));
        
        nombre = new JLabel("Color " + num);
        add(nombre);
        nombre.setFont(new Font("Helvetica",Font.BOLD, 15));
        
        for(int i = 0; i < colores.length; i++)
        {
            botones[i] = new JButton(colores[i]);
            botones[i].setActionCommand(String.valueOf(i) + num);
            add(botones[i]);
            
            botones[i].setBackground(cod_color[i]);
            botones[i].setOpaque(true);
            
            if(i == 0 || i == 2 || i == 11)
            {
                botones[i].setForeground(Color.WHITE);
            }
        }
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de ColorPanel
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        
        for(int i = 0; i < colores.length; i++)
        {
            botones[i].addActionListener(actionListener);
        }
    } 
}
