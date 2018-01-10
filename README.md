# AlonsoCarlos_BombermanTest
Repository for Bomberman UE4 test

- Project was done using version 4.18.2.
- Finished in approximately and accumulated 20 hours.
- Project was started using the C++ Top Down Game Template,
  the Mannequin and the Starter Content Folder and all their
  content came with the template. The only exception is the
  Bomberman Main Theme .wav file, which was downloaded from
  YouTube.
- Everything in the TopDownCPP folder is new and original.

-------------------------------------------------------------

PLAYER 1 CONTROLS:
- Movement: WASD keys
- Place Bomb: Spacebar

PLAYER 2 CONTROLS:
- Movement: Arrow keys
- Place Bomb: Right Ctrl key

POWER UPS
- Extra Bomb: blue token. Lets player place one more bomb at the same time.
- Longer Blast: red token. Bomb's linear blast extends by one grid spot in
  the four directions.
- Speed Boost: green token. Player's speed increased by 10%.
- Remote Bomb: yellow token. Changes player's arsenal to a remote controlled
  bomb for 10 seconds. Press the "Place Bomb" key again to trigger it. If 
  another Remote Bomb PowerUp is picked up during this PowerUp's duration,
  the timer will be reset to 10 seconds. If the time runs out, bomb will
  automatically go off.

KNOWN BUGS:
- Bombs' explosion effect from previous game lingers in the scene after starting
  new game.
- PowerUp colors might not show up.

IF I WERE TO CONTINUE WORKING ON THIS:
- Create Main Menu and Pause Menu.
- Implement AI for enemies and for a second player.
- Score system based on player's performance.
- Different levels and progression.
