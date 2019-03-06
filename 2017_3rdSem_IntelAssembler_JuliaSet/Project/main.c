#include <allegro.h>
#include "assembler.h"
#include <stdio.h>

int mx = 0, my = 0, mb = 0;
void myszka()
{
    if( mx != mouse_x || my != mouse_y || mb != mouse_b )
    {
        mx = mouse_x;
        my = mouse_y;
        mb = mouse_b;
    }
};

int main()
{	
	int S=800;
	int W=800;
	int maxIter = 250;	
	
	float real_c;
	float imag_c;

	/*printf("Podaj czesc rzeczywista wspolrzednej c.\n");
	scanf("%f",&real_c);
	printf("Podaj czesc urojona wspolrzednej c.\n");
	scanf("%f",&imag_c);*/
	
	
	real_c = -0.390541;
	imag_c = -0.586788;
	
	allegro_init();
	install_keyboard();
	set_color_depth( 24 );
	set_gfx_mode( GFX_AUTODETECT_WINDOWED, S, W, 0, 0 );
	install_mouse();
	show_mouse( screen );
	unscare_mouse();

	BITMAP * bufor = NULL;
	bufor = create_bitmap_ex(24, S, W);
	//clear_to_color( bufor, makecol( 100, 100, 100 ) );
	clear_to_color(bufor,makecol(0,0,0));
	blit(bufor, screen, 0, 0, 0, 0, S, W);
    
	float mid_x = 0.0;
	float mid_y = 0.0;
	float zoom = 1.0;
	float zoom_change = 0.15;	
	float coordinate_system_change = 10.0 ;
	
	julia(bufor->line,bufor->h,bufor->w, maxIter,real_c,imag_c,mid_x,mid_y,zoom);
	blit( bufor, screen, 0, 0, 0, 0, S, W );
	
	//while(mouse_b != 1)
	//{}
		
	while( !key[ KEY_ESC ] )
	{
        
        	//myszka();
		//julia(bufor->line,a,c);
		//if(a<S && b<W)
		//{	
		//while(mouse_b != 1)
		//{}

		
		
		if(key[KEY_UP])
		{
			mid_y -= coordinate_system_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		if(key[KEY_DOWN])
		{
			mid_y += coordinate_system_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		if(key[KEY_LEFT])
		{
			mid_x += coordinate_system_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		if(key[KEY_RIGHT])
		{
			mid_x -= coordinate_system_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		
		if(key[KEY_Z])
		{
			zoom -= zoom_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		if(key[KEY_X])
		{
			zoom += zoom_change;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}

		if(key[KEY_R])
		{
			mid_y = 0.0;			
			mid_x = 0.0;			
			zoom = 1.0;
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}
		/*if(key[KEY_C])
		{
			printf("Podaj czesc rzeczywista wspolrzednej c.\n");
			scanf("%f",&real_c);
			printf("Podaj czesc urojona wspolrzednej c.\n");
			scanf("%f",&imag_c);
			julia(bufor->line,bufor->h,bufor->w, maxIter, real_c,imag_c,mid_x,mid_y,zoom);
		}*/
	
		//	++a;
		//	++b;
	
		//}
		
		//if(mouse_b == 1)
		//	break;
	//printf("%d %d %d\n",a,b,c);

	//julia(bufor->line, mouse_x, mouse_y);
	
        //textprintf_ex( bufor, font, 20, 20, makecol( 200, 200, 200 ), - 1, "Myszka x = %d, y = %d, klawisz = %d !", mx, my, mb );
        
	

		blit( bufor, screen, 0, 0, 0, 0, S, W );

        	//clear_keybuf();
	}
	   
	destroy_bitmap( bufor );
	allegro_exit();
	return 0;
}
END_OF_MAIN();

/*while(mouse_b!=1)	
	{}
	a=mouse_x;
	b=mouse_y;
	mouse_b=0;*/
