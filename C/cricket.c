#include <stdio.h>

struct cricket_player {
  char name[20];
  unsigned age;
  float batting_average;
  float bowling_average;
};

size_t MAX_INPUT = sizeof(struct cricket_player);

void print_players_with_age_greater_than(struct cricket_player *player, unsigned size, unsigned age);
float average_age_of_players(struct cricket_player *player, unsigned size);
static void print_player(struct cricket_player player);

int
main()
{
  int n = 60;
  struct cricket_player cricket_players[n];
  char *input;
  /**
   * assuming that the first 30 players are Australian Players,
   * whilst the second 30 players are Indian Players.
   */
  for (int i = 0; i < n; ++i) {
    printf("Please provided the input in following format: \n");
    printf("age, batting_average, bowling_average, name\n");
    getline(&input, &MAX_INPUT, stdin);
    sscanf(input, "%u, %f, %f, %s", &cricket_players[i].age, &cricket_players[i].batting_average,
        &cricket_players[i].bowling_average, cricket_players[i].name);
  }

  printf("\n\nAustralian Players with age greater than 25, are:\n");
  print_players_with_age_greater_than(cricket_players, n - 30, 25);

  printf("\n\nAverage age of Indian Players is: %.2f\n", average_age_of_players(&cricket_players[n - 30], n - 30));
}


/**
 * print_players_with_age_greater_than:
 * given an array of players
 * print all players with age greater than given age
 */
void
print_players_with_age_greater_than(struct cricket_player *players, unsigned size, unsigned age)
{
  for (int i = 0; i < size; ++i)
    if (players[i].age > age)
      print_player(players[i]);
}

/**
 * average_age_of_players:
 * given an array of players
 * return average age of the players
 */
float
average_age_of_players(struct cricket_player *players, unsigned size) {
  float average = 0;
  for (int i = 0; i < size; ++i)
    average += players[i].age;
  return average /= size;
}

static void
print_player(struct cricket_player player) {
  printf("------------------\n");
  printf("Name: %s\n", player.name);
  printf("Age: %u\n", player.age);
  printf("Batting Average: %.2f\n", player.batting_average);
  printf("Bowling Average: %.2f\n", player.bowling_average);
}
