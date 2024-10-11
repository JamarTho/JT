**Classes**

- Player Class:

   *Data:

      *name
      *score
      *dice_set: Array of Dice objects
      *player_stats
  
Actions:

roll_dice(): Roll the dice for the player.
get_score(): Retrieve the current score.
update_score(points): Update the player’s score after each roll.
Relationships:

A Player HAS-A Dice (composition).

Leaderboard Class:(Possible)

Data:

entries
max_entries
name
score
player_stats

Actions: 

entries: A list of player scores, which can include player names and scores.
max_entries: The maximum number of entries to display 
add_entry(name: str, score: int): Adds a new entry to the leaderboard, maintaining the highest scores.
get_top_entries(): Returns the top entries in the leaderboard.
resetleaderboard(): Clears the leaderboard, if necessary.

A entry has a name (composition).


Multiplayer Class: (necessity)

Data:

players: List of connected players.
game_instance: The current instance of the Knucklebones game being played.
player_count: Number of players currently in the game.

Actions:

add_player(player: Player): Adds a new player to the current game.
remove_player(player: Player): Removes a player from the game if they leave.
start_multiplayer_game(): Initializes a multiplayer game session.
get_player_list(): Returns the list of current players.

Relationships:

This class could manage instances of the Player and Knucklebones classes (composition).


Level Class: (Wishful)

Data:

current_level: Current level of the game.
difficulty: Difficulty of level
max_levels: Maximum number of levels available.
Actions:

next_level(): Advances to the next level, potentially increasing difficulty.
reset_level(): Resets to the first level.
get_difficulty(): Returns the current difficulty settings.

Relationships:

Can be used with game or knucklebones class  (composition).
