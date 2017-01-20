#include"tictac.h"

size_t MAXLINE = 10;

/* To represent empty tic */
char EMPTY = ' ';

char *line = NULL;


/*
 * usage: print usage and exit
 */
void
usage (const char *p)
{
	printf("%s: An TicTacToe Game!\n", p);
	printf("Options:\n"
	       "-b \t botmode\n"
	       "-h \t this help message\n");
	exit(0);
}

/*
 * init: Initializes the board for the new
 * tictac game.
 */
void
init ()
{
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			BOARD[i][j] = EMPTY;
}

/*
 * greet: Greet User.
 */
void
greet ()
{
	clear();
	printf("Welcome to TicTacToe!\n");
	usleep(500000);
}

/*
 * asktic: asks user to choose the tic
 */
void
asktic ()
{
	do {
		printf("What would you like your tic to be? (X or O): ");
		getline(&line, &MAXLINE, stdin);

		if ((strlen(line) == 2) && isalpha(line[0])) {
			if (line[0] == 'X' || line[0] == 'x') {
				TIC = 'X';
				CTIC = 'O';
				break;
			} else if ( line[0] == 'O' || line[0] == 'o') {
				TIC = 'O';
				CTIC = 'X';
				break;
			}
		}
	} while (1);
}

/*
 * takeinput: asks user for input
 * returns the unsigned input
 */
unsigned
takeinput ()
{

	/* prompt for move */
	while (1) {
		printf("Where to put tic?: ");
		getline(&line, &MAXLINE, stdin);
		if ((strlen(line) == 3) &&
		    (isdigit(line[0]) && isdigit(line[1])))
			break;
	}
	return atoi(line);
}

/*
 * move: move if possible
 */
int
move (unsigned m)
{
	int i, j;
	i = m / 10;
	j = m % 10;
	if (i > 2 || j > 2)
		return 0;
	else if (BOARD[i][j] != EMPTY)
		return 0;
	else
		BOARD[i][j] = TIC;

	return 1;
}

/*
 * cpumove: cpu's turn to move
 */
void
cpumove ()
{
	int choices[9];
	int i, j, r, count;

	count = 0;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			if ( EMPTY == BOARD[i][j])
				choices[count++] = (i * 10) + j;
	r = choices[rand() % count];
	BOARD[(r / 10)][(r % 10)] = CTIC;
}

/*
 * won: returns the tic of the player, if game is won by the player,
 * else return 0.
 */
int
won (void)
{
	int i;

	if ((BOARD[0][0] == BOARD[1][1]) &&
	    (BOARD[0][0] == BOARD[2][2])) {

		if (BOARD[0][0] == TIC)
			return TIC;
		else if (BOARD[0][0] == CTIC)
			return CTIC;

	} else if ((BOARD[0][2] == BOARD[1][1])&&
		   (BOARD[0][2] == BOARD[2][0])) {

		if (BOARD[0][2] == TIC)
			return TIC;
		else if (BOARD[0][2] == CTIC)
			return CTIC;

	}
	for (i = 0; i < 3; ++i) {
		if ((BOARD[i][0] == BOARD[i][1]) &&
		    (BOARD[i][0] == BOARD[i][2])) {

			if (BOARD[i][0] == TIC)
				return TIC;
			else if (BOARD[i][0] == CTIC)
				return CTIC;

		} else if ((BOARD[0][i] == BOARD[1][i]) &&
			   (BOARD[0][i] == BOARD[2][i])) {

			if (BOARD[0][i] == TIC)
				return TIC;
			else if (BOARD[0][i] == CTIC)
				return CTIC;

		}
	}

	return 0;
}

/*
 * gameover: checks if the game is over.
 */
int
gameover (void)
{
	int i, j, go;

	if ((go = won()))
		return go;

	go = 1;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			if (EMPTY == BOARD[i][j])
				go = 0;
	return go;
}


/*
 * save: save board state to logfile.
 */
void
save (FILE *f)
{
	int i, j;
	if (!f)
		return;
	fprintf(f, "{");
	for (i = 0; i < 3; ++i) {
		fprintf(f, "(");
		for (j = 0; j < 3; ++j)
			fprintf(f, "%c, ", BOARD[i][j]);
		fprintf(f, "), ");
	}
	fprintf(f, "}\n");
}

/*
 * clear: clear the screen.
 */
void
clear ()
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

/*
 * draw: draw the board.
 */
void
draw ()
{
	/* clear the screen */
	clear();

	printf("\n\n");
	printf("\t\t\t %c | %c | %c \n", BOARD[0][0],
	       BOARD[0][1],BOARD[0][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n", BOARD[1][0],
	       BOARD[1][1],BOARD[1][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n", BOARD[2][0],
	       BOARD[2][0],BOARD[2][2]);
	printf("\n\n");
}

/*
 * aimode: play CPU VS CPU
 */
void
aimode ()
{
	/* TODO */
	return;
}

/*
 * fatal: logs fatal errors to stderr and logfile
 * and exits.
 */
void
fatal (const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "[!] fatal: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	t_log(f, fmt, args);
	va_end(args);
	exit(1);
}

/*
 * log: logs error and any other information to logfile.
 */
void
t_log (FILE *f, const char *fmt, void *args)
{
	if (!f)
		return;
	fprintf(f, "[!] fatal");
	vfprintf(f, fmt, args);
	fprintf(f, "\n");
}
