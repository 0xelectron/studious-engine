#include"tictac.h"

/*
 * tictac: A Simple tictac game
 */
int
main(int argc, char *argv[])
{
	char c, w;
	const char *fn, *p;

	fn = "tictac.log";
	p = argv[0];

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'b':
				AIMODE = 1;
				break;
			case 'h':
				usage(p);
			default:
				printf("tictac: Illegal Option %c\n", c);
				argc = 0;
				break;
			}

	if ((f = fopen(fn, "a")) == NULL)
		fatal("could not open file %s for logging", fn);

	/* greet the user */
	greet();

	if (AIMODE)
		/* cpu vs cpu */
		aimode();
	else {
		/* ask for users currsors */
		asktic();

		/* initialize board */
		init();

		while (1) {

			/* draw the current state of board */
			draw();

			/* save the current state of board (for testing) */
			save(f);

			/* ask for user's move */
			while (!move(takeinput())) {
				printf("Illegal move!\n");
				usleep(500000);
			}

			/* check for win */
			if ((w = gameover()))
				break;

			/* sleep */
			usleep(500000);

			/* cpu's turn */
			cpumove();

			/* check for win */
			if ((w = gameover()))
				break;

			/* sleep */
			usleep(500000);
		}
	}

	/* draw the current state of board */
	draw();

	/* save the current state of board (for testing) */
	save(f);

	if (w == TIC)
		printf("ftw!\n");
	else if (w == CTIC)
		printf("I won buddy! better luck next time.\n");
	else
		printf("It's a tie! The game is on.\n");

	return 0;
}
