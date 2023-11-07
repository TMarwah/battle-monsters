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
![swat-team-diagrams-navigation diagram drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/0faa0ec5-8d0e-4964-85ff-40a1cefadf8d)

This Navigation Diagram represent the linear structure of game phases with the only potential of replay loop. 


### Screen Layouts
 ![swat-team-diagrams-Screen Layouts drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/414ea81e-d23b-4bf6-8997-2243a13849d3)


## Class Diagram
![swat-team-diagrams-class diagram drawio](https://github.com/cs100/final-project-wkim107-tmarw001-szhan240-atill006/assets/115139825/4fa120fb-d3da-43fc-a0a0-e71e545c91a7)

 The game will be state driven and the superclass States is inherited by all other objects. The Game class is responsible for movement through the phases of the game. Player and Draft class are composed within Game to initialize and then branch out to other classes to build up the game logic.


 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
