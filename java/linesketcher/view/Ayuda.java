/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class Ayuda extends JFrame{
    
    JPanel panel = new JPanel();
    JButton volver;
    JLabel titulo;
    JLabel help;
    
    /**
     * Constructor por defecto de Ayuda
     */
    public Ayuda()
    {
        volver = new JButton("Volver");
        volver.setActionCommand("VolverAyuda");
        
        panel.setLayout(new BorderLayout());
        
        titulo = new JLabel("Ayuda:");    
        help = new JLabel("<html> <body align='center'> Si quieres que las líneas sean de un color, selecciona el color deseado." + 
                "<br><br>Si quieres que las líneas sean degradadas, selecciona \"Añadir color secundario\" y aparecerá una paleta para el color secundario." +
                "<br><br>Si quires eliminar el color secundario, selecciona \"Quitar color secundario\" y se volverá a pintar con un color." +
                "<br><br>Si no seleccionas colores, se iniciarán en blanco por defecto." +
                "<br><br>Pulsa empezar para dibujar. </body> </html>");
        
        titulo.setFont(new Font("Cooper Black",Font.PLAIN ,30));
        help.setFont(new Font("Helvetica",Font.PLAIN ,20));
        
        help.setHorizontalAlignment(JLabel.CENTER);
        help.setVerticalAlignment(JLabel.CENTER);
        
        titulo.setHorizontalAlignment(JLabel.CENTER);
        titulo.setVerticalAlignment(JLabel.CENTER);
        
        volver.setFont(new Font("Helvetica", Font.BOLD ,25));
        
        panel.add(titulo, BorderLayout.NORTH);
        panel.add(help, BorderLayout.CENTER);
        panel.add(volver, BorderLayout.SOUTH);
        
        this.add(panel);
        this.setSize(650, 500);
        
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de Autores
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        volver.addActionListener(actionListener);
    } 
    
}
