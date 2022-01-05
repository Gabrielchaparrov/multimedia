/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package es.uv.eu.LineSketcher.view;

import es.uv.eu.LineSketcher.model.LineSketcherModel;
import java.awt.AlphaComposite;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

/**
 *
 * @author Gabriel Chaparro y María Navarro
 */
public class ImagePanel extends JPanel{
    private LineSketcherModel model;
    
    /**
     * Constructor de ImagePanel
     * @param model
     */
    public ImagePanel(LineSketcherModel model){
        this.model = model;
    }
    
    /**
     * Devuelve la imagen actual
     * @return
     */
    public BufferedImage getImagen()
    {
        return model.getImagen();
    }  
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.drawImage(model.getImagen(), 15, 15, null);
    }
    
    /**
     * Se asignan los listeners necesarios a los componentes de ImagePanel
     * @param e
     */
    public void setMouseListener(MouseListener e){
        this.addMouseListener(e);
    }
}

