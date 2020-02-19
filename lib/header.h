#include <gtk/gtk.h>
#include <unistd.h>

#ifndef HEADER_H_
#define HEADER_H_

int Time;

int mil;
int sec;
int min;
int hor;

GtkWidget* label;
GtkWidget* ValueGetter;

void  ChangeValue();
void printVal    ();
void Stop	 ();
void Start	 ();
void Ref	 ();

char str[1024];



#endif /* header.h */
