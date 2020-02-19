#include "lib/header.h"

int main(int argc, char **argv)
{
	Time = 1;

        gtk_init(&argc, &argv);

	GtkWidget* win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	label = gtk_label_new(" ");
	ValueGetter = gtk_label_new(" ");
	GtkWidget* btn   = gtk_button_new_with_label("get clock");
        GtkWidget* stop  = gtk_button_new_with_label("stop");
        GtkWidget* start = gtk_button_new_with_label("start");
	GtkWidget* ref   = gtk_button_new_with_label("refresh");
	GtkWidget* fix   = gtk_fixed_new();

	// desine
	GdkColor back;
        GdkColor btns;

	gdk_color_parse("#090909", &back);
        gdk_color_parse("#050505", &btns);

	gtk_widget_modify_bg(GTK_WIDGET(win),  GTK_STATE_NORMAL, &back);
        gtk_widget_modify_bg(GTK_WIDGET(btn),  GTK_STATE_NORMAL, &btns);
	gtk_widget_modify_bg(GTK_WIDGET(stop), GTK_STATE_NORMAL, &btns);
	gtk_widget_modify_bg(GTK_WIDGET(start),GTK_STATE_NORMAL, &btns);
	gtk_widget_modify_bg(GTK_WIDGET(ref),  GTK_STATE_NORMAL, &btns);


	gtk_window_set_title(GTK_WINDOW(win), "timer");

	//set size
	gtk_widget_set_usize(GTK_WIDGET(win), 180, 210);

	gtk_widget_set_usize(GTK_WIDGET(btn), 120, 29);
        gtk_widget_set_usize(GTK_WIDGET(start), 120, 29);
        gtk_widget_set_usize(GTK_WIDGET(stop), 120, 29);
	gtk_widget_set_usize(GTK_WIDGET(ref) , 120, 29);

	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(win), FALSE);

	// fix
	gtk_fixed_put(GTK_FIXED(fix), label, 60, 10);
        gtk_fixed_put(GTK_FIXED(fix), btn  , 30, 30);
        gtk_fixed_put(GTK_FIXED(fix), ValueGetter, 60, 175);
	gtk_fixed_put(GTK_FIXED(fix), stop , 30, 100);
	gtk_fixed_put(GTK_FIXED(fix), start, 30, 65);
	gtk_fixed_put(GTK_FIXED(fix), ref  , 30, 140);

	// signal
	g_signal_connect(win, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(btn,   "clicked"  ,  G_CALLBACK(printVal), NULL);
	g_signal_connect(stop,  "clicked"  ,  G_CALLBACK(Stop),	    NULL);
	g_signal_connect(start, "clicked"  ,  G_CALLBACK(Start),    NULL);
	g_signal_connect(ref,   "clicked"  ,  G_CALLBACK(Ref),      NULL);

	// thread
    	gdk_threads_init();

    	gdk_threads_enter();

    	 g_thread_create(ChangeValue, NULL,  FALSE, NULL);

	// show
	gtk_container_add(GTK_CONTAINER(win), fix);
	gtk_widget_show_all(win);
    	gtk_main();

    	/* Release gtk's global lock */
    	gdk_threads_leave();

    	return 0;
}

