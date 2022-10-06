#include "T1.h"

int fork_start_x_pos=120;
int fork_start_y_pos=40;
int current_fork_x=0;
int current_fork_y=0;
int fork_size=5;
int fork_stop=20;

void alarm_icon(int start_point_x, int start_point_y)
{    
    plot1(start_point_x, start_point_y-4);
    plot1(start_point_x, start_point_y-3);
    plot1(start_point_x, start_point_y-2);
    plot1(start_point_x, start_point_y-1);
    plot1(start_point_x, start_point_y);
    plot1(start_point_x, start_point_y+2);
    plot1(start_point_x, start_point_y+3);
}

void draw_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        for (j = start_point_y; j < end_point_y; j++ )
        {
            plot1(i, j);
        }
    }
}

void draw_empty_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        if(i==start_point_x || i==end_point_x-1)
        {
            for (j = start_point_y; j < end_point_y; j++ )
            {
                plot1(i, j);
            }
        }
        else
        {
            plot1(i, start_point_y);
            plot1(i, end_point_y);
        }
    }
}

void clear_box(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
    int i=0;
    int j=0;
    
    for (i = start_point_x; i < end_point_x; i++ )
    {
        for (j = start_point_y; j < end_point_y; j++ )
        {
            plot0(i, j);
        }
    }
}

void initial_draw()
{
    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
    //Fork
    draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
    current_fork_x=fork_start_x_pos;
    current_fork_y=fork_start_y_pos;
    draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);

    //Icons
    alarm_icon(200, 20);
}

void tache1()
{
    unsigned char i;

    di();
    initialisation_des_ports();
    initialisation_afficheur();
    clear_text();
    clear_graphics();
    init_rxtx();
    Init(SEM_RXTX);
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;

    vitesse=0;
    batterie=120;
    n_octet_badge=0;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
    //Fork
    draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
    current_fork_x=fork_start_x_pos;
    current_fork_y=fork_start_y_pos;
    draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);

    //Icons
    alarm_icon(200, 20);
            
    TP_appui=0;
    alarme_pannel=0;
            
    while(1)
    {
        
        goto_lico(0,0);
        draw_string("Marche:");
        if (MARCHE_AVANT==0)
            draw_string("AV");
        else
            if (MARCHE_ARRIERE==0)
                draw_string("AR");
            else
                draw_string("N ");

        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==0)
        {draw_char('1');}
        else
        {draw_char('0');}

        goto_lico(2,0);
        draw_string("Temp. Eau:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_EAU));

        goto_lico(3,0);
        draw_string("Temp. Huile:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_HUILE));

        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0)
            draw_char('1');
        else
            draw_char('0');

        goto_lico(5,0);
        draw_string("Vitesse:");
        if (VITESSE_PLUS==0)
            vitesse++;
        if (VITESSE_MOINS==0)
            vitesse--;
        draw_hex8(vitesse);

        goto_lico(6,0);
        draw_string("Batterie:");
        if (BATTERIE_PLUS==0)
            batterie++;
        if (BATTERIE_MOINS==0)
            batterie--;
        draw_hex8(batterie);

        goto_lico(7,0);
        if (FREIN_A_MAIN==0)
            draw_string("((!))");
        else
            draw_string("     ");

        goto_lico(8,0);
        draw_string("Badge:");
        if (n_octet_badge==0)
            draw_string(" AUCUN              ");
        else
        {
            for (i=0;i<n_octet_badge;i++)
            {
                draw_hex8(badge[i]);
            }
        }

        goto_lico(9,0);
        draw_string("X-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_X));

        goto_lico(10,0);
        draw_string("Y-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

        if (TP_appui==1)
        {
            goto_lico(0,20);
            draw_string("x=");
            draw_hex8(TP_x);
            draw_string(" y=");
            draw_hex8(TP_y);
            plot1(TP_x,TP_y);
        }
        else
        {
            Nop();
        }
        
        
        //draw_box(100, 100, 110, 110);
        //draw_line_x(120, 120, 140);
        //draw_line_y(140, 140, 160);
        //draw_fork(120, 40);
        
        //Fork
        if (lecture_8bit_analogique(JOYSTICK_X) == 0xFF && (current_fork_x+1)<(fork_start_x_pos+fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x+1, current_fork_y, current_fork_x+fork_size+1, current_fork_y+fork_size);
            current_fork_x=current_fork_x+1;
        }
        if (lecture_8bit_analogique(JOYSTICK_X) == 0x00 && (current_fork_x-1)>(fork_start_x_pos-fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x-1, current_fork_y, current_fork_x+fork_size-1, current_fork_y+fork_size);
            current_fork_x=current_fork_x-1;
        }
        if (lecture_8bit_analogique(JOYSTICK_Y) == 0x00 && (current_fork_y+1)<(fork_start_y_pos+fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+10, current_fork_y+fork_size);
            draw_box(current_fork_x, current_fork_y+1, current_fork_x+fork_size, current_fork_y+fork_size+1);
            current_fork_y=current_fork_y+1;
        }
       if (lecture_8bit_analogique(JOYSTICK_Y) == 0xFF && (current_fork_y-1)>(fork_start_y_pos-fork_stop))
        {
            clear_box(current_fork_x, current_fork_y, current_fork_x+fork_size, current_fork_y+fork_size);
            draw_box(current_fork_x, current_fork_y-1, current_fork_x+fork_size, current_fork_y+fork_size-1);
            current_fork_y=current_fork_y-1;
        }
        
        goto_lico(11,0);
        draw_string("pannel=");
        draw_hex8(alarme_pannel);
        if(alarme_pannel==0xFF)
        {
            clear_text();
            clear_graphics();
            while (alarme_pannel==0xFF)
            {
                //Alarme
                alarm_icon(200, 20);
                goto_lico(11,0);
                draw_string("alarme_eau=");
                draw_hex8((alarme_active >> 0) & 0x01);
                goto_lico(12,0);
                draw_string("alarme_huile=");
                draw_hex8((alarme_active >> 1) & 0x01);
                goto_lico(13,0);
                draw_string("alarme_choc=");
                draw_hex8((alarme_active >> 2) & 0x01);
                goto_lico(14,0);
                draw_string("alarme_batterie=");
                draw_hex8((alarme_active >> 3) & 0x01);
                goto_lico(11,20);
                draw_string("alarme_cle=");
                draw_hex8((alarme_active >> 4) & 0x01);
                goto_lico(12,20);
                draw_string("alarme_frein=");
                draw_hex8((alarme_active >> 5) & 0x01);
                goto_lico(13,20);
                draw_string("alarme_siege=");
                draw_hex8((alarme_active >> 6) & 0x01);
                goto_lico(14,20);
                draw_string("erreur_choc=");
                draw_hex8((error_active >> 2) & 0x01);
                goto_lico(15,20);
                draw_string("choc_time=");
                draw_hex8(choc_time_1);
                draw_hex8(choc_time_2);
                draw_hex8(choc_time_3);
                draw_hex8(choc_time_4);
            }
            clear_text();
            clear_graphics();
            goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
            goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
            goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    
            //Fork
            draw_box(fork_start_x_pos, fork_start_y_pos, fork_start_x_pos+fork_size, fork_start_y_pos+fork_size);
            current_fork_x=fork_start_x_pos;
            current_fork_y=fork_start_y_pos;
            draw_empty_box(fork_start_x_pos-fork_stop-1, fork_start_y_pos-fork_stop-1, fork_start_x_pos+fork_size+fork_stop+1, fork_start_y_pos+fork_size+fork_stop+1);

            //Icons
            alarm_icon(200, 20);
        }
                
    }
}