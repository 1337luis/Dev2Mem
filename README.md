# Dev2Mem
A joystick or game controller software that shows you some device values and the memory address of them.
This program uses SDL2 to handle joysticks and game controllers.
I coded this to make a bridge from game devices to Cheat Engine but you can use it for everthing you want.
##### You will need Microsoft Visual C++ 2010 Redistributable Package (x86)
[Download Here](https://github.com/1337luis/Dev2Mem/releases/latest)

## How to compile
1. Open VS2010 (SHOULD WORK WITH OTHER VERSIONS)
1. Create a C++ Console Application
1. In the wizard check the Empty Project checkBox
1. Download SDL2 Development Libraries (I'm using 2.0.5 for Visual C++)
1. Go to project properties (For the configuration you will compile: Debug / Release. I compiled for release)
   1. VC++ Directories -> Include Directiories -> Add <SDL2_DIR>\include.
   1. VC++ Directories -> Library Directories -> Add <SDL2_DIR>\lib\x86.
   1. Linker -> General -> Incremental Linker -> NO (/INCREMENTAL:NO).
   1. Linker -> Input -> Additional Dependencies -> Add SDL2.lib and SDL2main.lib.
1. Compile
1. Enjoy
### Links
* SDL2 Development Libraries for Visual C++ https://www.libsdl.org/release/SDL2-devel-2.0.5-VC.zip
* Microsoft Visual C++ 2010 Redistributable(x86) https://www.microsoft.com/es-es/download/details.aspx?id=5555
