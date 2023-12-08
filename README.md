![Deploy badge](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/actions/workflows/main.yml/badge.svg)  
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
![swat-team-diagrams-SOLID class diagram drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/114537897/8abda0ac-0a20-4df7-9641-80c375372225)

## Class Diagram reflection after using S.O.L.I.D. principles to improve the design

### Single Responsiility Principle (S):
- We created an input class and display class to handle input and display responsibilities (**Single Responsibility Principle**). The change we made was by incorporating a new class boxes to our diagram labeled input class and display class, assigning functions to their respective classes to handle specific functionality. By following the guidelines of the first principle our code looks a lot cleaner and less clumped up together.
<img width="218" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/36d7302f-494b-42f1-bf84-bff64b81daa8">


### Open-Closed Principle (O):
- We created a Monster class that aligns with the **Open-Closed Principle** because it has a vector of `MoveSet *` which is open to extension by the Liskov's Substitution Principle. But this does not require Monster class to change its code (closed for modification). This is an example from our previous diagram that contains the Open-Closed Principle.
  
<img width="317" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4895db2b-586f-4a93-9ad9-aedb78766299">


### Liskov's Substitution Principle (L):
- We created a `MoveSets` class that aligns with the **Liskov's Substitution Principle** because it is replaceable with instances of their subtype(specific moves) without altering the correctness of that program. Since we already have a class that contains similar qualities of the Liskov's Substitution principle we decided to use it as an example. The below image showcases the `MoveSets` class that we decided to use.

<img width="337" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4010e9e3-e762-417a-a54c-27d30e943d2b">


### Interface Segregation Principle (I):
- All of the classes within our class diagram adhere to the **Interface Segregation Principle**. This is because we have made sure that all our classes require all interfaces of the class they depend on to be implemented and no classes implement unused interfaces.

<img width="239" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/99a13975-2b28-407a-96e4-bb01fc5f0d7b">


- For example, here, every object of the Monster class requires full implementation of a MoveSet object to be utilized. No MoveSet member goes unused.

### Dependency Inversion Principle (D):
- The monster class is not dependent on the MoveSet class. But it depends on the abstraction of the Movesets in the `MoveSet` class. This is an example of the Dependency Inversion Principle that our class diagram has.

![image](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/12e805a9-55f9-4e3b-8f88-cc86dd7b3d43)


 
 ## Screenshots
 <img width="350" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/b41a0526-4b0d-4a22-9ef3-8240bf1f5b66"> <br />

 <img width="314" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/26939172-c412-4d6e-8699-1ecf073d8045"> <br />

 <img width="356" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/ad023d93-497e-4954-9193-2a24a7687a80"> <br />

 <img width="236" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/ec014b54-aed5-439c-83f5-92553a2a5735"> <br />

 <img width="335" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4ef801a5-bc86-40a2-905c-22e0f660803c"> <br />

 <img width="326" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/34d83a4c-8c23-4837-9028-330a002848b6"> <br />

 <img width="323" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/6e94ac1d-71f8-4ed0-9a2c-3c35be398254"> <br />

 <img width="323" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/123ad511-18d6-465b-b194-1eb305d82a23"> <br />

 <img width="277" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/129a9a01-0ba2-4ffc-93a8-1b45ef046d3c"> <br />

 <img width="315" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/5672ecff-7e98-4c7f-8203-e648269dc849"> <br />

 <img width="356" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/ad023d93-497e-4954-9193-2a24a7687a80"> <br />

 <img width="303" alt="image" src="https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/b0bc2994-5f1a-4ec7-b0cd-90ee43293966"> <br />

 ## Installation/Usage
  To build Monster Battle, execute the following from within the project directory
 ```
 cmake . -B build
 cd build
 make
 ```
 To run the executable
 ```
 ./bin/monsterBattle
 ```
 The game will prompt the user for there inputs. Enjoy! 😃
 ## Testing
  To build and execute the test, execute the following from within the project directory
 ```
 cmake . -B build
 cd build
 make
 ```
 To run the test
 ```
 ./bin/runAllTests
 ```
 The test will be executed accordingly! 
 Also you can checkout the CI badge at the top of `README.md`
 
