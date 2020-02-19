#include "lib/header.h"


void ChangeValue()
{
        mil = 0;
        sec = 0;
        min = 0;
        hor = 0;

        for(int i = 0; 1; i++)
        {
                for(int i = 0;Time == -1; i += Time);

                mil++;
                if(mil % 100 == 0)
                {
                        sec++;
                        mil = 0;
                }

                if(sec % 60  == 0 && sec != 0)
                {
                        min++;
                        sec = 0;
                }

                if(min % 60 == 0 && min != 0)
                {
                        hor++;
                        sec = 0;
                }

                sprintf(str, "%d:%d:%d:%d", hor, min, sec, mil);

                gdk_threads_enter();

                gtk_label_set_text(GTK_LABEL(label), str);

                gdk_threads_leave();
                usleep(10000);
        }
}

void printVal()
{
        gtk_label_set_text(GTK_LABEL(ValueGetter), str);
}

void Stop()
{
	Time = -1;
}

void Start()
{
	Time = 1;
}

void Ref()
{
	mil = 0;
	sec = 0;
	min = 0;
	hor = 0;
}

