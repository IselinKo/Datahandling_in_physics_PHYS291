Notes and links; about ctime, time_t      etc   

time_t tt; struct tm * ti; 
time(&tt); ti = localtime(&tt); asctime(ti)

time_t tt; tm *ti;

time(&tt); asctime(localtime(&tt))


http://www.cplusplus.com/reference/ctime/strftime/


==================== save and compile - C-file ==================
/* strftime example */
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"Now it's %I:%M%p.",timeinfo);
  puts (buffer);

  return 0;
}
==================== END save and compile ==================


DATE ONLY:

  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
 strftime (buffer,80,"%F",timeinfo)
 strftime (buffer,80,"Now it's %I:%M%p.",timeinfo);
buffer
strftime (buffer,80,"%F",timeinfo)
buffer
cout << buffer << endl;
