# Battle Monsters
Authors: [Andrew Tilles](https://github.com/antilles183), [Tanmay Marwah](https://github.com/TMarwah), [Stanley Zhang](https://github.com/StanleyZhang0), [William(Dongyeon) Kim](https://github.com/WilliamEKim)


## Project Description
A two player battle strategy game where each player has a team of monsters at their command. With monsters of different strengths and weaknesses it's up to our players to use the right strategies to emerge victorious!

> The reason why our project idea of "Battle Monster" is important or interesting to our group is that,
1. We all love games
2. We want make the world a little more fun and interesting by making this game
3. It’s also a statistical challenge by collecting battle data of tactics

> The languages or tools our group is planning to use
* C++
* terminal (command line) for its execution

> Main Input/Output for our project will be...
 * Input: Command line inputs to select options from a menu
 * Output: Battle details such as damage taken, remaining health, and usable moves

> Our project provides feature as...
 * Players 1 and 2 are given 6 random characters to choose from, and they take turns to select 3 each (draft)
 * Battle menu with move-set selection
 * Characters have unique types with advantages/disadvantages
 * Moves have accuracy percentage that can result in some moves missing
 * Being able to swap between battle monsters
 * Display victory(battle result) and Generate file(such as .txt) for the battle log


## User Interface Specification

### Navigation Diagram
![swat-team-diagrams-navigation diagram의 복사본 drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/114537897/8daa761c-685a-4962-b2b9-df8d75c41fca)


This Navigation Diagram represent the linear structure of game phases with the only potential of replay loop. 


### Screen Layouts
 <img width="295" alt="Screen  1" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/9d93a2d4-37eb-4ffd-90ce-36b1ce0c4cc8">
 
 
 Title Screen



 <img width="229" alt="Screen  2" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/dc40bebc-9efc-4a08-a033-71518e73ce64">
 
 
 Players are prompted for their names



<img width="346" alt="Screen  3" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/bd3c1de0-c3e9-40b2-a1c0-30c2b7121b3a">


Draft Board Screen Layout:
* We se our two players, their empty stables (soon to have monsters), and the monsters available for drafting. We can also see each monsters type.
* Players take turns and are prompted to select an available monster by the monsters indicator



<img width="355" alt="Screen  3 5" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/20044b09-2d0d-4869-90b3-97933c918133">


As Monsters are selected they move from the draft board to the player's stable



<img width="366" alt="Screen  4" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/347905f8-8f35-4275-9157-73ff3c7ad574">


Fight Screen Layout:
* Most of the game takes place in this layout as the battle continues until one of the players is out of monsters.
* We can see all the pieces needed to play the game. Players, monsters, and monster data like its type and health meter. In the center are each players active monsters (the ones currently fighting)
* The moves available to players are seen below. Moves will include different attacks and swapping out the active monster for a different one



<img width="218" alt="Screen  5" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/7e788f4d-a532-4f56-9c69-441316a564c8">


Endgame Screen Layout:
* When one of the players is outof Monsters we have a winner. The option to play again (or quit) is given




<img width="211" alt="Screen  6" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/3074cf81-aca3-435f-ad4c-a4066f573c67">

Quit Game Screen Layout:
* When the game is quit, a nice goodbye message is shown before program exit.




## Class Diagram
![swat-team-diagrams-class diagram drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4fa120fb-d3da-43fc-a0a0-e71e545c91a7)

 The game will be state driven and the superclass States is inherited by all other objects. The Game class is responsible for movement through the phases of the game. Player and Draft class are composed within Game to initialize and then branch out to other classes to build up the game logic.

## Class Diagram after incoporating S.O.L.I.D. principle guidelines

## Class Diagram reflection after using S.O.L.I.D. principles to improve the design

### Single Responsiility Principle (S):
- We created an input class and display class to handle input and display responsibilities (**Single Responsibility Principle**)

### Open-Closed Principle (O):
- We created a Monster class that aligns with the **Open-Closed Principle** because it has a vector of MoveSet * which is open to extension by the Liskov's Substitution Principle, but does not require Monster class to change its code (closed for modification).
  
<img width="317" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4895db2b-586f-4a93-9ad9-aedb78766299">


### Liskov's Substitution Principle (L):
- We created a MoveSets class that aligns with the **Liskov's Substitution Principle** because it is replaceable with instances of their subtype(specific moves) without altering the correctness of that program.

<img width="337" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4010e9e3-e762-417a-a54c-27d30e943d2b">


### Interface Segregation Principle (I):
- All of the classes within our class diagram adhere to the **Interface Segregation Principle** as we have made sure that all classes require all interfaces of the class they depend on to be implemented and no classes implement unused interfaces

<img width="239" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/99a13975-2b28-407a-96e4-bb01fc5f0d7b">


- For example, here, every object of the Monster class requires full implementation of a MoveSet object to be utilized. No MoveSet member goes unused.

### Dependency Inversion Principle (D):
- /**Blank**/

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
