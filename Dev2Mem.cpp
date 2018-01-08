/****************************************************/
/*************** CODED BY luis1337 ******************/
/************** luis1337@outlook.es *****************/
/****************************************************/
/************** Compile with VS2010 *****************/
/****************************************************/
/*********** Luis Ángel Santos Herrero **************/
/*__________________________________________________*/
/****************************************************/
/************ 28/04/2017 Burgos, Spain **************/
/*__________________________________________________*/



#include <stdio.h>   //STD INPUT & OUTPUT
#include <Windows.h> //FOR THE CONSOLE CMDs
#include <iostream>  //INPUT & OUTPUT STREAM, TO SHOW THE INTERFACE (std::cout & std::endl;)

#include <SDL.h> //SDL FOR HANDLING INPUT DEVICES

//CONST DECLARATION FOR JOY HANDLER WINDOW SIZE
const int SCREEN_WIDTH = 6;
const int SCREEN_HEIGHT = 4;

//VARIABLE DECLARATION
int			LX, LY, RX, RY, b1, b2, b3, b4;
int			curX, curY;
POINT			p;
std::string joyName = 	"";

//FUNCTION PROTOTYPES
bool			init();
void			close();
static void		updateValues();

//SDL DECLARATIONS
SDL_Joystick*	myJoy 		= NULL; //JOYSTICK OBJ
SDL_Window*	gWindow		= NULL; //SDL WINDOW
SDL_Surface*	gScreenSurface 	= NULL;
SDL_Surface*	gSurface 	= NULL;

//MAIN FUNCTION WITH ARGS, IF YOU WANT TO ADD ARGS TO THE PROGRAM, JUST DO IT.
int main( int argc, char* args[] )
{
	//TEST FOR INIT
	if ( !init() ) 
	{ 
		printf( "Failed to initialize!\n" ); 
	} else {
		//OPEN JOYSTICK AND GET JOY NAME
			
		if( SDL_NumJoysticks() > 0 )
		{
			myJoy = SDL_JoystickOpen( 0 );  //IF YOU HAVE MORE THAN ONE DEVICE, CHANGE THIS DEVICE ID.
			joyName = SDL_JoystickName( myJoy );
		}

		//WINDOW CONFIG
		system( "color a" );
		system( "mode 30,14" );
		system( "title Dev2Mem" );


		//INFINITE LOOP ON CONSOLE, I LOVE INFINITE LOOPS.
		while ( true ) 
		{

			//REFRESH ALL DATA
			updateValues();

			//UPDATES INTERFACE
			std::cout << joyName.c_str() << "\t" << std::endl;		//DEVICE NAME
			std::cout << "Eje\tValor\tDireccion" << std::endl;		//TABLE HEADERS
			std::cout << "LX\t" << LX << "  \t" << &LX << std::endl;	//LEFT X AXIS
			std::cout << "LY\t" << LY << "  \t" << &LY << std::endl;	//LEFT Y AXIS
			std::cout << "RX\t" << RX << "  \t" << &RX << std::endl;	//RIGHT X AXIS ( SWAPED Y )
			std::cout << "RY\t" << RY << "  \t" << &RY << std::endl;	//RIGHT Y AXIS ( SWAPED X )
			std::cout << "B1\t" << b1 << "  \t" << &b1 << std::endl;	//BUTTON 1
			std::cout << "B2\t" << b2 << "  \t" << &b2 << std::endl;	//BUTTON 2
			std::cout << "B3\t" << b3 << "  \t" << &b3 << std::endl;	//BUTTON 3
			std::cout << "B4\t" << b4 << "  \t" << &b4 << std::endl;	//BUTTON 4

			curX = p.x; curY = p.y;
			std::cout << "mouseX\t" << curX << "   \t" << &curX << std::endl;	//MOUSE X POSITION
			std::cout << "mouseY\t" << curY << "   \t" << &curY << std::endl;	//MOUSE Y POSITION

			std::cout << "-> luis1337@outlook.es <-";				//MY MAIL, FOR YOU

			//ClearScreen();
			COORD xy; xy.X = 0; xy.Y = 0;						//SETS A COORD TO ( 0, 0 )
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );//SETS CONSOLE CURSOR TO ( 0, 0 )

		}
	}
	close(); //HAHAHA, DO YOU THINK THIS IS GOING TO BE EXECUTED?

	return 0;
}

//DEFAULT SDL INIT, I´M TO LAZY TO DO THIS
bool init()
{
	bool success = true;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		//CREATE A WINDOW THAT HANDLES THE JOY (AND HIDES IT)
		gWindow = SDL_CreateWindow( "Joy Handler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		//TRYING TO NOT SHOW THE WINDOW WITHOUT USING SDL_HideWindow()
		SDL_SetWindowPosition( gWindow, 0, 0 );
		SDL_SetWindowBordered( gWindow, SDL_FALSE );
		SDL_SetWindowOpacity( gWindow, 0.0f );
		SDL_SetWindowPosition( gWindow, -20, -20 );
		SDL_SetWindowSize( gWindow, 0, 0 );

		if ( gWindow == NULL )
		{
			printf( "No se puede crear la ventana. Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
			SDL_GameControllerUpdate;
			SDL_JoystickUpdate;

			//INIT THE JOYSTICK
			if ( SDL_Init( SDL_INIT_JOYSTICK ) < 0 ) 
			{
				//ERROR HANDLING
				SDL_ShowSimpleMessageBox(
					SDL_MESSAGEBOX_ERROR,
					"Joystick",
					"No se ha podido iniciar la compatibilidad con Joysticks",
					NULL
				);
			} else {

				SDL_JoystickUpdate();
				//CHECK NUMBER OF CONTROLLERS
				if ( SDL_NumJoysticks <= 0 ) 
				{
					SDL_ShowSimpleMessageBox(
						SDL_MESSAGEBOX_ERROR,
						"Dispositivo",
						"No se encuentran Joysticks conectados",
						NULL
					);
				}

			}
		}
	}
	return success;
}

//DEFAULT SDL CLOSE, IS NOT USED BUT I DO WHAT I WANT
void close()
{
	system( "pause" );
	SDL_FreeSurface( gSurface );
	gSurface = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}

//THIS FUNCTION UPDATES THE VALUES OF ALL VARIABLES
static void updateValues() 
{

	//UPDATE CURSOR POSITION ON GLOBAL SCREEN.
	GetCursorPos( &p );

	
	//UPDATES JOYSTICK OR GAMECONTROLLER STATUS
	SDL_JoystickUpdate();
	SDL_GameControllerUpdate();

	//UPDATE AND RECALCULATE VARIABLES (IF YOU WANT VALUES FROM NEGATIVE TO POSITIVE DELETE "+ 32768" AT THE END) 
	LX = SDL_JoystickGetAxis( myJoy, SDL_CONTROLLER_AXIS_LEFTX  ) + 32768; //LEFT X AXIS
	LY = SDL_JoystickGetAxis( myJoy, SDL_CONTROLLER_AXIS_LEFTY  ) + 32768; //LEFT Y AXIS

	//SWAPED X TO Y AND Y TO X, YOU CAN CHANGE THIS AT YOUR OWN
	RX = SDL_JoystickGetAxis( myJoy, SDL_CONTROLLER_AXIS_RIGHTY ) + 32768; // RIGHT X AXIS
	RY = SDL_JoystickGetAxis( myJoy, SDL_CONTROLLER_AXIS_RIGHTX ) + 32768; //RIGHT Y AXIS

	//4 BUTTONS FOR MY CONTROLLER, YOU CAN ADD MORE IF YOU WANT. IF YOU DONT KNOW HOW TO DO THAT, SEND ME AN EMAIL
	b1 = SDL_JoystickGetButton( myJoy, 0 ); //BUTTON 1
	b2 = SDL_JoystickGetButton( myJoy, 1 ); //BUTTON 2
	b3 = SDL_JoystickGetButton( myJoy, 2 ); //BUTTON 3
	b4 = SDL_JoystickGetButton( myJoy, 3 ); //BUTTON 4
	

}
