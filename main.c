#include <gb/gb.h>
#include <stdint.h>

#include "logomap.h"
#include "beanlogo.h"
#include "DialogueChr.h"
#include "dialoguemap.h"
#include "demoscreen.h"
#include "Pizzi.h"
#include "Danny.h"
#include "ProfileChr.h"

uint8_t COLOR_FLAG = 16; //00010000
uint8_t FLIP_COLOR_FLAG = 48; //00110000

uint8_t joy;
uint8_t ind_x;
uint8_t ind_y;
uint8_t ind;

void load_profile(uint8_t ProfMap[], uint8_t ProfAtr[])
{
	ind = 0;
	for (ind_y = 0; ind_y < 5; ++ind_y)
	{
		for (ind_x = 0; ind_x < 5; ++ind_x)
		{
			set_sprite_tile(ind,ProfMap[ind]);
			move_sprite(ind,16+(8*ind_x),24+(8*ind_y));
			set_sprite_prop(ind,ProfAtr[ind]);
			ind++;
		}
	}
}








void main(void)
{
	//set_bkg_data(0, 127, beanlogo);
	//set_bkg_tiles(0,0,logomapWidth,logomapHeight,logomap);
	set_bkg_data(0, 127, DialogueChr);
	set_bkg_tiles(0,0,demoscreenWidth,demoscreenHeight,demoscreen);
	//set_bkg_data(0, 48, DialogueChr);
	//set_bkg_tiles(0,0,dialoguemapWidth,7,dialoguemap);
	set_sprite_data(0, 127, ProfileChr);
	//load_profile(PizziMap, PizziAtr);
	//load_profile(DannyMap, DannyAtr);
	SHOW_BKG;
	//SHOW_WIN;
	SHOW_SPRITES;
    DISPLAY_ON;
    // Loop forever
    while(1) {
		joy = joypad();
		if (joy & J_B) {
			load_profile(PizziMap, PizziAtr);
		}
		if (joy & J_A) {
			load_profile(DannyMap, DannyAtr);
		}
		// Game main loop processing goes here


		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}