# Basic setup

* Lanes like in plants vs zombies but vertical
* 10 fields per lane
* 8 border 5x24 lanes 8 border 24 menu
* Enemies do not overlap
* towers can always shoot at their complete lane
* menu on the left size of one lane
    * resources
    * lifes
    * wave info
    * build menu

# Technical notes

* draw towers onto the background to not hit the sprite per row limit
* criters should only be 24 tiles wide to avoid 10 sprites per row limit

## Sprites

* 0-3 Cursor

* 10-29 Enemies
* 30-39 Bullets

# Towers

* Basic Tower: Cheap but does not do much damage
* Wall: Does not shoot but has a lot of hp to block enemies
* Heavy Tower: Shots slower but does high damage, good for strong enemies
* Slow Tower: low to no damage but slows down enemies
* Aoe Tower: hits multiple targets with low damage, good against large groups of weak enemies
* Money gen tower: does not shoot but generates oney for you

# Enemies

* Normal: the average guy, not to special
* Little critter: low life easy to kill, often in large groups
* Speedy: also low life but faster
* Fatty: slow but a lot of life
* Reeper: normal but does more damage
* Boss: slow, lot of hp and lots of damage

# Iterations

## First draft

* one type of tower
* one enemy
* no scrolling

## Second draft

* multiple enemies
* scrolling map

## Third

* build menu with multiple towers

## Fourth

* Upgrade towers?
* animations?

# Code

## Basic Features

* Tower placement
* Cursor 
    * Movement
    * Selection
* Enemy spaning
* Enemy behavious
    * Moving
    * Attacking
* Tower Fire

## File strucure

* towers.c
* enemies.c
* waves.c
* menu.c
* gbtd.c
* cursor.c
* sprites.c
* bg-sprites.c
* bg-data.map


## interface definitions

´´´

struct TowerDefinition {
    int hp
    int dmg
    int cooldown
    ??? sprites
    ??? projectile
}

struct EnemyDefinition {
    int hp
    int speed
    int dmg
    ??? sprites
}



struct Tower {
    int type
    int lane
    int row
    int hp
    int cooldown
}

struct Enemy {
    int type
    int x
    int y
    int hp
}

place_tower(int row, int lane, int type)


´´´