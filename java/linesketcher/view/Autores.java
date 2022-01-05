/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import java.awt.BorderLayout;
import java.awt.Color;
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
public class Autores extends JFrame{
    
    JPanel panel = new JPanel();
    JButton volver;
    JLabel titulo;
    JLabel nombres;
    
    /**
     * Constructor por defecto de Autores
     */
    public Autores()
    {
        volver = new JButton("Volver");
        volver.setActionCommand("VolverAutores");
        volver.setBackground(Color.GREEN);
        volver.setFont(new Font("Helvetica",Font.BOLD ,25));
        volver.setForeground(Color.BLACK);
        
        panel.setLayout(new BorderLayout());
        
        titulo = new JLabel("Autores:");    
        nombres = new JLabel("<html> <body align='center'> Gabriel Chaparro Villaescusa <br/><br/> María Navarro Silvestre </body> </html>");
        
        nombres.setHorizontalAlignment(JLabel.CENTER);
        nombres.setVerticalAlignment(JLabel.CENTER);
        nombres.setFont(new Font("Cooper Black",Font.BOLD ,30));
        nombres.setForeground(Color.BLUE);
        
        titulo.setHorizontalAlignment(JLabel.CENTER);
        titulo.setVerticalAlignment(JLabel.CENTER);
        titulo.setFont(new Font("Harlow Solid Italic",Font.BOLD ,40));
        titulo.setForeground(Color.RED);
        
        panel.add(titulo, BorderLayout.NORTH);
        panel.add(nombres, BorderLayout.CENTER);
        panel.add(volver, BorderLayout.SOUTH);
        
        this.add(panel);
        this.setSize(550, 400);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de Autores
     * @param actionListener
     */
    public void setActionListener(ActionListener actionListener ) {
        volver.addActionListener(actionListener);
    } 
}

























