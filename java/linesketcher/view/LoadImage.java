package es.uv.eu.LineSketcher.view;

import java.io.File;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 * @author gabri
 */
public class LoadImage extends JFileChooser {
    
    private static final String[] EXTENSIONES = { "jpg", "jpeg", "png", "gif",
        "tiff", "JPG", "JPEG" };
    
    /**
     * Constructor de LoadImage
     */
    public LoadImage() {
        super();
        FileNameExtensionFilter extensionFilter = new FileNameExtensionFilter("Imágenes", EXTENSIONES);
        this.setFileSelectionMode(JFileChooser.FILES_ONLY);
        this.setDialogType(JFileChooser.OPEN_DIALOG);
        this.setFileFilter(extensionFilter);
        this.setVisible(true);
    }
  
    /**
     *
     * @return
     */
    public File getFile() {
        int ret = showDialog(null, "Abrir imagen");

        if (ret == JFileChooser.APPROVE_OPTION) {
            return getSelectedFile();
        }
        else {
            return null;
        }
    }
}