package es.uv.eu.euroconversor.view;

import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JPanel;
import javax.swing.JButton;
/**
 *
 * @author EU 
 */
public class ClearPanel extends JPanel{
    private JButton clear;
    
    public ClearPanel(){
        
        this.setLayout(new GridLayout(1,1));
        
        clear = new JButton("Clear");
        clear.setActionCommand("Clear");
        
        add(clear);
    }
    
    public void setActionListener(ActionListener actionListener ){
        clear.addActionListener(actionListener);
    }
}