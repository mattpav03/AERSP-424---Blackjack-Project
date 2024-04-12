Blackjack in C++
 
Description:
This C++ program allows for a 1v1 game of blackjack against the computer. The objective of Blackjack is for players to beat the dealer's hand without exceeding a total sum of 21 points. 

This can be achieved through various means:
Getting 21 points on the initial two cards dealt, known as a "blackjack".
Attaining a higher total score than the dealer without going over 21.
Allowing the dealer to draw additional cards until their hand exceeds 21, resulting in a “bust”.

The program consists of a regular 52 card deck with the four suits: 
Hearts
Spades
Clubs
Diamonds

And the 13 cards with their respective point values:
Ace = 1 OR 11
2 - 10
Jack = 10
Queen = 10
King = 10


How to Play the Game:
All the files necessary to run the program are included in the “AERSP 424 - Blackjack Project” zip file. To run the program, unzip the provided folder to a known location. Within the folder, open the “BlackjackGame.cpp” file in Microsoft Visual Studio. Open the project and press the “Local Windows Debugger” button at the top. This will cause the code to begin to run. 


At the start of play, the code will give the user two cards face up and the dealer (the computer) one card face up and one card face down. The output of the program for this section will look like:
“Player’s hand: # Suit # Suit (Total Value)
Dealer’s hand: # Suit”


Once the dealing is complete, if someone was dealt an Ace (11 points) and a card worth 10 points (10, Jack, Queen, King) they automatically win with a “Blackjack” and the following message will be outputted:
“Congrats you have Blackjack. You win!!”

If no one was dealt one of these hands, the action moves on to the player. If the player is dealt two cards of different values they will have two options, to “hit”, or “stay”. If the cards are the same value a third option will be available, which will be explained further. To “hit” means to receive another card from the deck to try and get closer to 21 than the dealer. To “stay” means to receive no more cards and to compete with the dealer with what is shown, but the dealer cannot stay with a total value below 17. If the player or dealer hits and obtains a point value above 21 they “bust” which means they lose. 


When the player is able to hit or stay the following message will appear:
“Hit or Stand? (h/s)”

The player must then choose to type “h” for hit or “s” for stay on the command line and hit enter. This will be repeated until the player either stays or busts.
 
If at the end of the hand both the player and dealer have the same point value, it is called a “push” which is basically a tie and the following message will appear: 
“It’s a push.”

If at the beginning of play the player was dealt two cards of the same value they have the option to “split”. This means the cards become the first of a new hand and two new cards are dealt out. The user then plays out two hands separately against the dealer. However, this is optional and not a required step. If the hand is able to be split the following message will pop up:
“Split, Hit or Stand? (p/h/s)”


The player must then choose to type “p” to split,  “h” to hit or “s” to stand on the command line and hit enter. Once an option is selected the game will continue as normal with the options to hit or stay until the game is over. 


Once the game has ended one of two messages will be presented. The following message will be displayed if the player wins:
“Player wins!”

And the following message will be displayed if the player loses:
“Dealer wins”


To play another game or stop the program the user may type “y” for yes to playing another game or “n” for no, after this message pops up:
“Do you want to play again? (y/n)”


After eight hands the game will automatically stop because there will be no more cards in the deck to play with. To keep playing the game, the code must be rerun. When this occurs the following message will be displayed:
“The deck has no more cards.” 


References: fengvyi. (Year). Blackjack. GitHub. https://github.com/fengvyi/Blackjack.git
