#include <gtk/gtk.h>

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GdkScreen *screen;
    GtkWidget       *window;
    GtkWidget       *image;
    GtkWidget *frame;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);
    screen = gdk_screen_get_default();
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_screen (GTK_WINDOW (window), screen);
    gtk_window_set_title (GTK_WINDOW (window), "rolling_cat");

    g_signal_connect (window, "destroy",
                      G_CALLBACK (on_window_main_destroy), NULL);

    gtk_container_set_border_width (GTK_CONTAINER (window), 8);

    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 8);
    gtk_container_set_border_width (GTK_CONTAINER (vbox), 8);
    gtk_container_add (GTK_CONTAINER (window), vbox);

    frame = gtk_frame_new (NULL);
    gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_widget_set_halign (frame, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (frame, GTK_ALIGN_CENTER);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);

    image = gtk_image_new_from_file ("image.gif");

    gtk_container_add (GTK_CONTAINER (frame), image);
    gtk_widget_show_all (window);
    gtk_main();

    return 0;


}

