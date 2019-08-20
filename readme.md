# Particle_Explosion

A simple particle explosion simulation using SDL library for 2D gaming.

## Setup
It was tested on Ubuntu: 16.04 with gcc-version: 7.3, should work with previous version as well.

## How to run
You will need to install SDL library first, kindly follow instructions based on your OS from following link:  
https://wiki.libsdl.org/Installation  

Once installed navigate to your particle explosion directory and make a directory called bin then,  
Compile with:  
```
g++ src/main.cpp src/particle.cpp src/swarm.cpp src/screen.cpp -lSDL2 -o bin/explosion  
```

Run with:  
```
./bin/explosion 500 
```

When executed it will create 500 particles in the centre of the screated screen, and they will move in the form of an explosion. You can change number of particles by changing the number to any other integer number while executing (default is set to 10000). After execting you should see an explosion as shown in the results section.

## Results

<p align="center">
  <img src="https://raw.githubusercontent.com/choco83/particle-simulation/master/result/explosion.png" width="450" /> 
</p>