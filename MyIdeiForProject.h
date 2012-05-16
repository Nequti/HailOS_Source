#include "Memory.h"
#include "Proc.h"

/*это вариант , если ось написана на C, а интерфейс пользователю будет предоставлен на C++*/
int main()
{
	CProc* pProc = GetMemory( sizeof( CProc ) );
	IGraphics<int>* graph = pProc->GetPlace();/*делаем, так, что процесс будет выполнять нашу графику в приложении*/
	IInput* input = GetKeyboardState( ALL_KEY ); /*клавиатура*/
	
	if( pProc == 0 )
	{
		return 1;
	}
	
	pProc->CreateProc( );
	pProc->LifeInterval = 0.94;/*время , через которое процесс повторяется*/
	
	while( pProc->State != KILL_PROC/*0*/ )
	{
		pProc->RemoveMemory( ); /*если не хватает памяти, выделяем ещё, для всех объектов процесса*/
		pProc->Life( );/*запуск*/
		graph->Point( 100, 100, graph->Colour<float>( 1.0, 1.0, 1.0 ), graph->Size<int>( 10 ) );
		graph->Line( graph->Point<int>( 200, 200 )/*перегруженная функция*/, graph->Point<int>( 300, 300 ), graph->Colour<int>( 255, 255, 255 ), graph->Size<int>( 10 ) );
		if( input->Key == 27 )
		{
			pProc->State = KILL_PROC;
		}
	}
	pProc->KillProg();/*со спокойной душой выходим из программы, если State == KILL_PROC*/
}