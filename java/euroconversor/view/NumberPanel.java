package es.uv.eu.euroconversor.view;

import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.JButton;
/**
 *
 * @author
 */

public class NumberPanel extends JPanel{
    private JButton[] botones = new JButton[10];

    private JButton coma;
    private JButton c;
    
    public NumberPanel(){
        
        this.setLayout(new GridLayout(3,4, 10, 10));
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        
        for(int i = 0; i < botones.length; i++)
        {
            botones[i] = new JButton(String.valueOf(i));
            botones[i].setActionCommand(String.valueOf(i));
            add(botones[i]);
        }
        
        coma = new JButton(".");
        coma.setActionCommand(".");
        c = new JButton("C");
        c.setActionCommand("C");
        
        add(coma);
        add(c);
    }
    
    public void setActionListener(ActionListener actionListener ) {
        
        for(int i = 0; i < botones.length; i++)
        {
            botones[i].addActionListener(actionListener);
        }
        
        coma.addActionListener(actionListener);
        c.addActionListener(actionListener);        
    } 
}