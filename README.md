# Dev2Mem
A joystick or game controller software that shows you some device values and the memory address of them.
This program uses SDL2 to handle joysticks and game controllers.
I coded this to make a bridge from game devices to Cheat Engine but you can use it for everthing you want.
## How to compile
1. Open VS2010 (SHOULD WORK WITH OTHER VERSIONS)
2. Create a C++ Console Application
3. In the wizard check the Empty Project checkBox
4. Download SDL2 Development Libraries (I'm using 2.0.5 for Visual C++)
5. Go to project properties (For the configuration you will compile: Debug / Release. I compiled for release)
 * VC++ Directories -> Include Directiories -> Add <SDL2_DIR>\include
 * VC++ Directories -> Library Directories -> Add <SDL2_DIR>\lib\x86
 * Linker -> General -> Incremental Linker -> NO (/INCREMENTAL:NO)
 * Linker -> Input -> Additional Dependencies -> Add SDL2.lib and SDL2main.lib
6. Compile
7. Enjoy
