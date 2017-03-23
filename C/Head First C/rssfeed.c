#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char* argv[])

{

char *feeds[] = {"http://www.gsmarena.com/rss-news-reviews.php3","http://www.phonearena.com/feed","http://edition.cnn.com/ASIA/"};

int times = 3;
char *phrase = argv[1];
int i;
for (i = 0; i < times;i ++)
{
	char var[255];
	sprintf(var, "RSS_FEED=%s",feeds[i]);
	char *vars[] = {var,NULL};
	if(execle ("/usr/bin/python","/usr/bin/python","./rssgossip.py",phrase,NULL,vars)==-1)
{
	fprintf(stderr,"Can't run script: %i \n",strerror(errno));
	return 1;
}
}
return 0;
}
