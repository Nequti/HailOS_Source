/*Представление участника Nequti, о том , как должен будет выглядеть, API работа с процессами, памятью + окнами и IO*/

/****************************************************************/
#include "Memory.h"
#include "Proc.h"
#include "Window.h"
#include "Graphics.h"
#include "Input.h"
/***************************************************************/

/*это вариант , если ось написана на C, а интерфейс пользователю будет предоставлен на C++*/
int main()
{
	/*инициализация*/
	IProc* pProc = GetMemory( sizeof( CProc ) );
	IWindow win = pProc->GetWindowPlace( 800, 600, 32, "Test program for my OS" );
	IGraphics* graph = pProc->GetPlace( );/*делаем, так, что процесс будет выполнять нашу графику в приложении*/
	IInput* input = GetKeyboardState( ALL_KEY ); /*клавиатура*/
	graph->OpenGraphicDevice( graph->SMOOTH, graph->RGB, graph->VersionGraph, graph->Buffer = COLOUR_BUF | Z_BUF );
	
	win->ButtonOff( );/*выключаем крестики и прочие кнопки на окне*/
	
	if( pProc == 0 )/*процесс был создан?*/
	{
		return 1;
	}
	
	pProc->CreateProc( );
	pProc->LifeInterval = 0.94;/*время , через которое процесс повторяется*/
	
	while( pProc->State != KILL_PROC/*0*/ )
	{
		graph->ClearBuffers( );
		
		if( pProc->Error == NONE_MEMORY )
		{
			pProc->RemoveMemory( ); /*если не хватает памяти, выделяем ещё, для всех объектов процесса*/
		}
		
		win->Draw( );
		pProc->Life( );/*запуск*/
		graph->Point( 100, 100, graph->Colour<float>( 1.0, 1.0, 1.0 ), graph->Size<int>( 10 ) );
		graph->Line( graph->Point<int>( 200, 200 )/*перегруженная функция*/, graph->Point<int>( 300, 300 ), graph->Colour<int>( 255, 255, 255 ), graph->Size<int>( 10 ) );
		if( input->Key == 27 )
		{
			pProc->State = KILL_PROC;
		}
	}
	
	win->Close();/*закрываем окно*/
	graph->CloseDevice();/*закрываем все устройства*/
	pProc->KillProg();/*со спокойной душой выходим из программы, если State == KILL_PROC*/
	
}