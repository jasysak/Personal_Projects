// A stand-alone GUI Java program to display a friendly greeting.
// Also added code to close the application when the user clicks
// the mouse in the close box.

// Written by Wayne Pollock, Tampa, FL USA, 1999

// Modified by Jason Sysak, Tampa, FL USA, 2018

import java.awt.*;
import java.awt.event.*;

public class GUIGreet extends Frame
{
   private String message = "Hello, World!";

   public GUIGreet ()
   {
      setTitle( "A Friendly Greeting" );
      setSize( 300, 200 );
      setVisible( true );

      addWindowListener(
         new WindowAdapter()
         {  public void windowClosing( WindowEvent e )
            {  System.exit( 0 );
            }
         }
      );
   }

   public static void main ( String [] args )
   {
      GUIGreet me = new GUIGreet();
   }

   public void paint ( Graphics g )
   {
      g.setColor( Color.RED );
      g.drawRect( 30, 40, 240, 130 );
      g.setColor( Color.BLUE );
      g.setFont( new Font( "SansSerif", Font.BOLD, 24 ) );
      g.drawString( message, 70, 110 );  // Position determined
   }                                     // by trial and error!
}
