# Solitaire

The objective of this practice is the implementation of the **Pila** abstract data type and its use in the simulation of a solitaire of Spanish cards.

The game requires the management of different piles that will represent the different decks of cards involved in the game, and consists of moving a card from one deck to another until it is not possible to make valid movements or to have all the cards of the same suit piled up in their corresponding pile. In the game, a Spanish deck with **48 cards (4 suits with 12 cards each)** is used, each card being represented with a number and a character that indicates the suit ('O', 'C', 'E', 'B'). Before starting the game, the program generates the deck (in the form of a pile) and proceeds to shuffle the cards so that they are not ordered. Next, the initial state of the game requires the creation the following piles of cards, in addition to the deck itself: 
- **4 piles** where the cards of each of the suits will be piled up: Oros, Copas, Espadas and Bastos. 
- **7 piles** on the table: deck1, deck2, deck3, deck4, deck5, deck6, deck7. 
- **1 Auxiliary pile.** 

The game begins by distributing the cards from the deck in the following way: 
- **5 cards** in the Auxiliary pile 
- **1 card** in each of the piles of the table (deck1 .. deck7) 

From there the program allows the player to perform card movements between the different piles, taking into account that in each movement only one card is moved and that the pile from which it is removed (top of the pile) and the pile to which it is taken must be indicated. The possible movements are: 
- **Towards the piles of suits (Oros, Copas, Espadas,Bastos):**
	- When they are empty, only the “ace” (B1, C1, E1, O1) of the corresponding suit can be moved from any pile except of the deck. 
	- When they contain any card, only another one of the same suit and a superior unit can be placed from any pile except from the deck.
- **Towards the work stacks (deck1 .. deck7):**
	- When empty, the user can move any card from any stack except from the deck. 
	- When they contain a card, only one of a different suit and a lower unit can be placed from any pile except the deck.

# Result

Initial Stage             |  Playing  |  Winner
:-------------------------:|:-------------------------:|:-------------------------:
![Initial](https://user-images.githubusercontent.com/96742277/149896326-1c93cf70-a85a-446f-a6f4-e59e5eed7041.JPG) | ![Playing](https://user-images.githubusercontent.com/96742277/149896424-926238c2-da7a-456d-94f5-30e5c5a9ac7d.JPG) | ![Winner](https://user-images.githubusercontent.com/96742277/149896486-a43fa96a-5861-4b8a-805e-11c8ff885bc7.JPG)




