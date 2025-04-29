
<a name="readme-top"></a>
<div align="center">

  <!-- Project Name -->
  <h1>So Long | PACMAN </h1>

  <!-- Short Description -->
  <p align="center">
	  <b>2D game in C</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-mandatory-part">🔷 Mandatory Part</a>
    <span> · </span>
	    <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
    <span> · </span>
      <a href="#-screenshots">🌄 Screenshots</a>
  </h3>
</div>

---

<p align="center">
  <img src="game_gifs/main_game.gif" alt="Game gif" />
</p>

## 📜 About Project

> 42 School So Long project is a small 2D game where the player has to collect items and reach the exit. \
> The project is designed to introduce the basics of game development and graphical programming, but I almost rewrote the complete original pacman.

For detailed information, refer to the [**subject of this project**](en.subject.pdf).

	🚀 TLDR: This project is an introduction to the basics of game development using the MiniLibX library.
    Learn about handling events, rendering graphics, and managing game states.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 🔷 Mandatory Part

#### The subject describes the game as follows:

* The player controls a character in a 2D grid-based map.
* The map contains walls, collectible items, and an exit.
* The player must collect all items and reach the exit to win.
* The game must be displayed in a window using the MiniLibX library.
* The player can move up, down, left, and right using the keyboard.

## 🌟 Bonus Part

#### The subject describes the game as follows:

* Player lose when they touch an enemy patrol.
* Add sprite animation.
* Display the movement count directly on screen instead of writing it in the shell.	

## 👨‍💻 Usage

## ⚠️ Attention | A must read
#### Frame Timing and Speed Adjustments

All timing-related constants discussed here are defined using #define and must not be modified programmatically. You should only adjust their numeric values directly in the header file.

The timing of animation and movement function calls is controlled by variables, meaning that each processor — depending on its power and processing speed — will produce different animation speeds.
To ensure a smooth and comfortable gameplay experience, you must adjust the main variable that controls the overall speed: GAME_FRAME_LIMIT, located in so_long.h.
You must also tune all other related constants declared using #define.
The value of GAME_FRAME_LIMIT should be a number that is a power of two — for example: 2048, 1024, 512, 256, 128, 64, etc.

#### Variable Descriptions

GAME_START_LIMIT and GHOST_FREEZE_LIMIT
At the beginning of the game (or when Pacman eats a ghost), a separate variable — the one being compared to these constants — is initialized to zero or a specific value.
This ensures that certain functions (like ghost movement) do not execute until the variable exceeds GAME_START_LIMIT, creating a brief pause or "freeze" effect.
When a ghost is eaten, the same variable is initialized to a value close to GAME_START_LIMIT — about 75% of it — defined as GHOST_FREEZE_LIMIT. This results in a slightly shorter freeze duration

GHOST_NEUTRAL_LIMIT and GHOST_ATTACK_LIMIT
In the game, all ghosts except the orange one have two modes: neutral and aggressive. In neutral mode, they target a predefined "home" corner on the map rather than Pacman. In aggressive mode, their target becomes Pacman himself.
In the original game, the neutral mode lasts 10 seconds, while aggressive mode lasts 30 seconds.
You need to determine when the variable being compared to GHOST_NEUTRAL_LIMIT will reach its limit in approximately 10 seconds.
Set that value to GHOST_NEUTRAL_LIMIT, and assign the same value multiplied by 3 to GHOST_ATTACK_LIMIT.
⚠️ Avoid using printf for this — it adds overhead and skews timing. Use lighter functions such as write.
(If you're using my libft, you can use the ft_putnbr_fd function.)

GHOST_PANIC_LIMIT and GHOST_PANIC_FLASHING_LIMIT
When Pacman eats a special pellet, he enters an "attack mode," gaining speed and the ability to eat ghosts. During this mode, all ghosts enter a panic state: they turn blue and flee from Pacman.
As the attack mode nears its end, ghosts start flashing between blue and white to indicate the mode is about to expire — this warns the player not to get too close to ghosts.
Once the mode ends, all ghosts resume behavior based on their current state: either neutral or aggressive.
GHOST_PANIC_LIMIT defines the total duration of the panic state, while GHOST_PANIC_FLASHING_LIMIT sets when the flashing phase begins.

DYING_FRAME_LIMIT
This constant applies only to Pacman. When he collides with a ghost, a death animation of 10 frames begins.
The higher the value of DYING_FRAME_LIMIT, the longer the animation takes to complete.

#### Pacman Controls and Keycodes

Each keyboard layout and operating system may assign different keycodes to physical keys.
For example, on Kali Linux, the W key might produce the keycode 119, while on Ubuntu it could be 1731. Changing the keyboard or layout will result in different codes.
To help with this, I’ve included a simple utility that lets you find the correct keycodes for your system.
Run the keycode executable located in the keycode directory. When the window opens, press a key and its keycode will be printed in the terminal.

#### The program takes the following arguments:
`./so_long <map_file>`
* The map must be a .ber file
