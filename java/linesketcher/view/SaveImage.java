package es.uv.eu.LineSketcher.view;

import java.io.File;
import javax.swing.JFileChooser;

/**
 *
 * @author gabri
 */
public class SaveImage extends JFileChooser {
    
    /**
     * Constructor de SaveImage
     */
    public SaveImage() {
        super();
        this.setFileSelectionMode(JFileChooser.FILES_ONLY);
        this.setDialogType(JFileChooser.SAVE_DIALOG);
        this.setVisible(true);
    }
  
    /**
     *
     * @return
     */
    public File getFile() {
        int ret = showDialog(null, "Guardar imagen");

        if (ret == JFileChooser.APPROVE_OPTION) {
            return getSelectedFile();
        }
        else {
            return null;
        }
    }
}