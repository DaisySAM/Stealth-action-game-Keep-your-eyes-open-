# Stealth-action-game-Keep-your-eyes-open-
I developed the first level of the game in C ++ on the game engine UnrealEngine4 (v 4.10)

The project implemented:

1. Game character (C ++ language).

    Movement, camera rotation, jump (C ++).

    Inventory (logic - C ++, visualization - Blueprint).
    
    Import skeleton, 3d model and animation. Configure the components.
    
2. Not a game character / opponent (C ++).

The NPC moves along the given points. When a Pawn Sensing Component is detected, the pursuit begins.

   Mechanics of motion (C ++).
    
   Motion logic (Behavior Tree and Black Board). In C ++, I wrote a task for BehaviorTree to find points for movement (TargetPoint) and assign them to variables in the Black Board.
    
3. Interactive subjects (C ++).

    Animation - rotation using the EvenTick event (C ++).
    
    Override the OnBeginOverlap event for the interaction of the game character and the object (pick up the item and place it in inventory) (C ++).
    
    No mapping (hiding the mesh component and collision), if the player picked it up (C ++).
    
4. Interface (widgets) (Blueprint).

[Illustrations of the project](https://github.com/DaisySAM/Stealth-action-game-Keep-your-eyes-open-/issues/1#issue-353031339)
