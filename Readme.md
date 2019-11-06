# Overview

It's a simple console game.

This repo was created as a part of a homework during a course about Operating Systems. It's a rewrite of WinApi-based single file project with the same logic. Main goal is to use C++ library and principles of OOP to reimplement everyting without using WinApi (where possible).

# Progress

## TODO

- [ ] Project is not friendly for extension via inheritance
- [ ] Enemies are too close to the player (there are no rows between him and enemies)
- [ ] Too many time constants in the code

## Done

- [x] Enemies are spawning in the same line as player
- [x] Player can go too far away
- [x] Game screen dimensions are hardcoded
- [x] Bullets don't spawn
- [x] Enemies' animations are incorrect when moving RTL
- [x] Spawner spawns too many enemies
- [x] Console header has several double spaces
- [x] Bullet spawns at the spot of the player
- [x] Lose condition seems to not work
- [x] It seems that cursor isn't hidden during play
- [x] Game components can store shared pointers to game instance. Replace them with weak pointers.
- [x] Make InputComponent either a part of Player or a part of GameInstance
